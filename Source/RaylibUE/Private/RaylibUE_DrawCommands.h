#pragma once
#include "CoreMinimal.h"
#include "RaylibUE_DrawCommands.generated.h"

UENUM(BlueprintType)
enum class ERlDrawType : uint8 {
  DrawPixel,
  DrawPixelV,
  DrawLine,
  DrawLineV,
  DrawLineEx,
  DrawLineBezier,
  DrawLineBezierQuad,
  DrawLineBezierCubic,
  DrawLineStrip,
  DrawCircle,
  DrawCircleSector,
  DrawCircleSectorLines,
  DrawCircleGradient,
  DrawCircleV,
  DrawCircleLines,
  DrawEllipse,
  DrawEllipseLines,
  DrawRing,
  DrawRingLines,
  DrawRectangle,
  DrawRectangleV,
  DrawRectangleRec,
  DrawRectanglePro,
  DrawRectangleGradientV,
  DrawRectangleGradientH,
  DrawRectangleGradientEx,
  DrawRectangleLines,
  DrawRectangleLinesEx,
  DrawRectangleRounded,
  DrawRectangleRoundedLines,
  DrawTriangle,
  DrawTriangleLines,
  DrawPoly,
  DrawPolyLines,
  DrawPolyLinesEx,
  DrawFPS,
  DrawText,
  DrawTextEx,
  DrawTextPro,
  DrawTextCodepoint,
  DrawTextCodepoints,
  // 3D
  DrawLine3D,
  DrawPoint3D,
  DrawCircle3D,
  DrawTriangle3D,
  DrawTriangleStrip3D,
  DrawCube,
  DrawCubeV,
  DrawCubeWires,
  DrawCubeWiresV,
  DrawSphere,
  DrawSphereEx,
  DrawSphereWires,
  DrawCylinder,
  DrawCylinderEx,
  DrawCylinderWires,
  DrawCylinderWiresEx,
  DrawCapsule,
  DrawCapsuleWires,
  DrawPlane,
  DrawRay,
  DrawGrid,
  // Model
  DrawModel,
  DrawModelEx,
  DrawModelWires,
  DrawModelWiresEx,
  DrawBoundingBox,
  DrawBillboard,
  DrawBillboardRec,
  DrawBillboardPro,
  // Texture
  DrawTexture,
  DrawTextureV,
  DrawTextureEx,
  DrawTextureRec,
  DrawTexturePro,
  DrawTextureNPatch,
};



USTRUCT(BlueprintType)
struct FRlDrawCommand {
  GENERATED_BODY()

  UPROPERTY()
  int32 CommandID = -1;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  ERlDrawType Type = ERlDrawType::DrawText;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Position = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint Size = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Radius = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString Text = TEXT("Hello Raylib");

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 FontSize = 32;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FIntPoint> Points;

  // For 3D polys/lines
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<FVector> Points3D;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Thick = 1.0f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint StartPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint EndPos = FIntPoint::ZeroValue;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float StartAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float EndAngle = 360.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Segments = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Roundness = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color1 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color2 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color3 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FLinearColor Color4 = FLinearColor::White;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Sides = 0;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Rotation = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Origin3D = FVector::ZeroVector;

  // For text advanced
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Spacing = 1.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TArray<int32> Codepoints;

  // For 3D/model
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Position3D = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector Scale3D = FVector(1.f);

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RotationAxis = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float RotationAngle = 0.f;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString ModelPath; // Placeholder for model/texture loading

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FString TexturePath;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourcePos;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FIntPoint SourceSize;

  // For ray/grid
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RayOrigin = FVector::ZeroVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  FVector RayDir = FVector::ForwardVector;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  int32 Slices = 10;

 FRlDrawCommand()
    : CommandID(-1)
    , Type(ERlDrawType::DrawText)
    , Position(FIntPoint::ZeroValue)
    , Size(FIntPoint::ZeroValue)
    , Radius(0.f)
    , Color(FLinearColor::White)
    , Text(TEXT("Hello Raylib"))
    , FontSize(32)
    , Points()
    , Points3D()
    , Thick(1.0f)
    , StartPos(FIntPoint::ZeroValue)
    , EndPos(FIntPoint::ZeroValue)
    , StartAngle(0.f)
    , EndAngle(360.f)
    , Segments(0)
    , Roundness(0.f)
    , Color1(FLinearColor::White)
    , Color2(FLinearColor::White)
    , Color3(FLinearColor::White)
    , Color4(FLinearColor::White)
    , Sides(0)
    , Rotation(0.f)
    , Origin3D(FVector::ZeroVector)
    , Spacing(1.f)
    , Codepoints()
    , Position3D(FVector::ZeroVector)
    , Scale3D(FVector(1.f))
    , RotationAxis(FVector::ForwardVector)
    , RotationAngle(0.f)
    , ModelPath()
    , TexturePath()
    , SourcePos(FIntPoint::ZeroValue)
    , SourceSize(FIntPoint::ZeroValue)
    , RayOrigin(FVector::ZeroVector)
    , RayDir(FVector::ForwardVector)
    , Slices(10)
  {}
};

USTRUCT(BlueprintType)
struct FRlDrawCommandBuffer {
  GENERATED_BODY()

  UPROPERTY()
  TArray<FRlDrawCommand> rlDrawCommands;

  UPROPERTY()
  TMap<int32, int32> IDToIndex;

  int32 Add(FRlDrawCommand& Cmd);
  void Clear();
  bool Update(const FRlDrawCommand& Cmd);
  bool Remove(int32 CommandID);
};