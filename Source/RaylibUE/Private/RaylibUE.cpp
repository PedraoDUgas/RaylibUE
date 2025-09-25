#include "RaylibUE.h"
#include <GameFramework/GameModeBase.h>
#include <Kismet/GameplayStatics.h>
#include "Framework/Application/SlateApplication.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "Slate/SceneViewport.h"
#include "Widgets/SViewport.h"
#include "Widgets/SWindow.h"
#include "Widgets/SWidget.h"
#include "Input/Reply.h"
#include "Input/Events.h"

// WinAPI
extern "C" {
  __declspec(dllimport) long __stdcall GetWindowLongA(void* hWnd, int nIndex);
  __declspec(dllimport) long __stdcall SetWindowLongA(void* hWnd, int nIndex, long dwNewLong);
  __declspec(dllimport) bool __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags);
  __declspec(dllimport) LONG_PTR __stdcall SetWindowLongPtrA(void* hWnd, int nIndex, LONG_PTR dwNewLong);
  __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow);
}

#define GWL_EXSTYLE -20
#define GWLP_HWNDPARENT -8
#define HWND_TOPMOST ((void*)-1)
#define SW_HIDE 0
#define SW_SHOW 5
#define SWP_NOZORDER  0x0004
#define SWP_NOACTIVATE 0x0010
#define WS_EX_LAYERED 0x80000
#define WS_EX_TRANSPARENT 0x20
#define WS_EX_TOOLWINDOW 0x80

DEFINE_LOG_CATEGORY(LogRaylibUE);
#define LOCTEXT_NAMESPACE "FRaylibUEModule"

// Raylib API
extern "C" void* GetWindowHandle(void);

FRlDrawCommandBuffer FRaylibUEModule::rlDrawCommandsBuffer;

void FRaylibUEModule::StartupModule() {
  hOnGameModeInitialized = FDelegateHandle();
  hOnViewportResized = FDelegateHandle();
  hOnEndDraw = FDelegateHandle();

  hOnGameModeInitialized = FGameModeEvents::OnGameModeInitializedEvent().AddRaw(this, &FRaylibUEModule::OnGameModeInitialized);

  if (GEngine && GEngine->GetWorldContexts().Num() != 0) {
    for (const FWorldContext& Context : GEngine->GetWorldContexts()) {
      if (Context.World() && Context.World()->IsGameWorld()) {
        OnGameModeInitialized(UGameplayStatics::GetGameMode(Context.World()));
      }
    }
  }
}

void FRaylibUEModule::OnGameModeInitialized(AGameModeBase* aGameMode) {
  UE_LOG(LogRaylibUE, Log, TEXT("OnGameModeInitialized."));

  // Sync UE main objects
  GameMode = aGameMode;
  GameViewport = GameMode->GetWorld()->GetGameViewport();

  // Cleanup delegates if PIE or second window.
  RemoveDelegates();

  // Sync UE game window events
  hOnViewportResized = GameViewport->Viewport->ViewportResizedEvent.AddRaw(this, &FRaylibUEModule::OnViewportResized);
  hOnViewportClose = GameViewport->OnCloseRequested().AddRaw(this, &FRaylibUEModule::OnViewportClose);

  TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
  GameWindow->SetOnWindowMoved(FOnWindowMoved::CreateRaw(this, &FRaylibUEModule::OnGameWindowMoved));
  PrevWindowPos = GameWindow->GetPositionInScreen();
}

void FRaylibUEModule::InitRaylibOverlay() {
  GetGameWindowPosition();

  // FLAG_WINDOW_HIDDEN 
  SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TRANSPARENT);
  InitWindow(rlWindowSize.X, rlWindowSize.Y, "RaylibUE overlay");
  SetWindowPosition(ueWindowPosition.X, ueWindowPosition.Y);
  SetTargetFPS(60);
  //rlRenderTarget = LoadRenderTexture(rlWindowSize.X, rlWindowSize.Y);

  // WinAPI
  hwndRaylib = (HWND)GetWindowHandle();
  hwndUE = GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();

  LONG exStyle = GetWindowLongA(hwndRaylib, GWL_EXSTYLE);
  SetWindowLongA(hwndRaylib, GWL_EXSTYLE, exStyle | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
  SetWindowPos(hwndRaylib, HWND_TOPMOST, ueWindowPosition.X, ueWindowPosition.Y, (int)rlWindowSize.X, (int)rlWindowSize.Y, SWP_NOZORDER | SWP_NOACTIVATE);
  SetWindowLongPtrA(hwndRaylib, GWLP_HWNDPARENT, (LONG_PTR)hwndUE);
  
  GameViewport->GetWindow()->GetNativeWindow()->SetWindowFocus();
}

