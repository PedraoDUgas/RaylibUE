#pragma once

#include "CoreMinimal.h" 
#include "Engine/Engine.h"
#include "Modules/ModuleManager.h"
#include "RaylibUE_DrawCommands.h"

#define RLGL_IMPLEMENTATION
#include "raylib.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRaylibUE, Log, All);

class FRaylibUEModule : public IModuleInterface {
public:
  static FRaylibUEModule& Get() {
    return FModuleManager::LoadModuleChecked<FRaylibUEModule>("RaylibUE");
  }
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

  UPROPERTY(BlueprintReadWrite, Category="Raylib")
  static FRlDrawCommandBuffer rlDrawCommandsBuffer;

protected:
  // UE context
  TWeakObjectPtr<AGameModeBase> GameMode;
  TWeakObjectPtr<UGameViewportClient> GameViewport;
  FIntPoint ViewportSize;
  FVector2f rlWindowSize;
  FIntPoint ueWindowPosition;

  // Events
  FDelegateHandle hOnGameModeInitialized;
  void OnGameModeInitialized(AGameModeBase* GameMode);

  FDelegateHandle hOnEndDraw;
  void OnEndDraw();

  FDelegateHandle hOnViewportResized;
  void OnViewportResized(FViewport* Viewport, uint32 /*Unused*/);

  FDelegateHandle hOnViewportClose;
  void OnViewportClose(FViewport* Viewport);

  FDelegateHandle hOnGameWindowMoved;
  void OnGameWindowMoved(const TSharedRef<SWindow>& Window);

private:
  void InitRaylibOverlay();
  void RenderRaylibOverlay();
  ::RenderTexture2D rlRenderTarget;
  bool bIsWindowOpen = false;

  void GetGameWindowPosition();

   enum ERlWindowState {
    None,
    Init,
    Idle,
    Hide,
    Show,
    OnDrag,
    OnDrop,
    Position,
    Resize,
    Close,
  };

  void SetRaylibWindowState(ERlWindowState WindowState);
  ERlWindowState RaylibWindowState = ERlWindowState::None;

  void RemoveDelegates();

  // WinAPI
  using HWND = void*;
  HWND hwndRaylib;
  HWND hwndUE;

  // The pain of the lack of window move events...
  FVector2D PrevWindowPos;
  bool bWasDragging = false;
  float DragEndTimer = 0.f;
  const float DragDeltaThreshold = 2.f;  // Pixels to detect move
  const float DragEndThreshold = 0.05f;  // Seconds of no move to end drag
  FTimerHandle hDragEndTimer;
  void CheckGameWindowMovedEnd();
  void Tick(float DeltaTime);

};
