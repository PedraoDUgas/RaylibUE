#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "raylib.h"
#include "RaylibUE_DrawCommands.h"
#include "RaylibUEBPLibrary.generated.h"

// DrawPixel
USTRUCT(BlueprintType)
struct FRlDrawPixel {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawPixelV
USTRUCT(BlueprintType)
struct FRlDrawPixelV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLine
USTRUCT(BlueprintType)
struct FRlDrawLine {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 StartPosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 StartPosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 EndPosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 EndPosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineV
USTRUCT(BlueprintType)
struct FRlDrawLineV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineEx
USTRUCT(BlueprintType)
struct FRlDrawLineEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineBezier
USTRUCT(BlueprintType)
struct FRlDrawLineBezier {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineBezierQuad
USTRUCT(BlueprintType)
struct FRlDrawLineBezierQuad {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint ControlPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineBezierCubic
USTRUCT(BlueprintType)
struct FRlDrawLineBezierCubic {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartControlPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndControlPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLineStrip
USTRUCT(BlueprintType)
struct FRlDrawLineStrip {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FIntPoint> Points;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircle
USTRUCT(BlueprintType)
struct FRlDrawCircle {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CenterX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CenterY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircleSector
USTRUCT(BlueprintType)
struct FRlDrawCircleSector {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndAngle = 360.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircleSectorLines
USTRUCT(BlueprintType)
struct FRlDrawCircleSectorLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndAngle = 360.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircleGradient
USTRUCT(BlueprintType)
struct FRlDrawCircleGradient {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color1 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color2 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircleV
USTRUCT(BlueprintType)
struct FRlDrawCircleV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircleLines
USTRUCT(BlueprintType)
struct FRlDrawCircleLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawEllipse
USTRUCT(BlueprintType)
struct FRlDrawEllipse {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CenterX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CenterY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusH = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusV = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawEllipseLines
USTRUCT(BlueprintType)
struct FRlDrawEllipseLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusH = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusV = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRing
USTRUCT(BlueprintType)
struct FRlDrawRing {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float InnerRadius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float OuterRadius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndAngle = 360.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRingLines
USTRUCT(BlueprintType)
struct FRlDrawRingLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float InnerRadius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float OuterRadius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndAngle = 360.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRectangle
USTRUCT(BlueprintType)
struct FRlDrawRectangle {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Width = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Height = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRectangleV
USTRUCT(BlueprintType)
struct FRlDrawRectangleV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRectangleRec
USTRUCT(BlueprintType)
struct FRlDrawRectangleRec {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRectanglePro
USTRUCT(BlueprintType)
struct FRlDrawRectanglePro {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Origin = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleGradientV
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color1 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color2 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRectangleGradientH
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientH {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color1 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color2 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleGradientEx
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint TopLeft = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint TopRight = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint BottomRight = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint BottomLeft = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleLines
USTRUCT(BlueprintType)
struct FRlDrawRectangleLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 LineThick = 1;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleLinesEx
USTRUCT(BlueprintType)
struct FRlDrawRectangleLinesEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float LineThick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleRounded
USTRUCT(BlueprintType)
struct FRlDrawRectangleRounded {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Roundness = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawRectangleRoundedLines
USTRUCT(BlueprintType)
struct FRlDrawRectangleRoundedLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Roundness = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 LineThick = 1;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTriangle
USTRUCT(BlueprintType)
struct FRlDrawTriangle {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V1 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V2 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V3 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTriangleLines
USTRUCT(BlueprintType)
struct FRlDrawTriangleLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V1 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V2 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint V3 = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawPoly
USTRUCT(BlueprintType)
struct FRlDrawPoly {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Sides = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawPolyLines
USTRUCT(BlueprintType)
struct FRlDrawPolyLines {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Center = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Sides = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawPolyLinesEx
USTRUCT(BlueprintType)
struct FRlDrawPolyLinesEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FIntPoint> Points;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawFPS
USTRUCT(BlueprintType)
struct FRlDrawFPS {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawText
USTRUCT(BlueprintType)
struct FRlDrawText {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString Text = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 FontSize = 20;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTextEx
USTRUCT(BlueprintType)
struct FRlDrawTextEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString Text = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 FontSize = 20;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Spacing = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextPro
USTRUCT(BlueprintType)
struct FRlDrawTextPro {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString Text = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Origin = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float FontSize = 20.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Spacing = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextCodepoint
USTRUCT(BlueprintType)
struct FRlDrawTextCodepoint {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Codepoint = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 FontSize = 20;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextCodepoints
USTRUCT(BlueprintType)
struct FRlDrawTextCodepoints {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<int32> Codepoints;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 FontSize = 20;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Spacing = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawLine3D
USTRUCT(BlueprintType)
struct FRlDrawLine3D {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector StartPos = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector EndPos = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawPoint3D
USTRUCT(BlueprintType)
struct FRlDrawPoint3D {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCircle3D
USTRUCT(BlueprintType)
struct FRlDrawCircle3D {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Center = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RotationAxis = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RotationAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTriangle3D
USTRUCT(BlueprintType)
struct FRlDrawTriangle3D {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector V1 = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector V2 = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector V3 = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTriangleStrip3D
USTRUCT(BlueprintType)
struct FRlDrawTriangleStrip3D {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FVector> Points;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCube
USTRUCT(BlueprintType)
struct FRlDrawCube {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Width = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Height = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Length = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCubeV
USTRUCT(BlueprintType)
struct FRlDrawCubeV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Size = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCubeWires
USTRUCT(BlueprintType)
struct FRlDrawCubeWires {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Width = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Height = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Length = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCubeWiresV
USTRUCT(BlueprintType)
struct FRlDrawCubeWiresV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Size = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawSphere
USTRUCT(BlueprintType)
struct FRlDrawSphere {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Center = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawSphereEx
USTRUCT(BlueprintType)
struct FRlDrawSphereEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Center = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Rings = 16;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawSphereWires
USTRUCT(BlueprintType)
struct FRlDrawSphereWires {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Center = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Rings = 16;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCylinder
USTRUCT(BlueprintType)
struct FRlDrawCylinder {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusTop = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusBottom = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Height = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCylinderEx
USTRUCT(BlueprintType)
struct FRlDrawCylinderEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector StartVertex = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector EndVertex = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartRadius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndRadius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Sides = 8;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCylinderWires
USTRUCT(BlueprintType)
struct FRlDrawCylinderWires {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusTop = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RadiusBottom = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Height = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCylinderWiresEx
USTRUCT(BlueprintType)
struct FRlDrawCylinderWiresEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector StartVertex = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector EndVertex = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartRadius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndRadius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Sides = 8;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawCapsule
USTRUCT(BlueprintType)
struct FRlDrawCapsule {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Start = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector End = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Rings = 16;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawCapsuleWires
USTRUCT(BlueprintType)
struct FRlDrawCapsuleWires {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Start = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector End = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Rings = 16;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawPlane
USTRUCT(BlueprintType)
struct FRlDrawPlane {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector CenterPos = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Size = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawRay
USTRUCT(BlueprintType)
struct FRlDrawRay {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RayPos = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RayDir = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawGrid
USTRUCT(BlueprintType)
struct FRlDrawGrid {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 10;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Spacing = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawModel
USTRUCT(BlueprintType)
struct FRlDrawModel {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString ModelPath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawModelEx
USTRUCT(BlueprintType)
struct FRlDrawModelEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString ModelPath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RotationAxis = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RotationAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Scale = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawModelWires
USTRUCT(BlueprintType)
struct FRlDrawModelWires {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString ModelPath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor WireColor = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawModelWiresEx
USTRUCT(BlueprintType)
struct FRlDrawModelWiresEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString ModelPath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RotationAxis = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RotationAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Scale = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor WireColor = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawBoundingBox
USTRUCT(BlueprintType)
struct FRlDrawBoundingBox {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Min = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Max = FVector::OneVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawBillboard
USTRUCT(BlueprintType)
struct FRlDrawBillboard {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawBillboardRec
USTRUCT(BlueprintType)
struct FRlDrawBillboardRec {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourceRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawBillboardPro
USTRUCT(BlueprintType)
struct FRlDrawBillboardPro {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourceRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Up = FVector::UpVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Right = FVector::RightVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Forward = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTexture
USTRUCT(BlueprintType)
struct FRlDrawTexture {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosX = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 PosY = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextureV
USTRUCT(BlueprintType)
struct FRlDrawTextureV {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextureEx
USTRUCT(BlueprintType)
struct FRlDrawTextureEx {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Scale = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

  // DrawTextureRec
USTRUCT(BlueprintType)
struct FRlDrawTextureRec {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourceRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint DestRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTexturePro
USTRUCT(BlueprintType)
struct FRlDrawTexturePro {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourceRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint DestRec = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Origin = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};

// DrawTextureNPatch
USTRUCT(BlueprintType)
struct FRlDrawTextureNPatch {
  GENERATED_BODY()

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath = TEXT("");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FIntPoint> NPatchInfo;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Dest = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Tint = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 CommandID = -1;
};


UCLASS()
class URaylibUEBPLibrary : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Pixel Raylib"))
  static void DrawPixel(int32 PosX, int32 PosY, FLinearColor Color, int32& OutHandleID, FRlDrawPixel& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Pixel Raylib"))
  static void DrawPixelUpdate(int32 HandleID, const FRlDrawPixel& InShape, int32& OutHandleID, FRlDrawPixel& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Pixel V Raylib"))
  static void DrawPixelV(FIntPoint Position, FLinearColor Color, int32& OutHandleID, FRlDrawPixelV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Pixel V Raylib"))
  static void DrawPixelVUpdate(int32 HandleID, const FRlDrawPixelV& InShape, int32& OutHandleID, FRlDrawPixelV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Raylib"))
  static void DrawLine(int32 StartPosX, int32 StartPosY, int32 EndPosX, int32 EndPosY, FLinearColor Color, int32& OutHandleID, FRlDrawLine& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Raylib"))
  static void DrawLineUpdate(int32 HandleID, const FRlDrawLine& InShape, int32& OutHandleID, FRlDrawLine& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line V Raylib"))
  static void DrawLineV(FIntPoint StartPos, FIntPoint EndPos, FLinearColor Color, int32& OutHandleID, FRlDrawLineV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line V Raylib"))
  static void DrawLineVUpdate(int32 HandleID, const FRlDrawLineV& InShape, int32& OutHandleID, FRlDrawLineV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Ex Raylib"))
  static void DrawLineEx(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Ex Raylib"))
  static void DrawLineExUpdate(int32 HandleID, const FRlDrawLineEx& InShape, int32& OutHandleID, FRlDrawLineEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Raylib"))
  static void DrawLineBezier(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezier& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Raylib"))
  static void DrawLineBezierUpdate(int32 HandleID, const FRlDrawLineBezier& InShape, int32& OutHandleID, FRlDrawLineBezier& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Quad Raylib"))
  static void DrawLineBezierQuad(FIntPoint StartPos, FIntPoint EndPos, FIntPoint ControlPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezierQuad& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Quad Raylib"))
  static void DrawLineBezierQuadUpdate(int32 HandleID, const FRlDrawLineBezierQuad& InShape, int32& OutHandleID, FRlDrawLineBezierQuad& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Cubic Raylib"))
  static void DrawLineBezierCubic(FIntPoint StartPos, FIntPoint EndPos, FIntPoint StartControlPos, FIntPoint EndControlPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezierCubic& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Cubic Raylib"))
  static void DrawLineBezierCubicUpdate(int32 HandleID, const FRlDrawLineBezierCubic& InShape, int32& OutHandleID, FRlDrawLineBezierCubic& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Strip Raylib"))
  static void DrawLineStrip(const TArray<FIntPoint>& Points, FLinearColor Color, int32& OutHandleID, FRlDrawLineStrip& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Strip Raylib"))
  static void DrawLineStripUpdate(int32 HandleID, const FRlDrawLineStrip& InShape, int32& OutHandleID, FRlDrawLineStrip& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Raylib"))
  static void DrawCircle(int32 CenterX, int32 CenterY, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Raylib"))
  static void DrawCircleUpdate(int32 HandleID, const FRlDrawCircle& InShape, int32& OutHandleID, FRlDrawCircle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Sector Raylib"))
  static void DrawCircleSector(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawCircleSector& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Sector Raylib"))
  static void DrawCircleSectorUpdate(int32 HandleID, const FRlDrawCircleSector& InShape, int32& OutHandleID, FRlDrawCircleSector& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Sector Lines Raylib"))
  static void DrawCircleSectorLines(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawCircleSectorLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Sector Lines Raylib"))
  static void DrawCircleSectorLinesUpdate(int32 HandleID, const FRlDrawCircleSectorLines& InShape, int32& OutHandleID, FRlDrawCircleSectorLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Gradient Raylib"))
  static void DrawCircleGradient(FIntPoint Center, float Radius, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawCircleGradient& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Gradient Raylib"))
  static void DrawCircleGradientUpdate(int32 HandleID, const FRlDrawCircleGradient& InShape, int32& OutHandleID, FRlDrawCircleGradient& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle V Raylib"))
  static void DrawCircleV(FIntPoint Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircleV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle V Raylib"))
  static void DrawCircleVUpdate(int32 HandleID, const FRlDrawCircleV& InShape, int32& OutHandleID, FRlDrawCircleV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Lines Raylib"))
  static void DrawCircleLines(FIntPoint Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Lines Raylib"))
  static void DrawCircleLinesUpdate(int32 HandleID, const FRlDrawCircleLines& InShape, int32& OutHandleID, FRlDrawCircleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ellipse Raylib"))
  static void DrawEllipse(int32 CenterX, int32 CenterY, float RadiusH, float RadiusV, FLinearColor Color, int32& OutHandleID, FRlDrawEllipse& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ellipse Raylib"))
  static void DrawEllipseUpdate(int32 HandleID, const FRlDrawEllipse& InShape, int32& OutHandleID, FRlDrawEllipse& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ellipse Lines Raylib"))
  static void DrawEllipseLines(FIntPoint Center, float RadiusH, float RadiusV, FLinearColor Color, int32& OutHandleID, FRlDrawEllipseLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ellipse Lines Raylib"))
  static void DrawEllipseLinesUpdate(int32 HandleID, const FRlDrawEllipseLines& InShape, int32& OutHandleID, FRlDrawEllipseLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ring Raylib"))
  static void DrawRing(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRing& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ring Raylib"))
  static void DrawRingUpdate(int32 HandleID, const FRlDrawRing& InShape, int32& OutHandleID, FRlDrawRing& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ring Lines Raylib"))
  static void DrawRingLines(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRingLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ring Lines Raylib"))
  static void DrawRingLinesUpdate(int32 HandleID, const FRlDrawRingLines& InShape, int32& OutHandleID, FRlDrawRingLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Raylib"))
  static void DrawRectangle(int32 PosX, int32 PosY, int32 Width, int32 Height, FLinearColor Color, int32& OutHandleID, FRlDrawRectangle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Raylib"))
  static void DrawRectangleUpdate(int32 HandleID, const FRlDrawRectangle& InShape, int32& OutHandleID, FRlDrawRectangle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle V Raylib"))
  static void DrawRectangleV(FIntPoint Position, FIntPoint Size, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle V Raylib"))
  static void DrawRectangleVUpdate(int32 HandleID, const FRlDrawRectangleV& InShape, int32& OutHandleID, FRlDrawRectangleV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rec Raylib"))
  static void DrawRectangleRec(FIntPoint Position, FIntPoint Size, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rec Raylib"))
  static void DrawRectangleRecUpdate(int32 HandleID, const FRlDrawRectangleRec& InShape, int32& OutHandleID, FRlDrawRectangleRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Pro Raylib"))
  static void DrawRectanglePro(FIntPoint Position, FIntPoint Size, FIntPoint Origin, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawRectanglePro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Pro Raylib"))
  static void DrawRectangleProUpdate(int32 HandleID, const FRlDrawRectanglePro& InShape, int32& OutHandleID, FRlDrawRectanglePro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient V Raylib"))
  static void DrawRectangleGradientV(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawRectangleGradientV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient V Raylib"))
  static void DrawRectangleGradientVUpdate(int32 HandleID, const FRlDrawRectangleGradientV& InShape, int32& OutHandleID, FRlDrawRectangleGradientV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient H Raylib"))
  static void DrawRectangleGradientH(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawRectangleGradientH& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient H Raylib"))
  static void DrawRectangleGradientHUpdate(int32 HandleID, const FRlDrawRectangleGradientH& InShape, int32& OutHandleID, FRlDrawRectangleGradientH& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient Ex Raylib"))
  static void DrawRectangleGradientEx(FIntPoint TopLeft, FIntPoint TopRight, FIntPoint BottomRight, FIntPoint BottomLeft, int32& OutHandleID, FRlDrawRectangleGradientEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient Ex Raylib"))
  static void DrawRectangleGradientExUpdate(int32 HandleID, const FRlDrawRectangleGradientEx& InShape, int32& OutHandleID, FRlDrawRectangleGradientEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Lines Raylib"))
  static void DrawRectangleLines(FIntPoint Position, FIntPoint Size, int32 LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Lines Raylib"))
  static void DrawRectangleLinesUpdate(int32 HandleID, const FRlDrawRectangleLines& InShape, int32& OutHandleID, FRlDrawRectangleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Lines Ex Raylib"))
  static void DrawRectangleLinesEx(FIntPoint Position, FIntPoint Size, float LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleLinesEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Lines Ex Raylib"))
  static void DrawRectangleLinesExUpdate(int32 HandleID, const FRlDrawRectangleLinesEx& InShape, int32& OutHandleID, FRlDrawRectangleLinesEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rounded Raylib"))
  static void DrawRectangleRounded(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRounded& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rounded Raylib"))
  static void DrawRectangleRoundedUpdate(int32 HandleID, const FRlDrawRectangleRounded& InShape, int32& OutHandleID, FRlDrawRectangleRounded& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rounded Lines Raylib"))
  static void DrawRectangleRoundedLines(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, int32 LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRoundedLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rounded Lines Raylib"))
  static void DrawRectangleRoundedLinesUpdate(int32 HandleID, const FRlDrawRectangleRoundedLines& InShape, int32& OutHandleID, FRlDrawRectangleRoundedLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Triangle Raylib"))
  static void DrawTriangle(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Triangle Raylib"))
  static void DrawTriangleUpdate(int32 HandleID, const FRlDrawTriangle& InShape, int32& OutHandleID, FRlDrawTriangle& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Triangle Lines Raylib"))
  static void DrawTriangleLines(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Triangle Lines Raylib"))
  static void DrawTriangleLinesUpdate(int32 HandleID, const FRlDrawTriangleLines& InShape, int32& OutHandleID, FRlDrawTriangleLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Raylib"))
  static void DrawPoly(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawPoly& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Raylib"))
  static void DrawPolyUpdate(int32 HandleID, const FRlDrawPoly& InShape, int32& OutHandleID, FRlDrawPoly& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Lines Raylib"))
  static void DrawPolyLines(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawPolyLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Lines Raylib"))
  static void DrawPolyLinesUpdate(int32 HandleID, const FRlDrawPolyLines& InShape, int32& OutHandleID, FRlDrawPolyLines& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Lines Ex Raylib"))
  static void DrawPolyLinesEx(const TArray<FIntPoint>& Points, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawPolyLinesEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Lines Ex Raylib"))
  static void DrawPolyLinesExUpdate(int32 HandleID, const FRlDrawPolyLinesEx& InShape, int32& OutHandleID, FRlDrawPolyLinesEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw FPS Raylib"))
  static void DrawFPS(int32 PosX, int32 PosY, int32& OutHandleID, FRlDrawFPS& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw FPS Raylib"))
  static void DrawFPSUpdate(int32 HandleID, const FRlDrawFPS& InShape, int32& OutHandleID, FRlDrawFPS& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Raylib"))
  static void DrawText(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, int32& OutHandleID, FRlDrawText& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Raylib"))
  static void DrawTextUpdate(int32 HandleID, const FRlDrawText& InShape, int32& OutHandleID, FRlDrawText& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Ex Raylib"))
  static void DrawTextEx(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Ex Raylib"))
  static void DrawTextExUpdate(int32 HandleID, const FRlDrawTextEx& InShape, int32& OutHandleID, FRlDrawTextEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Pro Raylib"))
  static void DrawTextPro(const FString& Text, FIntPoint Position, FIntPoint Origin, float Rotation, float FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextPro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Pro Raylib"))
  static void DrawTextProUpdate(int32 HandleID, const FRlDrawTextPro& InShape, int32& OutHandleID, FRlDrawTextPro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Codepoint Raylib"))
  static void DrawTextCodepoint(int32 Codepoint, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, int32& OutHandleID, FRlDrawTextCodepoint& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Codepoint Raylib"))
  static void DrawTextCodepointUpdate(int32 HandleID, const FRlDrawTextCodepoint& InShape, int32& OutHandleID, FRlDrawTextCodepoint& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Codepoints Raylib"))
  static void DrawTextCodepoints(const TArray<int32>& Codepoints, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextCodepoints& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Codepoints Raylib"))
  static void DrawTextCodepointsUpdate(int32 HandleID, const FRlDrawTextCodepoints& InShape, int32& OutHandleID, FRlDrawTextCodepoints& OutShape);

  // 3D
  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Line 3D Raylib"))
  static void DrawLine3D(FVector StartPos, FVector EndPos, FLinearColor Color, int32& OutHandleID, FRlDrawLine3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Line 3D Raylib"))
  static void DrawLine3DUpdate(int32 HandleID, const FRlDrawLine3D& InShape, int32& OutHandleID, FRlDrawLine3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Point 3D Raylib"))
  static void DrawPoint3D(FVector Position, FLinearColor Color, int32& OutHandleID, FRlDrawPoint3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Point 3D Raylib"))
  static void DrawPoint3DUpdate(int32 HandleID, const FRlDrawPoint3D& InShape, int32& OutHandleID, FRlDrawPoint3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Circle 3D Raylib"))
  static void DrawCircle3D(FVector Center, float Radius, FVector RotationAxis, float RotationAngle, FLinearColor Color, int32& OutHandleID, FRlDrawCircle3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Circle 3D Raylib"))
  static void DrawCircle3DUpdate(int32 HandleID, const FRlDrawCircle3D& InShape, int32& OutHandleID, FRlDrawCircle3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Triangle 3D Raylib"))
  static void DrawTriangle3D(FVector V1, FVector V2, FVector V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangle3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Triangle 3D Raylib"))
  static void DrawTriangle3DUpdate(int32 HandleID, const FRlDrawTriangle3D& InShape, int32& OutHandleID, FRlDrawTriangle3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Triangle Strip 3D Raylib"))
  static void DrawTriangleStrip3D(const TArray<FVector>& Points, FLinearColor Color, int32& OutHandleID, FRlDrawTriangleStrip3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Triangle Strip 3D Raylib"))
  static void DrawTriangleStrip3DUpdate(int32 HandleID, const FRlDrawTriangleStrip3D& InShape, int32& OutHandleID, FRlDrawTriangleStrip3D& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Raylib"))
  static void DrawCube(FVector Position, float Width, float Height, float Length, FLinearColor Color, int32& OutHandleID, FRlDrawCube& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Raylib"))
  static void DrawCubeUpdate(int32 HandleID, const FRlDrawCube& InShape, int32& OutHandleID, FRlDrawCube& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube V Raylib"))
  static void DrawCubeV(FVector Position, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawCubeV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube V Raylib"))
  static void DrawCubeVUpdate(int32 HandleID, const FRlDrawCubeV& InShape, int32& OutHandleID, FRlDrawCubeV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Wires Raylib"))
  static void DrawCubeWires(FVector Position, float Width, float Height, float Length, FLinearColor Color, int32& OutHandleID, FRlDrawCubeWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Wires Raylib"))
  static void DrawCubeWiresUpdate(int32 HandleID, const FRlDrawCubeWires& InShape, int32& OutHandleID, FRlDrawCubeWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Wires V Raylib"))
  static void DrawCubeWiresV(FVector Position, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawCubeWiresV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Wires V Raylib"))
  static void DrawCubeWiresVUpdate(int32 HandleID, const FRlDrawCubeWiresV& InShape, int32& OutHandleID, FRlDrawCubeWiresV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Raylib"))
  static void DrawSphere(FVector Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawSphere& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Raylib"))
  static void DrawSphereUpdate(int32 HandleID, const FRlDrawSphere& InShape, int32& OutHandleID, FRlDrawSphere& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Ex Raylib"))
  static void DrawSphereEx(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawSphereEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Ex Raylib"))
  static void DrawSphereExUpdate(int32 HandleID, const FRlDrawSphereEx& InShape, int32& OutHandleID, FRlDrawSphereEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Wires Raylib"))
  static void DrawSphereWires(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawSphereWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Wires Raylib"))
  static void DrawSphereWiresUpdate(int32 HandleID, const FRlDrawSphereWires& InShape, int32& OutHandleID, FRlDrawSphereWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Raylib"))
  static void DrawCylinder(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinder& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Raylib"))
  static void DrawCylinderUpdate(int32 HandleID, const FRlDrawCylinder& InShape, int32& OutHandleID, FRlDrawCylinder& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Ex Raylib"))
  static void DrawCylinderEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Ex Raylib"))
  static void DrawCylinderExUpdate(int32 HandleID, const FRlDrawCylinderEx& InShape, int32& OutHandleID, FRlDrawCylinderEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Wires Raylib"))
  static void DrawCylinderWires(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Wires Raylib"))
  static void DrawCylinderWiresUpdate(int32 HandleID, const FRlDrawCylinderWires& InShape, int32& OutHandleID, FRlDrawCylinderWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Wires Ex Raylib"))
  static void DrawCylinderWiresEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderWiresEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Wires Ex Raylib"))
  static void DrawCylinderWiresExUpdate(int32 HandleID, const FRlDrawCylinderWiresEx& InShape, int32& OutHandleID, FRlDrawCylinderWiresEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Capsule Raylib"))
  static void DrawCapsule(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, int32& OutHandleID, FRlDrawCapsule& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Capsule Raylib"))
  static void DrawCapsuleUpdate(int32 HandleID, const FRlDrawCapsule& InShape, int32& OutHandleID, FRlDrawCapsule& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Capsule Wires Raylib"))
  static void DrawCapsuleWires(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, int32& OutHandleID, FRlDrawCapsuleWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Capsule Wires Raylib"))
  static void DrawCapsuleWiresUpdate(int32 HandleID, const FRlDrawCapsuleWires& InShape, int32& OutHandleID, FRlDrawCapsuleWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Plane Raylib"))
  static void DrawPlane(FVector CenterPos, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawPlane& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Plane Raylib"))
  static void DrawPlaneUpdate(int32 HandleID, const FRlDrawPlane& InShape, int32& OutHandleID, FRlDrawPlane& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Ray Raylib"))
  static void DrawRay(FVector RayPos, FVector RayDir, FLinearColor Color, int32& OutHandleID, FRlDrawRay& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Ray Raylib"))
  static void DrawRayUpdate(int32 HandleID, const FRlDrawRay& InShape, int32& OutHandleID, FRlDrawRay& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Grid Raylib"))
  static void DrawGrid(int32 Slices, float Spacing, int32& OutHandleID, FRlDrawGrid& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Grid Raylib"))
  static void DrawGridUpdate(int32 HandleID, const FRlDrawGrid& InShape, int32& OutHandleID, FRlDrawGrid& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Raylib"))
  static void DrawModel(const FString& ModelPath, FVector Position, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawModel& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Raylib"))
  static void DrawModelUpdate(int32 HandleID, const FRlDrawModel& InShape, int32& OutHandleID, FRlDrawModel& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Ex Raylib"))
  static void DrawModelEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawModelEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Ex Raylib"))
  static void DrawModelExUpdate(int32 HandleID, const FRlDrawModelEx& InShape, int32& OutHandleID, FRlDrawModelEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Wires Raylib"))
  static void DrawModelWires(const FString& ModelPath, FVector Position, float Scale, FLinearColor WireColor, int32& OutHandleID, FRlDrawModelWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Wires Raylib"))
  static void DrawModelWiresUpdate(int32 HandleID, const FRlDrawModelWires& InShape, int32& OutHandleID, FRlDrawModelWires& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Wires Ex Raylib"))
  static void DrawModelWiresEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor WireColor, int32& OutHandleID, FRlDrawModelWiresEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Wires Ex Raylib"))
  static void DrawModelWiresExUpdate(int32 HandleID, const FRlDrawModelWiresEx& InShape, int32& OutHandleID, FRlDrawModelWiresEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Bounding Box Raylib"))
  static void DrawBoundingBox(const FVector& Min, const FVector& Max, FLinearColor Color, int32& OutHandleID, FRlDrawBoundingBox& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Bounding Box Raylib"))
  static void DrawBoundingBoxUpdate(int32 HandleID, const FRlDrawBoundingBox& InShape, int32& OutHandleID, FRlDrawBoundingBox& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Raylib"))
  static void DrawBillboard(const FString& TexturePath, FVector Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboard& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Raylib"))
  static void DrawBillboardUpdate(int32 HandleID, const FRlDrawBillboard& InShape, int32& OutHandleID, FRlDrawBillboard& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Rec Raylib"))
  static void DrawBillboardRec(const FString& TexturePath, FIntPoint SourceRec, FVector Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboardRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Rec Raylib"))
  static void DrawBillboardRecUpdate(int32 HandleID, const FRlDrawBillboardRec& InShape, int32& OutHandleID, FRlDrawBillboardRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Pro Raylib"))
  static void DrawBillboardPro(const FString& TexturePath, FIntPoint SourceRec, FVector Position, FVector Up, FVector Right, FVector Forward, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboardPro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Pro Raylib"))
  static void DrawBillboardProUpdate(int32 HandleID, const FRlDrawBillboardPro& InShape, int32& OutHandleID, FRlDrawBillboardPro& OutShape);

  // Texture
  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Raylib"))
  static void DrawTexture(const FString& TexturePath, int32 PosX, int32 PosY, FLinearColor Tint, int32& OutHandleID, FRlDrawTexture& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Raylib"))
  static void DrawTextureUpdate(int32 HandleID, const FRlDrawTexture& InShape, int32& OutHandleID, FRlDrawTexture& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture V Raylib"))
  static void DrawTextureV(const FString& TexturePath, FIntPoint Position, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture V Raylib"))
  static void DrawTextureVUpdate(int32 HandleID, const FRlDrawTextureV& InShape, int32& OutHandleID, FRlDrawTextureV& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Ex Raylib"))
  static void DrawTextureEx(const FString& TexturePath, FIntPoint Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Ex Raylib"))
  static void DrawTextureExUpdate(int32 HandleID, const FRlDrawTextureEx& InShape, int32& OutHandleID, FRlDrawTextureEx& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Rec Raylib"))
  static void DrawTextureRec(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Rec Raylib"))
  static void DrawTextureRecUpdate(int32 HandleID, const FRlDrawTextureRec& InShape, int32& OutHandleID, FRlDrawTextureRec& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Pro Raylib"))
  static void DrawTexturePro(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FIntPoint Origin, float Rotation, FLinearColor Tint, int32& OutHandleID, FRlDrawTexturePro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Pro Raylib"))
  static void DrawTextureProUpdate(int32 HandleID, const FRlDrawTexturePro& InShape, int32& OutHandleID, FRlDrawTexturePro& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture NPatch Raylib"))
  static void DrawTextureNPatch(const FString& TexturePath, const TArray<FIntPoint>& NPatchInfo, FIntPoint Dest, float Rotation, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureNPatch& OutShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture NPatch Raylib"))
  static void DrawTextureNPatchUpdate(int32 HandleID, const FRlDrawTextureNPatch& InShape, int32& OutHandleID, FRlDrawTextureNPatch& OutShape);

  // Render
  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Create Draw Command Raylib"))
  static void rlCreateDrawCommand(FRlDrawCommand InCommand, int32& OutHandleID, FRlDrawCommand& OutCommand);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Update Draw Command Raylib"))
  static void rlUpdateDrawCommand(int32 HandleID, FRlDrawCommand InCommand, int32& OutHandleID, FRlDrawCommand& OutCommand);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Get Draw Command Raylib"))
  static void rlGetDrawCommand(int32 HandleID, int32& OutHandleID, FRlDrawCommand& OutCommand);

  UFUNCTION(BlueprintCallable, Category="Raylib|Render")
  static void rlClear();

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Count Draw Commands Raylib"))
  static int32 rlCountDrawCommands();

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Get Draw Commands Raylib"))
  static void rlGetDrawCommands(TArray<FRlDrawCommand>& OutList);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Set Draw Commands Raylib"))
  static void rlSetDrawCommands(const TArray<FRlDrawCommand>& NewList);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Remove All Of Type Raylib"))
  static void rlRemoveAllOfType(ERlDrawType Type);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Send To Top Raylib"))
  static bool rlSendToTop(int32 ID);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Send To Bottom Raylib"))
  static bool rlSendToBottom(int32 ID);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Swap Order Raylib"))
  static bool rlSwapOrder(int32 ID1, int32 ID2);

private:
  static FRlDrawCommandBuffer& rlCmdBuf;
};