void FRaylibUEModule::SetRaylibWindowState(ERlWindowState WindowState) {
  // UE_LOG(LogRaylibUE, Log, TEXT("State: %d"), static_cast<int32>(WindowState));
  switch (WindowState) {
    case ERlWindowState::None:
      break;
    case ERlWindowState::Init:
      FRaylibUEModule::InitRaylibOverlay();
      hOnEndDraw = GameViewport.Get()->OnEndDraw().AddRaw(this, &FRaylibUEModule::OnEndDraw);
      break;
    case ERlWindowState::Hide:
      if (hwndRaylib) { ShowWindow(hwndRaylib, SW_HIDE); }
      break;
    case ERlWindowState::Show:
      if (hwndRaylib) { ShowWindow(hwndRaylib, SW_SHOW); }
      break;
    case ERlWindowState::OnDrag:
      SetRaylibWindowState(ERlWindowState::Hide);
      break;
    case ERlWindowState::OnDrop:
      SetRaylibWindowState(ERlWindowState::Position);
      SetRaylibWindowState(ERlWindowState::Show);
      break;
    case ERlWindowState::Position:
      GetGameWindowPosition();
      SetWindowPos(hwndRaylib, HWND_TOPMOST, ueWindowPosition.X, ueWindowPosition.Y, (int)rlWindowSize.X, (int)rlWindowSize.Y, SWP_NOZORDER | SWP_NOACTIVATE);
      break;
    case ERlWindowState::Resize:
      if (RaylibWindowState == ERlWindowState::None) {
        SetRaylibWindowState(ERlWindowState::Init);
        bIsWindowOpen = true;
      }
      if (bIsWindowOpen) {
        FVector2D vwSize;
        GameViewport.Get()->GetViewportSize(vwSize);
        ViewportSize.X = (int32)vwSize.X; ViewportSize.Y = (int32)vwSize.Y;
        SetWindowSize(ViewportSize.X, ViewportSize.Y);

        if (GameViewport->GetWindow()->IsWindowMinimized()) {
          SetRaylibWindowState(ERlWindowState::Hide);
        }
        SetRaylibWindowState(ERlWindowState::Position);
        UnloadRenderTexture(rlRenderTarget);
        rlRenderTarget = LoadRenderTexture(ViewportSize.X, ViewportSize.Y);
      }
      break;
    case ERlWindowState::Close:
      RemoveDelegates();
      return;
    default:
      break;
  }
  RaylibWindowState = ERlWindowState::Idle;
}

void FRaylibUEModule::RemoveDelegates() {
  if (bIsWindowOpen) {
    CloseWindow();
    UnloadRenderTexture(rlRenderTarget);
    rlDrawCommandsBuffer.Clear();
    RaylibWindowState = ERlWindowState::None;
  }

  if (hOnEndDraw.IsValid()) {
    GameViewport.Get()->OnEndDraw().Remove(hOnEndDraw);
    hOnEndDraw.Reset();
  }

  if (hOnGameWindowMoved.IsValid()) {
    TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
    if (GameWindow.IsValid()) {
      GameWindow->SetOnWindowMoved(FOnWindowMoved());
    }
    hOnGameWindowMoved.Reset();
  }
  if (hOnViewportClose.IsValid()) {
    GameViewport->OnCloseRequested().Remove(hOnViewportClose);
    hOnViewportClose.Reset();
  }

  if (hOnViewportResized.IsValid()) {
    GameViewport->Viewport->ViewportResizedEvent.Remove(hOnViewportResized);
  }
  bIsWindowOpen = false;
}

// Window Events
void FRaylibUEModule::OnEndDraw() { FRaylibUEModule::RenderRaylibOverlay(); /* at RaylibUE_Render.cpp*/ }

void FRaylibUEModule::OnViewportResized(FViewport* Viewport, uint32 /*Unused*/) { SetRaylibWindowState(ERlWindowState::Resize); }

void FRaylibUEModule::OnViewportClose(FViewport* Viewport) { SetRaylibWindowState(ERlWindowState::Close); }

void FRaylibUEModule::OnGameWindowMoved(const TSharedRef<SWindow>& Window) {
  TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
  if (GameWindow.IsValid() && !GameWindow->IsWindowMaximized()) {
    FVector2D CurrPos = GameWindow->GetPositionInScreen();
    float PosDelta = FVector2D::Distance(CurrPos, PrevWindowPos);
    if (PosDelta > DragDeltaThreshold && !bWasDragging) {
      bWasDragging = true;
      SetRaylibWindowState(ERlWindowState::OnDrag);
      FTimerDelegate DragEndDel = FTimerDelegate::CreateRaw(this, &FRaylibUEModule::CheckGameWindowMovedEnd);
      GameMode->GetWorld()->GetTimerManager().SetTimer(hDragEndTimer, DragEndDel, DragEndThreshold, false);
    }
    FRaylibUEModule::PrevWindowPos = CurrPos;
  }
}

void FRaylibUEModule::CheckGameWindowMovedEnd() {
  if (bWasDragging) {
    bWasDragging = false;
    SetRaylibWindowState(ERlWindowState::OnDrop);
    GameMode->GetWorld()->GetTimerManager().ClearTimer(hDragEndTimer);
  }
}

void FRaylibUEModule::Tick(float DeltaTime) {
  TSharedPtr<SWindow> GameWindow = GEngine->GameViewport->GetWindow();
  if (GameWindow.IsValid()) {
    FVector2D CurrPos = GameWindow->GetPositionInScreen();
    if (FVector2D::Distance(CurrPos, PrevWindowPos) < 1.f) {
      CheckGameWindowMovedEnd();
    } else {
      PrevWindowPos = CurrPos;
    }
  }
}

void FRaylibUEModule::GetGameWindowPosition() {
  TSharedPtr<SViewport> ViewportWidget = GEngine->GameViewport->GetGameViewportWidget();
  FGeometry Geo = ViewportWidget->GetTickSpaceGeometry();
  FVector2D vwPos = Geo.GetAbsolutePosition();
  FVector2D vwSize = Geo.GetLocalSize();
  float vwDPIScale = GameViewport.Get()->GetDPIScale();
  rlWindowSize.X = (float)vwSize.X * vwDPIScale;
  rlWindowSize.Y = (float)vwSize.Y * vwDPIScale;
  ueWindowPosition = FIntPoint((int32)vwPos.X, (int32)vwPos.Y);
}

void FRaylibUEModule::ShutdownModule() {
  if (hOnGameModeInitialized.IsValid()) {
    FGameModeEvents::OnGameModeInitializedEvent().Remove(hOnGameModeInitialized);
    hOnGameModeInitialized.Reset();
  }
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FRaylibUEModule, RaylibUE)