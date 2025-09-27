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
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPixelV
USTRUCT(BlueprintType)
struct FRlDrawPixelV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere)FLinearColor Color = FLinearColor::White;
};

// DrawLine
USTRUCT(BlueprintType)
struct FRlDrawLine {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 StartPosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 StartPosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 EndPosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 EndPosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineV
USTRUCT(BlueprintType)
struct FRlDrawLineV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineEx
USTRUCT(BlueprintType)
struct FRlDrawLineEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Thick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineBezier
USTRUCT(BlueprintType)
struct FRlDrawLineBezier {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Thick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineBezierQuad
USTRUCT(BlueprintType)
struct FRlDrawLineBezierQuad {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint ControlPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Thick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineBezierCubic
USTRUCT(BlueprintType)
struct FRlDrawLineBezierCubic {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint StartControlPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint EndControlPos = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Thick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLineStrip
USTRUCT(BlueprintType)
struct FRlDrawLineStrip {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<FIntPoint> Points;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircle
USTRUCT(BlueprintType)
struct FRlDrawCircle {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CenterX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CenterY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircleSector
USTRUCT(BlueprintType)
struct FRlDrawCircleSector {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndAngle = 360.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircleSectorLines
USTRUCT(BlueprintType)
struct FRlDrawCircleSectorLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndAngle = 360.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircleGradient
USTRUCT(BlueprintType)
struct FRlDrawCircleGradient {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color1 = FLinearColor::White;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color2 = FLinearColor::White;
};

// DrawCircleV
USTRUCT(BlueprintType)
struct FRlDrawCircleV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircleLines
USTRUCT(BlueprintType)
struct FRlDrawCircleLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawEllipse
USTRUCT(BlueprintType)
struct FRlDrawEllipse {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CenterX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CenterY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusH = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusV = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawEllipseLines
USTRUCT(BlueprintType)
struct FRlDrawEllipseLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusH = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusV = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRing
USTRUCT(BlueprintType)
struct FRlDrawRing {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float InnerRadius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float OuterRadius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndAngle = 360.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRingLines
USTRUCT(BlueprintType)
struct FRlDrawRingLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float InnerRadius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float OuterRadius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndAngle = 360.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangle
USTRUCT(BlueprintType)
struct FRlDrawRectangle {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Width = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Height = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleV
USTRUCT(BlueprintType)
struct FRlDrawRectangleV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleRec
USTRUCT(BlueprintType)
struct FRlDrawRectangleRec {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectanglePro
USTRUCT(BlueprintType)
struct FRlDrawRectanglePro {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Origin = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleGradientV
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color1 = FLinearColor::White;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color2 = FLinearColor::White;
};

// DrawRectangleGradientH
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientH {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color1 = FLinearColor::White;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color2 = FLinearColor::White;
};

// DrawRectangleGradientEx
USTRUCT(BlueprintType)
struct FRlDrawRectangleGradientEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint TopLeft = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint TopRight = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint BottomRight = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint BottomLeft = FIntPoint::ZeroValue;
};

// DrawRectangleLines
USTRUCT(BlueprintType)
struct FRlDrawRectangleLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 LineThick = 1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleLinesEx
USTRUCT(BlueprintType)
struct FRlDrawRectangleLinesEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float LineThick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleRounded
USTRUCT(BlueprintType)
struct FRlDrawRectangleRounded {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Roundness = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRectangleRoundedLines
USTRUCT(BlueprintType)
struct FRlDrawRectangleRoundedLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Size = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Roundness = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Segments = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 LineThick = 1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTriangle
USTRUCT(BlueprintType)
struct FRlDrawTriangle {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V1 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V2 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V3 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTriangleLines
USTRUCT(BlueprintType)
struct FRlDrawTriangleLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V1 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V2 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint V3 = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPoly
USTRUCT(BlueprintType)
struct FRlDrawPoly {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Sides = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPolyLines
USTRUCT(BlueprintType)
struct FRlDrawPolyLines {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Center = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Sides = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPolyLinesEx
USTRUCT(BlueprintType)
struct FRlDrawPolyLinesEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<FIntPoint> Points;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Thick = 1.0f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawFPS
USTRUCT(BlueprintType)
struct FRlDrawFPS {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
};

// DrawText
USTRUCT(BlueprintType)
struct FRlDrawText {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString Text = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 FontSize = 20;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTextEx
USTRUCT(BlueprintType)
struct FRlDrawTextEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString Text = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 FontSize = 20;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Spacing = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTextPro
USTRUCT(BlueprintType)
struct FRlDrawTextPro {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString Text = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Origin = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float FontSize = 20.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Spacing = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTextCodepoint
USTRUCT(BlueprintType)
struct FRlDrawTextCodepoint {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Codepoint = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 FontSize = 20;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTextCodepoints
USTRUCT(BlueprintType)
struct FRlDrawTextCodepoints {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<int32> Codepoints;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 FontSize = 20;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Spacing = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawLine3D
USTRUCT(BlueprintType)
struct FRlDrawLine3D {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector StartPos = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector EndPos = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPoint3D
USTRUCT(BlueprintType)
struct FRlDrawPoint3D {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCircle3D
USTRUCT(BlueprintType)
struct FRlDrawCircle3D {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Center = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector RotationAxis = FVector::ForwardVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RotationAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTriangle3D
USTRUCT(BlueprintType)
struct FRlDrawTriangle3D {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector V1 = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector V2 = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector V3 = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawTriangleStrip3D
USTRUCT(BlueprintType)
struct FRlDrawTriangleStrip3D {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<FVector> Points;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCube
USTRUCT(BlueprintType)
struct FRlDrawCube {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Width = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Height = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Length = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCubeV
USTRUCT(BlueprintType)
struct FRlDrawCubeV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Size = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCubeWires
USTRUCT(BlueprintType)
struct FRlDrawCubeWires {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Width = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Height = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Length = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCubeWiresV
USTRUCT(BlueprintType)
struct FRlDrawCubeWiresV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Size = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawSphere
USTRUCT(BlueprintType)
struct FRlDrawSphere {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Center = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawSphereEx
USTRUCT(BlueprintType)
struct FRlDrawSphereEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Center = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Rings = 16;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawSphereWires
USTRUCT(BlueprintType)
struct FRlDrawSphereWires {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Center = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Rings = 16;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCylinder
USTRUCT(BlueprintType)
struct FRlDrawCylinder {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusTop = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusBottom = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Height = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCylinderEx
USTRUCT(BlueprintType)
struct FRlDrawCylinderEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector StartVertex = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector EndVertex = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartRadius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndRadius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Sides = 8;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCylinderWires
USTRUCT(BlueprintType)
struct FRlDrawCylinderWires {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusTop = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RadiusBottom = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Height = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCylinderWiresEx
USTRUCT(BlueprintType)
struct FRlDrawCylinderWiresEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector StartVertex = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector EndVertex = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float StartRadius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float EndRadius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Sides = 8;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCapsule
USTRUCT(BlueprintType)
struct FRlDrawCapsule {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Start = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector End = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Rings = 16;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawCapsuleWires
USTRUCT(BlueprintType)
struct FRlDrawCapsuleWires {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Start = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector End = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Radius = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 32;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Rings = 16;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawPlane
USTRUCT(BlueprintType)
struct FRlDrawPlane {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector CenterPos = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Size = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawRay
USTRUCT(BlueprintType)
struct FRlDrawRay {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector RayPos = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector RayDir = FVector::ForwardVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawGrid
USTRUCT(BlueprintType)
struct FRlDrawGrid {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 Slices = 10;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Spacing = 1.f;
};

// DrawModel
USTRUCT(BlueprintType)
struct FRlDrawModel {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString ModelPath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawModelEx
USTRUCT(BlueprintType)
struct FRlDrawModelEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString ModelPath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector RotationAxis = FVector::ForwardVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RotationAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Scale = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawModelWires
USTRUCT(BlueprintType)
struct FRlDrawModelWires {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString ModelPath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor WireColor = FLinearColor::White;
};

// DrawModelWiresEx
USTRUCT(BlueprintType)
struct FRlDrawModelWiresEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString ModelPath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector RotationAxis = FVector::ForwardVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float RotationAngle = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Scale = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor WireColor = FLinearColor::White;
};

// DrawBoundingBox
USTRUCT(BlueprintType)
struct FRlDrawBoundingBox {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Min = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Max = FVector::OneVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Color = FLinearColor::White;
};

// DrawBillboard
USTRUCT(BlueprintType)
struct FRlDrawBillboard {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawBillboardRec
USTRUCT(BlueprintType)
struct FRlDrawBillboardRec {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint SourceRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawBillboardPro
USTRUCT(BlueprintType)
struct FRlDrawBillboardPro {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint SourceRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Position = FVector::ZeroVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Up = FVector::UpVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Right = FVector::RightVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector Forward = FVector::ForwardVector;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTexture
USTRUCT(BlueprintType)
struct FRlDrawTexture {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosX = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 PosY = 0;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTextureV
USTRUCT(BlueprintType)
struct FRlDrawTextureV {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTextureEx
USTRUCT(BlueprintType)
struct FRlDrawTextureEx {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Position = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Scale = 1.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTextureRec
USTRUCT(BlueprintType)
struct FRlDrawTextureRec {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint SourceRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint DestRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTexturePro
USTRUCT(BlueprintType)
struct FRlDrawTexturePro {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint SourceRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint DestRec = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Origin = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};

// DrawTextureNPatch
USTRUCT(BlueprintType)
struct FRlDrawTextureNPatch {
  GENERATED_BODY()
  UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 CommandID = -1;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FString TexturePath = TEXT("");
  UPROPERTY(BlueprintReadWrite, EditAnywhere) TArray<FIntPoint> NPatchInfo;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FIntPoint Dest = FIntPoint::ZeroValue;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) float Rotation = 0.f;
  UPROPERTY(BlueprintReadWrite, EditAnywhere) FLinearColor Tint = FLinearColor::White;
};


UCLASS()
class URaylibUEBPLibrary : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Pixel Raylib"))
  static void DrawPixel(int32 PosX, int32 PosY, FLinearColor Color, FRlDrawPixel& Pixel);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Pixel Raylib"))
  static FRlDrawPixel DrawPixelUpdate(UPARAM(ref) const FRlDrawPixel& Pixel);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Pixel V Raylib"))
  static void DrawPixelV(FIntPoint Position, FLinearColor Color, FRlDrawPixelV& PixelV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Pixel V Raylib"))
  static FRlDrawPixelV DrawPixelVUpdate(UPARAM(ref) const FRlDrawPixelV& PixelV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Raylib"))
  static void DrawLine(int32 StartPosX, int32 StartPosY, int32 EndPosX, int32 EndPosY, FLinearColor Color, FRlDrawLine& Line);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Raylib"))
  static FRlDrawLine DrawLineUpdate(UPARAM(ref) const FRlDrawLine& Line);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line V Raylib"))
  static void DrawLineV(FIntPoint StartPos, FIntPoint EndPos, FLinearColor Color, FRlDrawLineV& LineV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line V Raylib"))
  static FRlDrawLineV DrawLineVUpdate(UPARAM(ref) const FRlDrawLineV& LineV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Ex Raylib"))
  static void DrawLineEx(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, FRlDrawLineEx& LineEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Ex Raylib"))
  static FRlDrawLineEx DrawLineExUpdate(UPARAM(ref) const FRlDrawLineEx& LineEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Raylib"))
  static void DrawLineBezier(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, FRlDrawLineBezier& LineBezier);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Raylib"))
  static FRlDrawLineBezier DrawLineBezierUpdate(UPARAM(ref) const FRlDrawLineBezier& LineBezier);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Quad Raylib"))
  static void DrawLineBezierQuad(FIntPoint StartPos, FIntPoint EndPos, FIntPoint ControlPos, float Thick, FLinearColor Color, FRlDrawLineBezierQuad& LineBezierQuad);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Quad Raylib"))
  static FRlDrawLineBezierQuad DrawLineBezierQuadUpdate(UPARAM(ref) const FRlDrawLineBezierQuad& LineBezierQuad);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Bezier Cubic Raylib"))
  static void DrawLineBezierCubic(FIntPoint StartPos, FIntPoint EndPos, FIntPoint StartControlPos, FIntPoint EndControlPos, float Thick, FLinearColor Color, FRlDrawLineBezierCubic& LineBezierCubic);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Bezier Cubic Raylib"))
  static FRlDrawLineBezierCubic DrawLineBezierCubicUpdate(UPARAM(ref) const FRlDrawLineBezierCubic& LineBezierCubic);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Line Strip Raylib"))
  static void DrawLineStrip(const TArray<FIntPoint>& Points, FLinearColor Color, FRlDrawLineStrip& LineStrip);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Line Strip Raylib"))
  static FRlDrawLineStrip DrawLineStripUpdate(UPARAM(ref) const FRlDrawLineStrip& LineStrip);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Raylib"))
  static void DrawCircle(int32 CenterX, int32 CenterY, float Radius, FLinearColor Color, FRlDrawCircle& Circle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Raylib"))
  static FRlDrawCircle DrawCircleUpdate(UPARAM(ref) const FRlDrawCircle& Circle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Sector Raylib"))
  static void DrawCircleSector(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawCircleSector& CircleSector);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Sector Raylib"))
  static FRlDrawCircleSector DrawCircleSectorUpdate(UPARAM(ref) const FRlDrawCircleSector& CircleSector);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Sector Lines Raylib"))
  static void DrawCircleSectorLines(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawCircleSectorLines& CircleSectorLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Sector Lines Raylib"))
  static FRlDrawCircleSectorLines DrawCircleSectorLinesUpdate(UPARAM(ref) const FRlDrawCircleSectorLines& CircleSectorLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Gradient Raylib"))
  static void DrawCircleGradient(FIntPoint Center, float Radius, FLinearColor Color1, FLinearColor Color2, FRlDrawCircleGradient& CircleGradient);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Gradient Raylib"))
  static FRlDrawCircleGradient DrawCircleGradientUpdate(UPARAM(ref) const FRlDrawCircleGradient& CircleGradient);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle V Raylib"))
  static void DrawCircleV(FIntPoint Center, float Radius, FLinearColor Color, FRlDrawCircleV& CircleV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle V Raylib"))
  static FRlDrawCircleV DrawCircleVUpdate(UPARAM(ref) const FRlDrawCircleV& CircleV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Circle Lines Raylib"))
  static void DrawCircleLines(FIntPoint Center, float Radius, FLinearColor Color, FRlDrawCircleLines& CircleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Circle Lines Raylib"))
  static FRlDrawCircleLines DrawCircleLinesUpdate(UPARAM(ref) const FRlDrawCircleLines& CircleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ellipse Raylib"))
  static void DrawEllipse(int32 CenterX, int32 CenterY, float RadiusH, float RadiusV, FLinearColor Color, FRlDrawEllipse& Ellipse);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ellipse Raylib"))
  static FRlDrawEllipse DrawEllipseUpdate(UPARAM(ref) const FRlDrawEllipse& Ellipse);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ellipse Lines Raylib"))
  static void DrawEllipseLines(FIntPoint Center, float RadiusH, float RadiusV, FLinearColor Color, FRlDrawEllipseLines& EllipseLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ellipse Lines Raylib"))
  static FRlDrawEllipseLines DrawEllipseLinesUpdate(UPARAM(ref) const FRlDrawEllipseLines& EllipseLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ring Raylib"))
  static void DrawRing(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawRing& Ring);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ring Raylib"))
  static FRlDrawRing DrawRingUpdate(UPARAM(ref) const FRlDrawRing& Ring);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Ring Lines Raylib"))
  static void DrawRingLines(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawRingLines& RingLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Ring Lines Raylib"))
  static FRlDrawRingLines DrawRingLinesUpdate(UPARAM(ref) const FRlDrawRingLines& RingLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle V Raylib"))
  static void DrawRectangle(int32 PosX, int32 PosY, int32 Width, int32 Height, FLinearColor Color, FRlDrawRectangle& Rectangle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Raylib"))
  static FRlDrawRectangle DrawRectangleUpdate(UPARAM(ref) const FRlDrawRectangle& Rectangle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle V Raylib"))
  static void DrawRectangleV(FIntPoint Position, FIntPoint Size, FLinearColor Color, FRlDrawRectangleV& RectangleV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle V Raylib"))
  static FRlDrawRectangleV DrawRectangleVUpdate(UPARAM(ref) const FRlDrawRectangleV& RectangleV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rec Raylib"))
  static void DrawRectangleRec(FIntPoint Position, FIntPoint Size, FLinearColor Color, FRlDrawRectangleRec& RectangleRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rec Raylib"))
  static FRlDrawRectangleRec DrawRectangleRecUpdate(UPARAM(ref) const FRlDrawRectangleRec& RectangleRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Pro Raylib"))
  static void DrawRectanglePro(FIntPoint Position, FIntPoint Size, FIntPoint Origin, float Rotation, FLinearColor Color, FRlDrawRectanglePro& RectanglePro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Pro Raylib"))
  static FRlDrawRectanglePro DrawRectangleProUpdate(UPARAM(ref) const FRlDrawRectanglePro& RectanglePro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient V Raylib"))
  static void DrawRectangleGradientV(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, FRlDrawRectangleGradientV& RectangleGradientV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient V Raylib"))
  static FRlDrawRectangleGradientV DrawRectangleGradientVUpdate(UPARAM(ref) const FRlDrawRectangleGradientV& RectangleGradientV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient H Raylib"))
  static void DrawRectangleGradientH(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, FRlDrawRectangleGradientH& RectangleGradientH);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient H Raylib"))
  static FRlDrawRectangleGradientH DrawRectangleGradientHUpdate(UPARAM(ref) const FRlDrawRectangleGradientH& RectangleGradientH);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Gradient Ex Raylib"))
  static void DrawRectangleGradientEx(FIntPoint TopLeft, FIntPoint TopRight, FIntPoint BottomRight, FIntPoint BottomLeft, FRlDrawRectangleGradientEx& RectangleGradientEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Gradient Ex Raylib"))
  static FRlDrawRectangleGradientEx DrawRectangleGradientExUpdate(UPARAM(ref) const FRlDrawRectangleGradientEx& RectangleGradientEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Lines Raylib"))
  static void DrawRectangleLines(FIntPoint Position, FIntPoint Size, int32 LineThick, FLinearColor Color, FRlDrawRectangleLines& RectangleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Lines Raylib"))
  static FRlDrawRectangleLines DrawRectangleLinesUpdate(UPARAM(ref) const FRlDrawRectangleLines& RectangleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Lines Ex Raylib"))
  static void DrawRectangleLinesEx(FIntPoint Position, FIntPoint Size, float LineThick, FLinearColor Color, FRlDrawRectangleLinesEx& RectangleLinesEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Lines Ex Raylib"))
  static FRlDrawRectangleLinesEx DrawRectangleLinesExUpdate(UPARAM(ref) const FRlDrawRectangleLinesEx& RectangleLinesEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rounded Raylib"))
  static void DrawRectangleRounded(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, FLinearColor Color, FRlDrawRectangleRounded& RectangleRounded);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rounded Raylib"))
  static FRlDrawRectangleRounded DrawRectangleRoundedUpdate(UPARAM(ref) const FRlDrawRectangleRounded& RectangleRounded);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Rectangle Rounded Lines Raylib"))
  static void DrawRectangleRoundedLines(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, int32 LineThick, FLinearColor Color, FRlDrawRectangleRoundedLines& RectangleRoundedLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Rectangle Rounded Lines Raylib"))
  static FRlDrawRectangleRoundedLines DrawRectangleRoundedLinesUpdate(UPARAM(ref) const FRlDrawRectangleRoundedLines& RectangleRoundedLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Triangle Raylib"))
  static void DrawTriangle(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, FRlDrawTriangle& Triangle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Triangle Raylib"))
  static FRlDrawTriangle DrawTriangleUpdate(UPARAM(ref) const FRlDrawTriangle& Triangle);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Triangle Lines Raylib"))
  static void DrawTriangleLines(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, FRlDrawTriangleLines& TriangleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Triangle Lines Raylib"))
  static FRlDrawTriangleLines DrawTriangleLinesUpdate(UPARAM(ref) const FRlDrawTriangleLines& TriangleLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Raylib"))
  static void DrawPoly(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, FRlDrawPoly& Poly);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Raylib"))
  static FRlDrawPoly DrawPolyUpdate(UPARAM(ref) const FRlDrawPoly& Poly);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Lines Raylib"))
  static void DrawPolyLines(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, FRlDrawPolyLines& PolyLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Lines Raylib"))
  static FRlDrawPolyLines DrawPolyLinesUpdate(UPARAM(ref) const FRlDrawPolyLines& PolyLines);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Poly Lines Ex Raylib"))
  static void DrawPolyLinesEx(const TArray<FIntPoint>& Points, float Thick, FLinearColor Color, FRlDrawPolyLinesEx& PolyLinesEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Poly Lines Ex Raylib"))
  static FRlDrawPolyLinesEx DrawPolyLinesExUpdate(UPARAM(ref) const FRlDrawPolyLinesEx& PolyLinesEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw FPS Raylib"))
  static void DrawFPS(int32 PosX, int32 PosY, FRlDrawFPS& FPS);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw FPS Raylib"))
  static FRlDrawFPS DrawFPSUpdate(UPARAM(ref) const FRlDrawFPS& FPS);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Raylib"))
  static void DrawText(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, FRlDrawText& TextShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Raylib"))
  static FRlDrawText DrawTextUpdate(UPARAM(ref) const FRlDrawText& TextShape);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Ex Raylib"))
  static void DrawTextEx(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, FRlDrawTextEx& TextEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Ex Raylib"))
  static FRlDrawTextEx DrawTextExUpdate(UPARAM(ref) const FRlDrawTextEx& TextEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Pro Raylib"))
  static void DrawTextPro(const FString& Text, FIntPoint Position, FIntPoint Origin, float Rotation, float FontSize, float Spacing, FLinearColor Color, FRlDrawTextPro& TextPro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Pro Raylib"))
  static FRlDrawTextPro DrawTextProUpdate(UPARAM(ref) const FRlDrawTextPro& TextPro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Codepoint Raylib"))
  static void DrawTextCodepoint(int32 Codepoint, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, FRlDrawTextCodepoint& TextCodepoint);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Codepoint Raylib"))
  static FRlDrawTextCodepoint DrawTextCodepointUpdate(UPARAM(ref) const FRlDrawTextCodepoint& TextCodepoint);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Draw Text Codepoints Raylib"))
  static void DrawTextCodepoints(const TArray<int32>& Codepoints, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, FRlDrawTextCodepoints& TextCodepoints);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Draw", meta = (Keywords = "Update Draw Text Codepoints Raylib"))
  static FRlDrawTextCodepoints DrawTextCodepointsUpdate(UPARAM(ref) const FRlDrawTextCodepoints& TextCodepoints);

  // 3D
  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Line 3D Raylib"))
  static void DrawLine3D(FVector StartPos, FVector EndPos, FLinearColor Color, FRlDrawLine3D& Line3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Line 3D Raylib"))
  static FRlDrawLine3D DrawLine3DUpdate(UPARAM(ref) const FRlDrawLine3D& Line3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Point 3D Raylib"))
  static void DrawPoint3D(FVector Position, FLinearColor Color, FRlDrawPoint3D& Point3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Point 3D Raylib"))
  static FRlDrawPoint3D DrawPoint3DUpdate(UPARAM(ref) const FRlDrawPoint3D& Point3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Circle 3D Raylib"))
  static void DrawCircle3D(FVector Center, float Radius, FVector RotationAxis, float RotationAngle, FLinearColor Color, FRlDrawCircle3D& Circle3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Circle 3D Raylib"))
  static FRlDrawCircle3D DrawCircle3DUpdate(UPARAM(ref) const FRlDrawCircle3D& Circle3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Triangle 3D Raylib"))
  static void DrawTriangle3D(FVector V1, FVector V2, FVector V3, FLinearColor Color, FRlDrawTriangle3D& Triangle3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Triangle 3D Raylib"))
  static FRlDrawTriangle3D DrawTriangle3DUpdate(UPARAM(ref) const FRlDrawTriangle3D& Triangle3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Triangle Strip 3D Raylib"))
  static void DrawTriangleStrip3D(const TArray<FVector>& Points, FLinearColor Color, FRlDrawTriangleStrip3D& TriangleStrip3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Triangle Strip 3D Raylib"))
  static FRlDrawTriangleStrip3D DrawTriangleStrip3DUpdate(UPARAM(ref) const FRlDrawTriangleStrip3D& TriangleStrip3D);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Raylib"))
  static void DrawCube(FVector Position, float Width, float Height, float Length, FLinearColor Color, FRlDrawCube& Cube);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Raylib"))
  static FRlDrawCube DrawCubeUpdate(UPARAM(ref) const FRlDrawCube& Cube);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube V Raylib"))
  static void DrawCubeV(FVector Position, FVector Size, FLinearColor Color, FRlDrawCubeV& CubeV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube V Raylib"))
  static FRlDrawCubeV DrawCubeVUpdate(UPARAM(ref) const FRlDrawCubeV& CubeV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Wires Raylib"))
  static void DrawCubeWires(FVector Position, float Width, float Height, float Length, FLinearColor Color, FRlDrawCubeWires& CubeWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Wires Raylib"))
  static FRlDrawCubeWires DrawCubeWiresUpdate(UPARAM(ref) const FRlDrawCubeWires& CubeWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cube Wires V Raylib"))
  static void DrawCubeWiresV(FVector Position, FVector Size, FLinearColor Color, FRlDrawCubeWiresV& CubeWiresV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cube Wires V Raylib"))
  static FRlDrawCubeWiresV DrawCubeWiresVUpdate(UPARAM(ref) const FRlDrawCubeWiresV& CubeWiresV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Raylib"))
  static void DrawSphere(FVector Center, float Radius, FLinearColor Color, FRlDrawSphere& Sphere);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Raylib"))
  static FRlDrawSphere DrawSphereUpdate(UPARAM(ref) const FRlDrawSphere& Sphere);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Ex Raylib"))
  static void DrawSphereEx(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, FRlDrawSphereEx& SphereEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Ex Raylib"))
  static FRlDrawSphereEx DrawSphereExUpdate(UPARAM(ref) const FRlDrawSphereEx& SphereEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Sphere Wires Raylib"))
  static void DrawSphereWires(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, FRlDrawSphereWires& SphereWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Sphere Wires Raylib"))
  static FRlDrawSphereWires DrawSphereWiresUpdate(UPARAM(ref) const FRlDrawSphereWires& SphereWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Raylib"))
  static void DrawCylinder(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, FRlDrawCylinder& Cylinder);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Raylib"))
  static FRlDrawCylinder DrawCylinderUpdate(UPARAM(ref) const FRlDrawCylinder& Cylinder);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Ex Raylib"))
  static void DrawCylinderEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, FRlDrawCylinderEx& CylinderEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Ex Raylib"))
  static FRlDrawCylinderEx DrawCylinderExUpdate(UPARAM(ref) const FRlDrawCylinderEx& CylinderEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Wires Raylib"))
  static void DrawCylinderWires(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, FRlDrawCylinderWires& CylinderWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Wires Raylib"))
  static FRlDrawCylinderWires DrawCylinderWiresUpdate(UPARAM(ref) const FRlDrawCylinderWires& CylinderWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Cylinder Wires Ex Raylib"))
  static void DrawCylinderWiresEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, FRlDrawCylinderWiresEx& CylinderWiresEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Cylinder Wires Ex Raylib"))
  static FRlDrawCylinderWiresEx DrawCylinderWiresExUpdate(UPARAM(ref) const FRlDrawCylinderWiresEx& CylinderWiresEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Capsule Raylib"))
  static void DrawCapsule(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, FRlDrawCapsule& Capsule);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Capsule Raylib"))
  static FRlDrawCapsule DrawCapsuleUpdate(UPARAM(ref) const FRlDrawCapsule& Capsule);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Capsule Wires Raylib"))
  static void DrawCapsuleWires(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, FRlDrawCapsuleWires& CapsuleWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Capsule Wires Raylib"))
  static FRlDrawCapsuleWires DrawCapsuleWiresUpdate(UPARAM(ref) const FRlDrawCapsuleWires& CapsuleWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Plane Raylib"))
  static void DrawPlane(FVector CenterPos, FVector Size, FLinearColor Color, FRlDrawPlane& Plane);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Plane Raylib"))
  static FRlDrawPlane DrawPlaneUpdate(UPARAM(ref) const FRlDrawPlane& Plane);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Ray Raylib"))
  static void DrawRay(FVector RayPos, FVector RayDir, FLinearColor Color, FRlDrawRay& Ray);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Ray Raylib"))
  static FRlDrawRay DrawRayUpdate(UPARAM(ref) const FRlDrawRay& Ray);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Grid Raylib"))
  static void DrawGrid(int32 Slices, float Spacing, FRlDrawGrid& Grid);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Grid Raylib"))
  static FRlDrawGrid DrawGridUpdate(UPARAM(ref) const FRlDrawGrid& Grid);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Raylib"))
  static void DrawModel(const FString& ModelPath, FVector Position, float Scale, FLinearColor Tint, FRlDrawModel& Model);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Raylib"))
  static FRlDrawModel DrawModelUpdate(UPARAM(ref) const FRlDrawModel& Model);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Ex Raylib"))
  static void DrawModelEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor Tint, FRlDrawModelEx& ModelEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Ex Raylib"))
  static FRlDrawModelEx DrawModelExUpdate(UPARAM(ref) const FRlDrawModelEx& ModelEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Wires Raylib"))
  static void DrawModelWires(const FString& ModelPath, FVector Position, float Scale, FLinearColor WireColor, FRlDrawModelWires& ModelWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Wires Raylib"))
  static FRlDrawModelWires DrawModelWiresUpdate(UPARAM(ref) const FRlDrawModelWires& ModelWires);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Model Wires Ex Raylib"))
  static void DrawModelWiresEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor WireColor, FRlDrawModelWiresEx& ModelWiresEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Model Wires Ex Raylib"))
  static FRlDrawModelWiresEx DrawModelWiresExUpdate(UPARAM(ref) const FRlDrawModelWiresEx& ModelWiresEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Bounding Box Raylib"))
  static void DrawBoundingBox(const FVector& Min, const FVector& Max, FLinearColor Color, FRlDrawBoundingBox& BoundingBox);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Bounding Box Raylib"))
  static FRlDrawBoundingBox DrawBoundingBoxUpdate(UPARAM(ref) const FRlDrawBoundingBox& BoundingBox);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Raylib"))
  static void DrawBillboard(const FString& TexturePath, FVector Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboard& Billboard);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Raylib"))
  static FRlDrawBillboard DrawBillboardUpdate(UPARAM(ref) const FRlDrawBillboard& Billboard);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Rec Raylib"))
  static void DrawBillboardRec(const FString& TexturePath, FIntPoint SourceRec, FVector Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboardRec& BillboardRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Rec Raylib"))
  static FRlDrawBillboardRec DrawBillboardRecUpdate(UPARAM(ref) const FRlDrawBillboardRec& BillboardRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Draw Billboard Pro Raylib"))
  static void DrawBillboardPro(const FString& TexturePath, FIntPoint SourceRec, FVector Position, FVector Up, FVector Right, FVector Forward, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboardPro& BillboardPro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|3D", meta = (Keywords = "Update Draw Billboard Pro Raylib"))
  static FRlDrawBillboardPro DrawBillboardProUpdate(UPARAM(ref) const FRlDrawBillboardPro& BillboardPro);

  // Texture
  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Raylib"))
  static void DrawTexture(const FString& TexturePath, int32 PosX, int32 PosY, FLinearColor Tint, FRlDrawTexture& Texture);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Raylib"))
  static FRlDrawTexture DrawTextureUpdate(UPARAM(ref) const FRlDrawTexture& Texture);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture V Raylib"))
  static void DrawTextureV(const FString& TexturePath, FIntPoint Position, FLinearColor Tint, FRlDrawTextureV& TextureV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture V Raylib"))
  static FRlDrawTextureV DrawTextureVUpdate(UPARAM(ref) const FRlDrawTextureV& TextureV);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Ex Raylib"))
  static void DrawTextureEx(const FString& TexturePath, FIntPoint Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawTextureEx& TextureEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Ex Raylib"))
  static FRlDrawTextureEx DrawTextureExUpdate(UPARAM(ref) const FRlDrawTextureEx& TextureEx);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Rec Raylib"))
  static void DrawTextureRec(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FLinearColor Tint, FRlDrawTextureRec& TextureRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Rec Raylib"))
  static FRlDrawTextureRec DrawTextureRecUpdate(UPARAM(ref) const FRlDrawTextureRec& TextureRec);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture Pro Raylib"))
  static void DrawTexturePro(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FIntPoint Origin, float Rotation, FLinearColor Tint, FRlDrawTexturePro& TexturePro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture Pro Raylib"))
  static FRlDrawTexturePro DrawTextureProUpdate(UPARAM(ref) const FRlDrawTexturePro& TexturePro);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Draw Texture NPatch Raylib"))
  static void DrawTextureNPatch(const FString& TexturePath, const TArray<FIntPoint>& NPatchInfo, FIntPoint Dest, float Rotation, FLinearColor Tint, FRlDrawTextureNPatch& TextureNPatch);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Texture", meta = (Keywords = "Update Draw Texture NPatch Raylib"))
  static FRlDrawTextureNPatch DrawTextureNPatchUpdate(UPARAM(ref) const FRlDrawTextureNPatch& TextureNPatch);

// Render
  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Create Draw Command Raylib"))
  static void rlCreateDrawCommand(FRlDrawCommand InCommand, FRlDrawCommand& OutCommand);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Update Draw Command Raylib"))
  static void rlUpdateDrawCommand(FRlDrawCommand InCommand, FRlDrawCommand& OutCommand);

  UFUNCTION(BlueprintCallable, Category = "Raylib|Render", meta = (Keywords = "Get Draw Command Raylib"))
  static void rlGetDrawCommand(int32& OutID, FRlDrawCommand& OutCommand);

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