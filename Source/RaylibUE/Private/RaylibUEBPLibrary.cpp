#include "RaylibUEBPLibrary.h"
#include "RaylibUE.h"
#include "Math/Color.h"

URaylibUEBPLibrary::URaylibUEBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer) {
}

FRlDrawCommandBuffer& URaylibUEBPLibrary::rlCmdBuf = FRaylibUEModule::rlDrawCommandsBuffer;

void URaylibUEBPLibrary::DrawPixel(int32 PosX, int32 PosY, FLinearColor Color, int32& OutHandleID, FRlDrawPixel& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPixel;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPixelUpdate(int32 HandleID, const FRlDrawPixel& InShape, int32& OutHandleID, FRlDrawPixel& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPixel();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPixel;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPixelV(FIntPoint Position, FLinearColor Color, int32& OutHandleID, FRlDrawPixelV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPixelV;
  Cmd.Position = Position;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPixelVUpdate(int32 HandleID, const FRlDrawPixelV& InShape, int32& OutHandleID, FRlDrawPixelV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPixelV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPixelV;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLine(int32 StartPosX, int32 StartPosY, int32 EndPosX, int32 EndPosY, FLinearColor Color, int32& OutHandleID, FRlDrawLine& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLine;
  Cmd.StartPos = FIntPoint(StartPosX, StartPosY);
  Cmd.EndPos = FIntPoint(EndPosX, EndPosY);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPosX = StartPosX;
  OutShape.StartPosY = StartPosY;
  OutShape.EndPosX = EndPosX;
  OutShape.EndPosY = EndPosY;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineUpdate(int32 HandleID, const FRlDrawLine& InShape, int32& OutHandleID, FRlDrawLine& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLine();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLine;
  UpdateCmd.StartPos = FIntPoint(InShape.StartPosX, InShape.StartPosY);
  UpdateCmd.EndPos = FIntPoint(InShape.EndPosX, InShape.EndPosY);
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineV(FIntPoint StartPos, FIntPoint EndPos, FLinearColor Color, int32& OutHandleID, FRlDrawLineV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineV;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineVUpdate(int32 HandleID, const FRlDrawLineV& InShape, int32& OutHandleID, FRlDrawLineV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineV;
  UpdateCmd.StartPos = InShape.StartPos;
  UpdateCmd.EndPos = InShape.EndPos;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineEx(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineEx;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.Thick = Thick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineExUpdate(int32 HandleID, const FRlDrawLineEx& InShape, int32& OutHandleID, FRlDrawLineEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineEx;
  UpdateCmd.StartPos = InShape.StartPos;
  UpdateCmd.EndPos = InShape.EndPos;
  UpdateCmd.Thick = InShape.Thick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineBezier(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezier& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezier;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.Thick = Thick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineBezierUpdate(int32 HandleID, const FRlDrawLineBezier& InShape, int32& OutHandleID, FRlDrawLineBezier& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineBezier();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezier;
  UpdateCmd.StartPos = InShape.StartPos;
  UpdateCmd.EndPos = InShape.EndPos;
  UpdateCmd.Thick = InShape.Thick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineBezierQuad(FIntPoint StartPos, FIntPoint EndPos, FIntPoint ControlPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezierQuad& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezierQuad;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Position = ControlPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.ControlPos = ControlPos;
  OutShape.Thick = Thick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineBezierQuadUpdate(int32 HandleID, const FRlDrawLineBezierQuad& InShape, int32& OutHandleID, FRlDrawLineBezierQuad& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineBezierQuad();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezierQuad;
  UpdateCmd.StartPos = InShape.StartPos;
  UpdateCmd.EndPos = InShape.EndPos;
  UpdateCmd.Position = InShape.ControlPos;
  UpdateCmd.Thick = InShape.Thick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineBezierCubic(FIntPoint StartPos, FIntPoint EndPos, FIntPoint StartControlPos, FIntPoint EndControlPos, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawLineBezierCubic& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezierCubic;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Position = StartControlPos;
  Cmd.Size = EndControlPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.StartControlPos = StartControlPos;
  OutShape.EndControlPos = EndControlPos;
  OutShape.Thick = Thick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineBezierCubicUpdate(int32 HandleID, const FRlDrawLineBezierCubic& InShape, int32& OutHandleID, FRlDrawLineBezierCubic& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineBezierCubic();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezierCubic;
  UpdateCmd.StartPos = InShape.StartPos;
  UpdateCmd.EndPos = InShape.EndPos;
  UpdateCmd.Position = InShape.StartControlPos;
  UpdateCmd.Size = InShape.EndControlPos;
  UpdateCmd.Thick = InShape.Thick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLineStrip(const TArray<FIntPoint>& Points, FLinearColor Color, int32& OutHandleID, FRlDrawLineStrip& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineStrip;
  Cmd.Points = Points;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Points = Points;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLineStripUpdate(int32 HandleID, const FRlDrawLineStrip& InShape, int32& OutHandleID, FRlDrawLineStrip& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLineStrip();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineStrip;
  UpdateCmd.Points = InShape.Points;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircle(int32 CenterX, int32 CenterY, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircle& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircle;
  Cmd.Position = FIntPoint(CenterX, CenterY);
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.CenterX = CenterX;
  OutShape.CenterY = CenterY;
  OutShape.Radius = Radius;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleUpdate(int32 HandleID, const FRlDrawCircle& InShape, int32& OutHandleID, FRlDrawCircle& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircle();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircle;
  UpdateCmd.Position = FIntPoint(InShape.CenterX, InShape.CenterY);
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircleSector(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawCircleSector& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleSector;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.StartAngle = StartAngle;
  OutShape.EndAngle = EndAngle;
  OutShape.Segments = Segments;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleSectorUpdate(int32 HandleID, const FRlDrawCircleSector& InShape, int32& OutHandleID, FRlDrawCircleSector& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircleSector();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleSector;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.StartAngle = InShape.StartAngle;
  UpdateCmd.EndAngle = InShape.EndAngle;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircleSectorLines(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawCircleSectorLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleSectorLines;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.StartAngle = StartAngle;
  OutShape.EndAngle = EndAngle;
  OutShape.Segments = Segments;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleSectorLinesUpdate(int32 HandleID, const FRlDrawCircleSectorLines& InShape, int32& OutHandleID, FRlDrawCircleSectorLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircleSectorLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleSector;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.StartAngle = InShape.StartAngle;
  UpdateCmd.EndAngle = InShape.EndAngle;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircleGradient(FIntPoint Center, float Radius, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawCircleGradient& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleGradient;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  if (Cmd.Color1.A == 0.f) Cmd.Color1.A = 1.f;
  if (Cmd.Color2.A == 0.f) Cmd.Color2.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Color1 = Color1;
  OutShape.Color2 = Color2;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleGradientUpdate(int32 HandleID, const FRlDrawCircleGradient& InShape, int32& OutHandleID, FRlDrawCircleGradient& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircleGradient();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleGradient;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Color1 = InShape.Color1;
  UpdateCmd.Color2 = InShape.Color2;
  if (UpdateCmd.Color1.A == 0.f) UpdateCmd.Color1.A = 1.f;
  if (UpdateCmd.Color2.A == 0.f) UpdateCmd.Color2.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircleV(FIntPoint Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircleV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleV;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleVUpdate(int32 HandleID, const FRlDrawCircleV& InShape, int32& OutHandleID, FRlDrawCircleV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircleV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleV;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircleLines(FIntPoint Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawCircleLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleLines;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircleLinesUpdate(int32 HandleID, const FRlDrawCircleLines& InShape, int32& OutHandleID, FRlDrawCircleLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircleLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleLines;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawEllipse(int32 CenterX, int32 CenterY, float RadiusH, float RadiusV, FLinearColor Color, int32& OutHandleID, FRlDrawEllipse& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawEllipse;
  Cmd.Position = FIntPoint(CenterX, CenterY);
  Cmd.Radius = RadiusH;
  Cmd.Size.X = (int32)RadiusV;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.CenterX = CenterX;
  OutShape.CenterY = CenterY;
  OutShape.RadiusH = RadiusH;
  OutShape.RadiusV = RadiusV;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawEllipseUpdate(int32 HandleID, const FRlDrawEllipse& InShape, int32& OutHandleID, FRlDrawEllipse& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawEllipse();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawEllipse;
  UpdateCmd.Position = FIntPoint(InShape.CenterX, InShape.CenterY);
  UpdateCmd.Radius = InShape.RadiusH;
  UpdateCmd.Size.X = (int32)InShape.RadiusV;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawEllipseLines(FIntPoint Center, float RadiusH, float RadiusV, FLinearColor Color, int32& OutHandleID, FRlDrawEllipseLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawEllipseLines;
  Cmd.Position = Center;
  Cmd.Radius = RadiusH;
  Cmd.Size.X = (int32)RadiusV;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.RadiusH = RadiusH;
  OutShape.RadiusV = RadiusV;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawEllipseLinesUpdate(int32 HandleID, const FRlDrawEllipseLines& InShape, int32& OutHandleID, FRlDrawEllipseLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawEllipseLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawEllipseLines;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.RadiusH;
  UpdateCmd.Size.X = (int32)InShape.RadiusV;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRing(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRing& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRing;
  Cmd.Position = Center;
  Cmd.Radius = OuterRadius;
  Cmd.Size.X = (int32)InnerRadius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.InnerRadius = InnerRadius;
  OutShape.OuterRadius = OuterRadius;
  OutShape.StartAngle = StartAngle;
  OutShape.EndAngle = EndAngle;
  OutShape.Segments = Segments;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRingUpdate(int32 HandleID, const FRlDrawRing& InShape, int32& OutHandleID, FRlDrawRing& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRing();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRing;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.OuterRadius;
  UpdateCmd.Size.X = (int32)InShape.InnerRadius;
  UpdateCmd.StartAngle = InShape.StartAngle;
  UpdateCmd.EndAngle = InShape.EndAngle;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRingLines(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRingLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRingLines;
  Cmd.Position = Center;
  Cmd.Radius = OuterRadius;
  Cmd.Size.X = (int32)InnerRadius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.InnerRadius = InnerRadius;
  OutShape.OuterRadius = OuterRadius;
  OutShape.StartAngle = StartAngle;
  OutShape.EndAngle = EndAngle;
  OutShape.Segments = Segments;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRingLinesUpdate(int32 HandleID, const FRlDrawRingLines& InShape, int32& OutHandleID, FRlDrawRingLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRingLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRingLines;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Radius = InShape.OuterRadius;
  UpdateCmd.Size.X = (int32)InShape.InnerRadius;
  UpdateCmd.StartAngle = InShape.StartAngle;
  UpdateCmd.EndAngle = InShape.EndAngle;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangle(int32 PosX, int32 PosY, int32 Width, int32 Height, FLinearColor Color, int32& OutHandleID, FRlDrawRectangle& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangle;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Size = FIntPoint(Width, Height);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.Width = Width;
  OutShape.Height = Height;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleUpdate(int32 HandleID, const FRlDrawRectangle& InShape, int32& OutHandleID, FRlDrawRectangle& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangle();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangle;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Size = FIntPoint(InShape.Width, InShape.Height);
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleV(FIntPoint Position, FIntPoint Size, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleV;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleVUpdate(int32 HandleID, const FRlDrawRectangleV& InShape, int32& OutHandleID, FRlDrawRectangleV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleV;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleRec(FIntPoint Position, FIntPoint Size, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRec& OutShape) {
  int32 TempHandleID;
  FRlDrawRectangleV TempShape;
  DrawRectangleV(Position, Size, Color, TempHandleID, TempShape);
  OutHandleID = TempHandleID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color = Color;
  OutShape.CommandID = TempHandleID;
}

void URaylibUEBPLibrary::DrawRectangleRecUpdate(int32 HandleID, const FRlDrawRectangleRec& InShape, int32& OutHandleID, FRlDrawRectangleRec& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleRec();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRec;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectanglePro(FIntPoint Position, FIntPoint Size, FIntPoint Origin, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawRectanglePro& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectanglePro;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Origin = Origin;
  OutShape.Rotation = Rotation;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleProUpdate(int32 HandleID, const FRlDrawRectanglePro& InShape, int32& OutHandleID, FRlDrawRectanglePro& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectanglePro();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectanglePro;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.StartPos = InShape.Origin;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleGradientV(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawRectangleGradientV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientV;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  if (Cmd.Color1.A == 0.f) Cmd.Color1.A = 1.f;
  if (Cmd.Color2.A == 0.f) Cmd.Color2.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color1 = Color1;
  OutShape.Color2 = Color2;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleGradientVUpdate(int32 HandleID, const FRlDrawRectangleGradientV& InShape, int32& OutHandleID, FRlDrawRectangleGradientV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleGradientV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientV;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Color1 = InShape.Color1;
  UpdateCmd.Color2 = InShape.Color2;
  if (UpdateCmd.Color1.A == 0.f) UpdateCmd.Color1.A = 1.f;
  if (UpdateCmd.Color2.A == 0.f) UpdateCmd.Color2.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleGradientH(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, int32& OutHandleID, FRlDrawRectangleGradientH& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientH;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  if (Cmd.Color1.A == 0.f) Cmd.Color1.A = 1.f;
  if (Cmd.Color2.A == 0.f) Cmd.Color2.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color1 = Color1;
  OutShape.Color2 = Color2;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleGradientHUpdate(int32 HandleID, const FRlDrawRectangleGradientH& InShape, int32& OutHandleID, FRlDrawRectangleGradientH& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleGradientH();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientH;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Color1 = InShape.Color1;
  UpdateCmd.Color2 = InShape.Color2;
  if (UpdateCmd.Color1.A == 0.f) UpdateCmd.Color1.A = 1.f;
  if (UpdateCmd.Color2.A == 0.f) UpdateCmd.Color2.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleGradientEx(FIntPoint TopLeft, FIntPoint TopRight, FIntPoint BottomRight, FIntPoint BottomLeft, int32& OutHandleID, FRlDrawRectangleGradientEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientEx;
  Cmd.Position = TopLeft;
  Cmd.StartPos = TopRight;
  Cmd.EndPos = BottomRight;
  Cmd.Size = BottomLeft;
  if (Cmd.Color1.A == 0.f) Cmd.Color1.A = 1.f;
  if (Cmd.Color2.A == 0.f) Cmd.Color2.A = 1.f;
  if (Cmd.Color3.A == 0.f) Cmd.Color3.A = 1.f;
  if (Cmd.Color4.A == 0.f) Cmd.Color4.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TopLeft = TopLeft;
  OutShape.TopRight = TopRight;
  OutShape.BottomRight = BottomRight;
  OutShape.BottomLeft = BottomLeft;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleGradientExUpdate(int32 HandleID, const FRlDrawRectangleGradientEx& InShape, int32& OutHandleID, FRlDrawRectangleGradientEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleGradientEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientEx;
  UpdateCmd.Position = InShape.TopLeft;
  UpdateCmd.StartPos = InShape.TopRight;
  UpdateCmd.EndPos = InShape.BottomRight;
  UpdateCmd.Size = InShape.BottomLeft;
  if (UpdateCmd.Color1.A == 0.f) UpdateCmd.Color1.A = 1.f;
  if (UpdateCmd.Color2.A == 0.f) UpdateCmd.Color2.A = 1.f;
  if (UpdateCmd.Color3.A == 0.f) UpdateCmd.Color3.A = 1.f;
  if (UpdateCmd.Color4.A == 0.f) UpdateCmd.Color4.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleLines(FIntPoint Position, FIntPoint Size, int32 LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleLines;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.LineThick = LineThick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleLinesUpdate(int32 HandleID, const FRlDrawRectangleLines& InShape, int32& OutHandleID, FRlDrawRectangleLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleLines;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Thick = InShape.LineThick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleLinesEx(FIntPoint Position, FIntPoint Size, float LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleLinesEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleLinesEx;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.LineThick = LineThick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleLinesExUpdate(int32 HandleID, const FRlDrawRectangleLinesEx& InShape, int32& OutHandleID, FRlDrawRectangleLinesEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleLinesEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleLinesEx;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Thick = InShape.LineThick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleRounded(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRounded& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleRounded;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Roundness = Roundness;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Roundness = Roundness;
  OutShape.Segments = Segments;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleRoundedUpdate(int32 HandleID, const FRlDrawRectangleRounded& InShape, int32& OutHandleID, FRlDrawRectangleRounded& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleRounded();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRounded;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Roundness = InShape.Roundness;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRectangleRoundedLines(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, int32 LineThick, FLinearColor Color, int32& OutHandleID, FRlDrawRectangleRoundedLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleRoundedLines;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Roundness = Roundness;
  Cmd.Segments = Segments;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Roundness = Roundness;
  OutShape.Segments = Segments;
  OutShape.LineThick = LineThick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRectangleRoundedLinesUpdate(int32 HandleID, const FRlDrawRectangleRoundedLines& InShape, int32& OutHandleID, FRlDrawRectangleRoundedLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRectangleRoundedLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRoundedLines;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Size = InShape.Size;
  UpdateCmd.Roundness = InShape.Roundness;
  UpdateCmd.Segments = InShape.Segments;
  UpdateCmd.Thick = InShape.LineThick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTriangle(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangle& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangle;
  Cmd.Points = {V1, V2, V3};
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.V1 = V1;
  OutShape.V2 = V2;
  OutShape.V3 = V3;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTriangleUpdate(int32 HandleID, const FRlDrawTriangle& InShape, int32& OutHandleID, FRlDrawTriangle& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTriangle();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTriangle;
  UpdateCmd.Points = {InShape.V1, InShape.V2, InShape.V3};
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTriangleLines(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangleLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangleLines;
  Cmd.Points = {V1, V2, V3};
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.V1 = V1;
  OutShape.V2 = V2;
  OutShape.V3 = V3;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTriangleLinesUpdate(int32 HandleID, const FRlDrawTriangleLines& InShape, int32& OutHandleID, FRlDrawTriangleLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTriangleLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTriangleLines;
  UpdateCmd.Points = {InShape.V1, InShape.V2, InShape.V3};
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPoly(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawPoly& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPoly;
  Cmd.Position = Center;
  Cmd.Sides = Sides;
  Cmd.Radius = Radius;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Sides = Sides;
  OutShape.Radius = Radius;
  OutShape.Rotation = Rotation;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPolyUpdate(int32 HandleID, const FRlDrawPoly& InShape, int32& OutHandleID, FRlDrawPoly& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPoly();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPoly;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Sides = InShape.Sides;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPolyLines(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, int32& OutHandleID, FRlDrawPolyLines& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPolyLines;
  Cmd.Position = Center;
  Cmd.Sides = Sides;
  Cmd.Radius = Radius;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Sides = Sides;
  OutShape.Radius = Radius;
  OutShape.Rotation = Rotation;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPolyLinesUpdate(int32 HandleID, const FRlDrawPolyLines& InShape, int32& OutHandleID, FRlDrawPolyLines& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPolyLines();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPolyLines;
  UpdateCmd.Position = InShape.Center;
  UpdateCmd.Sides = InShape.Sides;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPolyLinesEx(const TArray<FIntPoint>& Points, float Thick, FLinearColor Color, int32& OutHandleID, FRlDrawPolyLinesEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPolyLinesEx;
  Cmd.Points = Points;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Points = Points;
  OutShape.Thick = Thick;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPolyLinesExUpdate(int32 HandleID, const FRlDrawPolyLinesEx& InShape, int32& OutHandleID, FRlDrawPolyLinesEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPolyLinesEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPolyLinesEx;
  UpdateCmd.Points = InShape.Points;
  UpdateCmd.Thick = InShape.Thick;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawFPS(int32 PosX, int32 PosY, int32& OutHandleID, FRlDrawFPS& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawFPS;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = FLinearColor::White;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawFPSUpdate(int32 HandleID, const FRlDrawFPS& InShape, int32& OutHandleID, FRlDrawFPS& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawFPS();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawFPS;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Color = FLinearColor::White;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawText(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, int32& OutHandleID, FRlDrawText& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawText;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Text = Text;
  Cmd.FontSize = FontSize;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Text = Text;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.FontSize = FontSize;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextUpdate(int32 HandleID, const FRlDrawText& InShape, int32& OutHandleID, FRlDrawText& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawText();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawText;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Text = InShape.Text;
  UpdateCmd.FontSize = InShape.FontSize;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextEx(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextEx;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Text = Text;
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Text = Text;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.FontSize = FontSize;
  OutShape.Spacing = Spacing;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextExUpdate(int32 HandleID, const FRlDrawTextEx& InShape, int32& OutHandleID, FRlDrawTextEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextEx;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Text = InShape.Text;
  UpdateCmd.FontSize = InShape.FontSize;
  UpdateCmd.Spacing = InShape.Spacing;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextPro(const FString& Text, FIntPoint Position, FIntPoint Origin, float Rotation, float FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextPro& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextPro;
  Cmd.Position = Position;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Text = Text;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Text = Text;
  OutShape.Position = Position;
  OutShape.Origin = Origin;
  OutShape.Rotation = Rotation;
  OutShape.FontSize = FontSize;
  OutShape.Spacing = Spacing;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextProUpdate(int32 HandleID, const FRlDrawTextPro& InShape, int32& OutHandleID, FRlDrawTextPro& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextPro();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextPro;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.StartPos = InShape.Origin;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.FontSize = InShape.FontSize;
  UpdateCmd.Spacing = InShape.Spacing;
  UpdateCmd.Text = InShape.Text;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextCodepoint(int32 Codepoint, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, int32& OutHandleID, FRlDrawTextCodepoint& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextCodepoint;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.FontSize = FontSize;
  Cmd.Codepoints = {Codepoint};
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Codepoint = Codepoint;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.FontSize = FontSize;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextCodepointUpdate(int32 HandleID, const FRlDrawTextCodepoint& InShape, int32& OutHandleID, FRlDrawTextCodepoint& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextCodepoint();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextCodepoint;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.FontSize = InShape.FontSize;
  UpdateCmd.Codepoints = {InShape.Codepoint};
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextCodepoints(const TArray<int32>& Codepoints, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, int32& OutHandleID, FRlDrawTextCodepoints& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextCodepoints;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Codepoints = Codepoints;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Codepoints = Codepoints;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.FontSize = FontSize;
  OutShape.Spacing = Spacing;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextCodepointsUpdate(int32 HandleID, const FRlDrawTextCodepoints& InShape, int32& OutHandleID, FRlDrawTextCodepoints& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextCodepoints();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextCodepoints;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.FontSize = InShape.FontSize;
  UpdateCmd.Spacing = InShape.Spacing;
  UpdateCmd.Codepoints = InShape.Codepoints;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawLine3D(FVector StartPos, FVector EndPos, FLinearColor Color, int32& OutHandleID, FRlDrawLine3D& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLine3D;
  Cmd.Position3D = StartPos;
  Cmd.Origin3D = EndPos;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartPos = StartPos;
  OutShape.EndPos = EndPos;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawLine3DUpdate(int32 HandleID, const FRlDrawLine3D& InShape, int32& OutHandleID, FRlDrawLine3D& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawLine3D();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLine3D;
  UpdateCmd.Position3D = InShape.StartPos;
  UpdateCmd.Origin3D = InShape.EndPos;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPoint3D(FVector Position, FLinearColor Color, int32& OutHandleID, FRlDrawPoint3D& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPoint3D;
  Cmd.Position3D = Position;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPoint3DUpdate(int32 HandleID, const FRlDrawPoint3D& InShape, int32& OutHandleID, FRlDrawPoint3D& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPoint3D();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPoint3D;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCircle3D(FVector Center, float Radius, FVector RotationAxis, float RotationAngle, FLinearColor Color, int32& OutHandleID, FRlDrawCircle3D& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircle3D;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.RotationAxis = RotationAxis;
  OutShape.RotationAngle = RotationAngle;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCircle3DUpdate(int32 HandleID, const FRlDrawCircle3D& InShape, int32& OutHandleID, FRlDrawCircle3D& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCircle3D();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircle3D;
  UpdateCmd.Position3D = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.RotationAxis = InShape.RotationAxis;
  UpdateCmd.RotationAngle = InShape.RotationAngle;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTriangle3D(FVector V1, FVector V2, FVector V3, FLinearColor Color, int32& OutHandleID, FRlDrawTriangle3D& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangle3D;
  Cmd.Points3D = {V1, V2, V3};
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.V1 = V1;
  OutShape.V2 = V2;
  OutShape.V3 = V3;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTriangle3DUpdate(int32 HandleID, const FRlDrawTriangle3D& InShape, int32& OutHandleID, FRlDrawTriangle3D& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTriangle3D();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTriangle3D;
  UpdateCmd.Points3D = {InShape.V1, InShape.V2, InShape.V3};
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTriangleStrip3D(const TArray<FVector>& Points, FLinearColor Color, int32& OutHandleID, FRlDrawTriangleStrip3D& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangleStrip3D;
  Cmd.Points3D = Points;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Points = Points;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTriangleStrip3DUpdate(int32 HandleID, const FRlDrawTriangleStrip3D& InShape, int32& OutHandleID, FRlDrawTriangleStrip3D& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTriangleStrip3D();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTriangleStrip3D;
  UpdateCmd.Points3D = InShape.Points;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCube(FVector Position, float Width, float Height, float Length, FLinearColor Color, int32& OutHandleID, FRlDrawCube& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCube;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Width, Height, Length);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Width = Width;
  OutShape.Height = Height;
  OutShape.Length = Length;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCubeUpdate(int32 HandleID, const FRlDrawCube& InShape, int32& OutHandleID, FRlDrawCube& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCube();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCube;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = FVector(InShape.Width, InShape.Height, InShape.Length);
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCubeV(FVector Position, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawCubeV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeV;
  Cmd.Position3D = Position;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCubeVUpdate(int32 HandleID, const FRlDrawCubeV& InShape, int32& OutHandleID, FRlDrawCubeV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCubeV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeV;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = InShape.Size;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCubeWires(FVector Position, float Width, float Height, float Length, FLinearColor Color, int32& OutHandleID, FRlDrawCubeWires& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeWires;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Width, Height, Length);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Width = Width;
  OutShape.Height = Height;
  OutShape.Length = Length;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCubeWiresUpdate(int32 HandleID, const FRlDrawCubeWires& InShape, int32& OutHandleID, FRlDrawCubeWires& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCubeWires();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeWires;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = FVector(InShape.Width, InShape.Height, InShape.Length);
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCubeWiresV(FVector Position, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawCubeWiresV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeWiresV;
  Cmd.Position3D = Position;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.Size = Size;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCubeWiresVUpdate(int32 HandleID, const FRlDrawCubeWiresV& InShape, int32& OutHandleID, FRlDrawCubeWiresV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCubeWiresV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeWiresV;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = InShape.Size;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawSphere(FVector Center, float Radius, FLinearColor Color, int32& OutHandleID, FRlDrawSphere& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphere;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawSphereUpdate(int32 HandleID, const FRlDrawSphere& InShape, int32& OutHandleID, FRlDrawSphere& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawSphere();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawSphere;
  UpdateCmd.Position3D = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawSphereEx(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawSphereEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphereEx;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Segments = Rings;
  Cmd.Sides = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Rings = Rings;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawSphereExUpdate(int32 HandleID, const FRlDrawSphereEx& InShape, int32& OutHandleID, FRlDrawSphereEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawSphereEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawSphereEx;
  UpdateCmd.Position3D = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Segments = InShape.Rings;
  UpdateCmd.Sides = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawSphereWires(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawSphereWires& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphereWires;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Segments = Rings;
  Cmd.Sides = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Center = Center;
  OutShape.Radius = Radius;
  OutShape.Rings = Rings;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawSphereWiresUpdate(int32 HandleID, const FRlDrawSphereWires& InShape, int32& OutHandleID, FRlDrawSphereWires& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawSphereWires();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawSphereWires;
  UpdateCmd.Position3D = InShape.Center;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Segments = InShape.Rings;
  UpdateCmd.Sides = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCylinder(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinder& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinder;
  Cmd.Position3D = Position;
  Cmd.Radius = RadiusTop;
  Cmd.Size.X = (int32)RadiusBottom;
  Cmd.Scale3D.Z = Height;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.RadiusTop = RadiusTop;
  OutShape.RadiusBottom = RadiusBottom;
  OutShape.Height = Height;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCylinderUpdate(int32 HandleID, const FRlDrawCylinder& InShape, int32& OutHandleID, FRlDrawCylinder& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCylinder();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCylinder;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Radius = InShape.RadiusTop;
  UpdateCmd.Size.X = (int32)InShape.RadiusBottom;
  UpdateCmd.Scale3D.Z = InShape.Height;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCylinderEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderEx;
  Cmd.Position3D = StartVertex;
  Cmd.Origin3D = EndVertex;
  Cmd.Radius = StartRadius;
  Cmd.Size.X = (int32)EndRadius;
  Cmd.Sides = Sides;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartVertex = StartVertex;
  OutShape.EndVertex = EndVertex;
  OutShape.StartRadius = StartRadius;
  OutShape.EndRadius = EndRadius;
  OutShape.Sides = Sides;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCylinderExUpdate(int32 HandleID, const FRlDrawCylinderEx& InShape, int32& OutHandleID, FRlDrawCylinderEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCylinderEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCylinderEx;
  UpdateCmd.Position3D = InShape.StartVertex;
  UpdateCmd.Origin3D = InShape.EndVertex;
  UpdateCmd.Radius = InShape.StartRadius;
  UpdateCmd.Size.X = (int32)InShape.EndRadius;
  UpdateCmd.Sides = InShape.Sides;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCylinderWires(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderWires& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderWires;
  Cmd.Position3D = Position;
  Cmd.Radius = RadiusTop;
  Cmd.Size.X = (int32)RadiusBottom;
  Cmd.Scale3D.Z = Height;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Position = Position;
  OutShape.RadiusTop = RadiusTop;
  OutShape.RadiusBottom = RadiusBottom;
  OutShape.Height = Height;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCylinderWiresUpdate(int32 HandleID, const FRlDrawCylinderWires& InShape, int32& OutHandleID, FRlDrawCylinderWires& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCylinderWires();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCylinderWires;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Radius = InShape.RadiusTop;
  UpdateCmd.Size.X = (int32)InShape.RadiusBottom;
  UpdateCmd.Scale3D.Z = InShape.Height;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCylinderWiresEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, int32& OutHandleID, FRlDrawCylinderWiresEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderWiresEx;
  Cmd.Position3D = StartVertex;
  Cmd.Origin3D = EndVertex;
  Cmd.Radius = StartRadius;
  Cmd.Size.X = (int32)EndRadius;
  Cmd.Sides = Sides;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.StartVertex = StartVertex;
  OutShape.EndVertex = EndVertex;
  OutShape.StartRadius = StartRadius;
  OutShape.EndRadius = EndRadius;
  OutShape.Sides = Sides;
  OutShape.Slices = Slices;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCylinderWiresExUpdate(int32 HandleID, const FRlDrawCylinderWiresEx& InShape, int32& OutHandleID, FRlDrawCylinderWiresEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCylinderWiresEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCylinderWiresEx;
  UpdateCmd.Position3D = InShape.StartVertex;
  UpdateCmd.Origin3D = InShape.EndVertex;
  UpdateCmd.Radius = InShape.StartRadius;
  UpdateCmd.Size.X = (int32)InShape.EndRadius;
  UpdateCmd.Sides = InShape.Sides;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCapsule(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, int32& OutHandleID, FRlDrawCapsule& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCapsule;
  Cmd.Position3D = Start;
  Cmd.Origin3D = End;
  Cmd.Radius = Radius;
  Cmd.Slices = Slices;
  Cmd.Segments = Rings;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Start = Start;
  OutShape.End = End;
  OutShape.Radius = Radius;
  OutShape.Slices = Slices;
  OutShape.Rings = Rings;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCapsuleUpdate(int32 HandleID, const FRlDrawCapsule& InShape, int32& OutHandleID, FRlDrawCapsule& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCapsule();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCapsule;
  UpdateCmd.Position3D = InShape.Start;
  UpdateCmd.Origin3D = InShape.End;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Segments = InShape.Rings;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawCapsuleWires(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, int32& OutHandleID, FRlDrawCapsuleWires& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCapsuleWires;
  Cmd.Position3D = Start;
  Cmd.Origin3D = End;
  Cmd.Radius = Radius;
  Cmd.Slices = Slices;
  Cmd.Segments = Rings;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Start = Start;
  OutShape.End = End;
  OutShape.Radius = Radius;
  OutShape.Slices = Slices;
  OutShape.Rings = Rings;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawCapsuleWiresUpdate(int32 HandleID, const FRlDrawCapsuleWires& InShape, int32& OutHandleID, FRlDrawCapsuleWires& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawCapsuleWires();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCapsuleWires;
  UpdateCmd.Position3D = InShape.Start;
  UpdateCmd.Origin3D = InShape.End;
  UpdateCmd.Radius = InShape.Radius;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Segments = InShape.Rings;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawPlane(FVector CenterPos, FVector Size, FLinearColor Color, int32& OutHandleID, FRlDrawPlane& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPlane;
  Cmd.Position3D = CenterPos;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.CenterPos = CenterPos;
  OutShape.Size = Size;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawPlaneUpdate(int32 HandleID, const FRlDrawPlane& InShape, int32& OutHandleID, FRlDrawPlane& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawPlane();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPlane;
  UpdateCmd.Position3D = InShape.CenterPos;
  UpdateCmd.Scale3D = InShape.Size;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawRay(FVector RayPos, FVector RayDir, FLinearColor Color, int32& OutHandleID, FRlDrawRay& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRay;
  Cmd.RayOrigin = RayPos;
  Cmd.RayDir = RayDir;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.RayPos = RayPos;
  OutShape.RayDir = RayDir;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawRayUpdate(int32 HandleID, const FRlDrawRay& InShape, int32& OutHandleID, FRlDrawRay& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawRay();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRay;
  UpdateCmd.RayOrigin = InShape.RayPos;
  UpdateCmd.RayDir = InShape.RayDir;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawGrid(int32 Slices, float Spacing, int32& OutHandleID, FRlDrawGrid& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawGrid;
  Cmd.Slices = Slices;
  Cmd.Thick = Spacing;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Slices = Slices;
  OutShape.Spacing = Spacing;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawGridUpdate(int32 HandleID, const FRlDrawGrid& InShape, int32& OutHandleID, FRlDrawGrid& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawGrid();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawGrid;
  UpdateCmd.Slices = InShape.Slices;
  UpdateCmd.Thick = InShape.Spacing;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawModel(const FString& ModelPath, FVector Position, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawModel& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModel;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.ModelPath = ModelPath;
  OutShape.Position = Position;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawModelUpdate(int32 HandleID, const FRlDrawModel& InShape, int32& OutHandleID, FRlDrawModel& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawModel();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawModel;
  UpdateCmd.ModelPath = InShape.ModelPath;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawModelEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawModelEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelEx;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Scale3D = Scale;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.ModelPath = ModelPath;
  OutShape.Position = Position;
  OutShape.RotationAxis = RotationAxis;
  OutShape.RotationAngle = RotationAngle;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawModelExUpdate(int32 HandleID, const FRlDrawModelEx& InShape, int32& OutHandleID, FRlDrawModelEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawModelEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawModelEx;
  UpdateCmd.ModelPath = InShape.ModelPath;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.RotationAxis = InShape.RotationAxis;
  UpdateCmd.RotationAngle = InShape.RotationAngle;
  UpdateCmd.Scale3D = InShape.Scale;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawModelWires(const FString& ModelPath, FVector Position, float Scale, FLinearColor WireColor, int32& OutHandleID, FRlDrawModelWires& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelWires;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = WireColor;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.ModelPath = ModelPath;
  OutShape.Position = Position;
  OutShape.Scale = Scale;
  OutShape.WireColor = WireColor;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawModelWiresUpdate(int32 HandleID, const FRlDrawModelWires& InShape, int32& OutHandleID, FRlDrawModelWires& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawModelWires();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawModelWires;
  UpdateCmd.ModelPath = InShape.ModelPath;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Color = InShape.WireColor;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawModelWiresEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor WireColor, int32& OutHandleID, FRlDrawModelWiresEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelWiresEx;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Scale3D = Scale;
  Cmd.Color = WireColor;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.ModelPath = ModelPath;
  OutShape.Position = Position;
  OutShape.RotationAxis = RotationAxis;
  OutShape.RotationAngle = RotationAngle;
  OutShape.Scale = Scale;
  OutShape.WireColor = WireColor;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawModelWiresExUpdate(int32 HandleID, const FRlDrawModelWiresEx& InShape, int32& OutHandleID, FRlDrawModelWiresEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawModelWiresEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawModelWiresEx;
  UpdateCmd.ModelPath = InShape.ModelPath;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.RotationAxis = InShape.RotationAxis;
  UpdateCmd.RotationAngle = InShape.RotationAngle;
  UpdateCmd.Scale3D = InShape.Scale;
  UpdateCmd.Color = InShape.WireColor;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawBoundingBox(const FVector& Min, const FVector& Max, FLinearColor Color, int32& OutHandleID, FRlDrawBoundingBox& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBoundingBox;
  Cmd.Position3D = Min;
  Cmd.Scale3D = Max - Min;
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.Min = Min;
  OutShape.Max = Max;
  OutShape.Color = Color;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawBoundingBoxUpdate(int32 HandleID, const FRlDrawBoundingBox& InShape, int32& OutHandleID, FRlDrawBoundingBox& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawBoundingBox();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawBoundingBox;
  UpdateCmd.Position3D = InShape.Min;
  UpdateCmd.Scale3D = InShape.Max - InShape.Min;
  UpdateCmd.Color = InShape.Color;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawBillboard(const FString& TexturePath, FVector Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboard& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboard;
  Cmd.TexturePath = TexturePath;
  Cmd.Position3D = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.Position = Position;
  OutShape.Rotation = Rotation;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawBillboardUpdate(int32 HandleID, const FRlDrawBillboard& InShape, int32& OutHandleID, FRlDrawBillboard& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawBillboard();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawBillboard;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawBillboardRec(const FString& TexturePath, FIntPoint SourceRec, FVector Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboardRec& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboardRec;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Position3D = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.SourceRec = SourceRec;
  OutShape.Position = Position;
  OutShape.Rotation = Rotation;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawBillboardRecUpdate(int32 HandleID, const FRlDrawBillboardRec& InShape, int32& OutHandleID, FRlDrawBillboardRec& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawBillboardRec();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawBillboardRec;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.SourcePos = InShape.SourceRec;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawBillboardPro(const FString& TexturePath, FIntPoint SourceRec, FVector Position, FVector Up, FVector Right, FVector Forward, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawBillboardPro& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboardPro;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = Up;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.SourceRec = SourceRec;
  OutShape.Position = Position;
  OutShape.Up = Up;
  OutShape.Right = Right;
  OutShape.Forward = Forward;
  OutShape.Rotation = Rotation;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawBillboardProUpdate(int32 HandleID, const FRlDrawBillboardPro& InShape, int32& OutHandleID, FRlDrawBillboardPro& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawBillboardPro();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawBillboardPro;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.SourcePos = InShape.SourceRec;
  UpdateCmd.Position3D = InShape.Position;
  UpdateCmd.RotationAxis = InShape.Up;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTexture(const FString& TexturePath, int32 PosX, int32 PosY, FLinearColor Tint, int32& OutHandleID, FRlDrawTexture& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTexture;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.PosX = PosX;
  OutShape.PosY = PosY;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureUpdate(int32 HandleID, const FRlDrawTexture& InShape, int32& OutHandleID, FRlDrawTexture& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTexture();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTexture;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.Position = FIntPoint(InShape.PosX, InShape.PosY);
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextureV(const FString& TexturePath, FIntPoint Position, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureV& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureV;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = Position;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.Position = Position;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureVUpdate(int32 HandleID, const FRlDrawTextureV& InShape, int32& OutHandleID, FRlDrawTextureV& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextureV();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextureV;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextureEx(const FString& TexturePath, FIntPoint Position, float Rotation, float Scale, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureEx& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureEx;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.Position = Position;
  OutShape.Rotation = Rotation;
  OutShape.Scale = Scale;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureExUpdate(int32 HandleID, const FRlDrawTextureEx& InShape, int32& OutHandleID, FRlDrawTextureEx& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextureEx();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextureEx;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.Position = InShape.Position;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Scale3D = FVector(InShape.Scale);
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextureRec(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureRec& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureRec;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Size = DestRec;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.SourceRec = SourceRec;
  OutShape.DestRec = DestRec;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureRecUpdate(int32 HandleID, const FRlDrawTextureRec& InShape, int32& OutHandleID, FRlDrawTextureRec& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextureRec();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextureRec;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.SourcePos = InShape.SourceRec;
  UpdateCmd.Size = InShape.DestRec;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTexturePro(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FIntPoint Origin, float Rotation, FLinearColor Tint, int32& OutHandleID, FRlDrawTexturePro& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTexturePro;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Size = DestRec;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.SourceRec = SourceRec;
  OutShape.DestRec = DestRec;
  OutShape.Origin = Origin;
  OutShape.Rotation = Rotation;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureProUpdate(int32 HandleID, const FRlDrawTexturePro& InShape, int32& OutHandleID, FRlDrawTexturePro& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTexturePro();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTexturePro;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.SourcePos = InShape.SourceRec;
  UpdateCmd.Size = InShape.DestRec;
  UpdateCmd.StartPos = InShape.Origin;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::DrawTextureNPatch(const FString& TexturePath, const TArray<FIntPoint>& NPatchInfo, FIntPoint Dest, float Rotation, FLinearColor Tint, int32& OutHandleID, FRlDrawTextureNPatch& OutShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureNPatch;
  Cmd.TexturePath = TexturePath;
  Cmd.Points = NPatchInfo;
  Cmd.Position = Dest;
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  OutHandleID = ID;
  OutShape.TexturePath = TexturePath;
  OutShape.NPatchInfo = NPatchInfo;
  OutShape.Dest = Dest;
  OutShape.Rotation = Rotation;
  OutShape.Tint = Tint;
  OutShape.CommandID = ID;
}

void URaylibUEBPLibrary::DrawTextureNPatchUpdate(int32 HandleID, const FRlDrawTextureNPatch& InShape, int32& OutHandleID, FRlDrawTextureNPatch& OutShape) {
  if (HandleID < 0) {
    OutHandleID = -1;
    OutShape = FRlDrawTextureNPatch();
    return;
  }

  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawTextureNPatch;
  UpdateCmd.TexturePath = InShape.TexturePath;
  UpdateCmd.Points = InShape.NPatchInfo;
  UpdateCmd.Position = InShape.Dest;
  UpdateCmd.Rotation = InShape.Rotation;
  UpdateCmd.Color = InShape.Tint;
  if (UpdateCmd.Color.A == 0.f) UpdateCmd.Color.A = 1.f;

  bool bSuccess = rlCmdBuf.Update(HandleID, UpdateCmd);

  OutHandleID = bSuccess ? HandleID : -1;
  OutShape = InShape;
  OutShape.CommandID = OutHandleID;
}

void URaylibUEBPLibrary::rlCreateDrawCommand(FRlDrawCommand InCommand, int32& OutHandleID, FRlDrawCommand& OutCommand) {
  FRlDrawCommand NewCmd = InCommand;
  if (NewCmd.Color.A == 0) {
  NewCmd.Color.A = 255;
  }
  OutHandleID = rlCmdBuf.Add(NewCmd);
  NewCmd.CommandID = OutHandleID;
  OutCommand = NewCmd;
}

void URaylibUEBPLibrary::rlUpdateDrawCommand(int32 HandleID, FRlDrawCommand InCommand, int32& OutHandleID, FRlDrawCommand& OutCommand) {
  if (HandleID <= 0) {
  UE_LOG(LogTemp, Warning, TEXT("rlUpdateDrawCommand invalid HandleID %d"), HandleID);
  OutCommand = InCommand;
  return;
  }

  FRlDrawCommand UpdateCmd = InCommand;
  if (UpdateCmd.Color.A == 0) {
  UpdateCmd.Color.A = 255;
  }
  UpdateCmd.CommandID = HandleID;
  if (InCommand.Color.A == 0) {
  InCommand.Color.A = 255;
  }
  if (rlCmdBuf.Update(HandleID, UpdateCmd)) {
  OutHandleID = HandleID;
  OutCommand = UpdateCmd;
  } else {
  UE_LOG(LogTemp, Warning, TEXT("rlUpdateDrawCommand failed for ID %d"), HandleID);
  }
}

void URaylibUEBPLibrary::rlGetDrawCommand(int32 HandleID, int32& OutHandleID, FRlDrawCommand& OutCommand) {
  if (int32* IndexPtr = rlCmdBuf.IDToIndex.Find(HandleID)) {
  int32 Index = *IndexPtr;
  if (rlCmdBuf.rlDrawCommands.IsValidIndex(Index)) {
    OutHandleID = Index;
    OutCommand = rlCmdBuf.rlDrawCommands[Index];
    return;
  }
  }
  OutCommand = FRlDrawCommand();
}

void URaylibUEBPLibrary::rlClear() {
  rlCmdBuf.Clear();
}

int32 URaylibUEBPLibrary::rlCountDrawCommands() {
  return rlCmdBuf.rlDrawCommands.Num();
}

void URaylibUEBPLibrary::rlGetDrawCommands(TArray<FRlDrawCommand>& OutList) {
  OutList = rlCmdBuf.rlDrawCommands;
}

void URaylibUEBPLibrary::rlSetDrawCommands(const TArray<FRlDrawCommand>& NewList) {
  rlCmdBuf.Clear();
  for (const FRlDrawCommand& Cmd : NewList) {
  if (Cmd.CommandID != -1 && rlCmdBuf.IDToIndex.Contains(Cmd.CommandID)) {
    UE_LOG(LogTemp, Warning, TEXT("rlSetDrawCommands: Overlapping ID %d ignored"), Cmd.CommandID);
  }
  rlCmdBuf.Add(const_cast<FRlDrawCommand&>(Cmd));
  }
}

void URaylibUEBPLibrary::rlRemoveAllOfType(ERlDrawType Type) {
  TArray<int32> ToRemove;
  for (auto& Pair : rlCmdBuf.IDToIndex) {
  int32 Index = Pair.Value;
  if (rlCmdBuf.rlDrawCommands[Index].Type == Type) {
    ToRemove.Add(Pair.Key);
  }
  }
  for (int32 ID : ToRemove) {
  rlCmdBuf.Remove(ID);
  }
}

bool URaylibUEBPLibrary::rlSendToTop(int32 ID) {
  if (int32* IndexPtr = rlCmdBuf.IDToIndex.Find(ID)) {
  int32 Index = *IndexPtr;
  if (rlCmdBuf.rlDrawCommands.IsValidIndex(Index)) {
    FRlDrawCommand Cmd = MoveTemp(rlCmdBuf.rlDrawCommands[Index]);
    rlCmdBuf.rlDrawCommands.RemoveAt(Index);
    int32 NewIndex = rlCmdBuf.rlDrawCommands.Add(MoveTemp(Cmd));
    rlCmdBuf.IDToIndex[ID] = NewIndex;
    return true;
  }
  }
  UE_LOG(LogTemp, Warning, TEXT("rlSendToTop: Invalid ID %d"), ID);
  return false;
}

bool URaylibUEBPLibrary::rlSendToBottom(int32 ID) {
  if (int32* IndexPtr = rlCmdBuf.IDToIndex.Find(ID)) {
  int32 Index = *IndexPtr;
  if (rlCmdBuf.rlDrawCommands.IsValidIndex(Index)) {
    FRlDrawCommand Cmd = rlCmdBuf.rlDrawCommands[Index];
    rlCmdBuf.rlDrawCommands.RemoveAt(Index);
    int32 NewIndex = 0;
    rlCmdBuf.rlDrawCommands.Insert(Cmd, NewIndex);
    rlCmdBuf.IDToIndex[ID] = NewIndex;
    return true;
  }
  }
  UE_LOG(LogTemp, Warning, TEXT("rlSendToBottom: Invalid ID %d"), ID);
  return false;
}

bool URaylibUEBPLibrary::rlSwapOrder(int32 ID1, int32 ID2) {
  if (int32* Index1Ptr = rlCmdBuf.IDToIndex.Find(ID1)) {
  if (int32* Index2Ptr = rlCmdBuf.IDToIndex.Find(ID2)) {
    int32 Index1 = *Index1Ptr;
    int32 Index2 = *Index2Ptr;
    if (rlCmdBuf.rlDrawCommands.IsValidIndex(Index1) && rlCmdBuf.rlDrawCommands.IsValidIndex(Index2)) {
    rlCmdBuf.rlDrawCommands.Swap(Index1, Index2);
    rlCmdBuf.IDToIndex[ID1] = Index2;
    rlCmdBuf.IDToIndex[ID2] = Index1;
    return true;
    }
  }
  }
  UE_LOG(LogTemp, Warning, TEXT("rlSwapOrder: Invalid ID1 %d or ID2 %d"), ID1, ID2);
  return false;
}
