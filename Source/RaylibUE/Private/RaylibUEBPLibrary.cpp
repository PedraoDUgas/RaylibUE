#include "RaylibUEBPLibrary.h"
#include "RaylibUE.h"
#include "Math/Color.h"

URaylibUEBPLibrary::URaylibUEBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer) {
}

FRlDrawCommandBuffer& URaylibUEBPLibrary::rlCmdBuf = FRaylibUEModule::rlDrawCommandsBuffer;

void URaylibUEBPLibrary::DrawPixel(int32 PosX, int32 PosY, FLinearColor Color, FRlDrawPixel& Pixel) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPixel;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Pixel.CommandID = ID;
  Pixel.PosX = PosX;
  Pixel.PosY = PosY;
  Pixel.Color = Color;
}

FRlDrawPixel URaylibUEBPLibrary::DrawPixelUpdate(const FRlDrawPixel& Pixel) {
  FRlDrawPixel OutPixel;
  if (Pixel.CommandID < 0) {
    OutPixel.CommandID = -1;
    OutPixel = FRlDrawPixel();
    return OutPixel;
  }

  OutPixel = Pixel;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPixel;
  UpdateCmd.Position = FIntPoint(Pixel.PosX, Pixel.PosY);
  UpdateCmd.Color = Pixel.Color;
  OutPixel.CommandID = rlCmdBuf.Update(UpdateCmd) ? Pixel.CommandID : -1; 
  return OutPixel;
}

void URaylibUEBPLibrary::DrawPixelV(FIntPoint Position, FLinearColor Color, FRlDrawPixelV& PixelV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPixelV;
  Cmd.Position = Position;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  PixelV.CommandID = ID;
  PixelV.Position = Position;
  PixelV.Color = Color;
}

FRlDrawPixelV URaylibUEBPLibrary::DrawPixelVUpdate(const FRlDrawPixelV& PixelV) {
  FRlDrawPixelV OutPixelV;
  if (PixelV.CommandID < 0) {
    OutPixelV.CommandID = -1;
    OutPixelV = FRlDrawPixelV();
    return OutPixelV;
  }

  OutPixelV = PixelV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPixelV;
  UpdateCmd.Position = PixelV.Position;
  UpdateCmd.Color = PixelV.Color;
  OutPixelV.CommandID = rlCmdBuf.Update(UpdateCmd) ? PixelV.CommandID : -1; 
  return OutPixelV;
}

void URaylibUEBPLibrary::DrawLine(int32 StartPosX, int32 StartPosY, int32 EndPosX, int32 EndPosY, FLinearColor Color, FRlDrawLine& Line) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLine;
  Cmd.StartPos = FIntPoint(StartPosX, StartPosY);
  Cmd.EndPos = FIntPoint(EndPosX, EndPosY);
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Line.CommandID = ID;
  Line.StartPosX = StartPosX;
  Line.StartPosY = StartPosY;
  Line.EndPosX = EndPosX;
  Line.EndPosY = EndPosY;
  Line.Color = Color;
}

FRlDrawLine URaylibUEBPLibrary::DrawLineUpdate(const FRlDrawLine& Line) {
  FRlDrawLine OutLine;
  if (Line.CommandID < 0) {
    OutLine.CommandID = -1;
    OutLine = FRlDrawLine();
    return OutLine;
  }

  OutLine = Line;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLine;
  UpdateCmd.StartPos = FIntPoint(Line.StartPosX, Line.StartPosY);
  UpdateCmd.EndPos = FIntPoint(Line.EndPosX, Line.EndPosY);
  UpdateCmd.Color = Line.Color;
  OutLine.CommandID = rlCmdBuf.Update(UpdateCmd) ? Line.CommandID : -1; 
  return OutLine;
}

void URaylibUEBPLibrary::DrawLineV(FIntPoint StartPos, FIntPoint EndPos, FLinearColor Color, FRlDrawLineV& LineV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineV;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineV.CommandID = ID;
  LineV.StartPos = StartPos;
  LineV.EndPos = EndPos;
  LineV.Color = Color;
}

FRlDrawLineV URaylibUEBPLibrary::DrawLineVUpdate(const FRlDrawLineV& LineV) {
  FRlDrawLineV OutLineV;
  if (LineV.CommandID < 0) {
    OutLineV.CommandID = -1;
    OutLineV = FRlDrawLineV();
    return OutLineV;
  }

  OutLineV = LineV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineV;
  UpdateCmd.StartPos = LineV.StartPos;
  UpdateCmd.EndPos = LineV.EndPos;
  UpdateCmd.Color = LineV.Color;
  OutLineV.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineV.CommandID : -1; 
  return OutLineV;
}

void URaylibUEBPLibrary::DrawLineEx(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, FRlDrawLineEx& LineEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineEx;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineEx.CommandID = ID;
  LineEx.StartPos = StartPos;
  LineEx.EndPos = EndPos;
  LineEx.Thick = Thick;
  LineEx.Color = Color;
}

FRlDrawLineEx URaylibUEBPLibrary::DrawLineExUpdate(const FRlDrawLineEx& LineEx) {
  FRlDrawLineEx OutLineEx;
  if (LineEx.CommandID < 0) {
    OutLineEx.CommandID = -1;
    OutLineEx = FRlDrawLineEx();
    return OutLineEx;
  }

  OutLineEx = LineEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineEx;
  UpdateCmd.StartPos = LineEx.StartPos;
  UpdateCmd.EndPos = LineEx.EndPos;
  UpdateCmd.Thick = LineEx.Thick;
  UpdateCmd.Color = LineEx.Color;
  OutLineEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineEx.CommandID : -1; 
  return OutLineEx;
}

void URaylibUEBPLibrary::DrawLineBezier(FIntPoint StartPos, FIntPoint EndPos, float Thick, FLinearColor Color, FRlDrawLineBezier& LineBezier) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezier;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineBezier.CommandID = ID;
  LineBezier.StartPos = StartPos;
  LineBezier.EndPos = EndPos;
  LineBezier.Thick = Thick;
  LineBezier.Color = Color;
}

FRlDrawLineBezier URaylibUEBPLibrary::DrawLineBezierUpdate(const FRlDrawLineBezier& LineBezier) {
  FRlDrawLineBezier OutLineBezier;
  if (LineBezier.CommandID < 0) {
    OutLineBezier.CommandID = -1;
    OutLineBezier = FRlDrawLineBezier();
    return OutLineBezier;
  }

  OutLineBezier = LineBezier;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezier;
  UpdateCmd.StartPos = LineBezier.StartPos;
  UpdateCmd.EndPos = LineBezier.EndPos;
  UpdateCmd.Thick = LineBezier.Thick;
  UpdateCmd.Color = LineBezier.Color;
  OutLineBezier.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineBezier.CommandID : -1; 
  return OutLineBezier;
}

void URaylibUEBPLibrary::DrawLineBezierQuad(FIntPoint StartPos, FIntPoint EndPos, FIntPoint ControlPos, float Thick, FLinearColor Color, FRlDrawLineBezierQuad& LineBezierQuad) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezierQuad;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Position = ControlPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineBezierQuad.CommandID = ID;
  LineBezierQuad.StartPos = StartPos;
  LineBezierQuad.EndPos = EndPos;
  LineBezierQuad.ControlPos = ControlPos;
  LineBezierQuad.Thick = Thick;
  LineBezierQuad.Color = Color;
}

FRlDrawLineBezierQuad URaylibUEBPLibrary::DrawLineBezierQuadUpdate(const FRlDrawLineBezierQuad& LineBezierQuad) {
  FRlDrawLineBezierQuad OutLineBezierQuad;
  if (LineBezierQuad.CommandID < 0) {
    OutLineBezierQuad.CommandID = -1;
    OutLineBezierQuad = FRlDrawLineBezierQuad();
    return OutLineBezierQuad;
  }

  OutLineBezierQuad = LineBezierQuad;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezierQuad;
  UpdateCmd.StartPos = LineBezierQuad.StartPos;
  UpdateCmd.EndPos = LineBezierQuad.EndPos;
  UpdateCmd.Position = LineBezierQuad.ControlPos;
  UpdateCmd.Thick = LineBezierQuad.Thick;
  UpdateCmd.Color = LineBezierQuad.Color;
  OutLineBezierQuad.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineBezierQuad.CommandID : -1; 
  return OutLineBezierQuad;
}

void URaylibUEBPLibrary::DrawLineBezierCubic(FIntPoint StartPos, FIntPoint EndPos, FIntPoint StartControlPos, FIntPoint EndControlPos, float Thick, FLinearColor Color, FRlDrawLineBezierCubic& LineBezierCubic) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineBezierCubic;
  Cmd.StartPos = StartPos;
  Cmd.EndPos = EndPos;
  Cmd.Position = StartControlPos;
  Cmd.Size = EndControlPos;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineBezierCubic.CommandID = ID;
  LineBezierCubic.StartPos = StartPos;
  LineBezierCubic.EndPos = EndPos;
  LineBezierCubic.StartControlPos = StartControlPos;
  LineBezierCubic.EndControlPos = EndControlPos;
  LineBezierCubic.Thick = Thick;
  LineBezierCubic.Color = Color;
}

FRlDrawLineBezierCubic URaylibUEBPLibrary::DrawLineBezierCubicUpdate(const FRlDrawLineBezierCubic& LineBezierCubic) {
  FRlDrawLineBezierCubic OutLineBezierCubic;
  if (LineBezierCubic.CommandID < 0) {
    OutLineBezierCubic.CommandID = -1;
    OutLineBezierCubic = FRlDrawLineBezierCubic();
    return OutLineBezierCubic;
  }

  OutLineBezierCubic = LineBezierCubic;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineBezierCubic;
  UpdateCmd.StartPos = LineBezierCubic.StartPos;
  UpdateCmd.EndPos = LineBezierCubic.EndPos;
  UpdateCmd.Position = LineBezierCubic.StartControlPos;
  UpdateCmd.Size = LineBezierCubic.EndControlPos;
  UpdateCmd.Thick = LineBezierCubic.Thick;
  UpdateCmd.Color = LineBezierCubic.Color;
  OutLineBezierCubic.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineBezierCubic.CommandID : -1; 
  return OutLineBezierCubic;
}

void URaylibUEBPLibrary::DrawLineStrip(const TArray<FIntPoint>& Points, FLinearColor Color, FRlDrawLineStrip& LineStrip) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLineStrip;
  Cmd.Points = Points;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  LineStrip.CommandID = ID;
  LineStrip.Points = Points;
  LineStrip.Color = Color;
}

FRlDrawLineStrip URaylibUEBPLibrary::DrawLineStripUpdate(const FRlDrawLineStrip& LineStrip) {
  FRlDrawLineStrip OutLineStrip;
  if (LineStrip.CommandID < 0) {
    OutLineStrip.CommandID = -1;
    OutLineStrip = FRlDrawLineStrip();
    return OutLineStrip;
  }

  OutLineStrip = LineStrip;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawLineStrip;
  UpdateCmd.Points = LineStrip.Points;
  UpdateCmd.Color = LineStrip.Color;
  OutLineStrip.CommandID = rlCmdBuf.Update(UpdateCmd) ? LineStrip.CommandID : -1; 
  return OutLineStrip;
}

void URaylibUEBPLibrary::DrawCircle(int32 CenterX, int32 CenterY, float Radius, FLinearColor Color, FRlDrawCircle& Circle) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircle;
  Cmd.Position = FIntPoint(CenterX, CenterY);
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Circle.CommandID = ID;
  Circle.CenterX = CenterX;
  Circle.CenterY = CenterY;
  Circle.Radius = Radius;
  Circle.Color = Color;
}

FRlDrawCircle URaylibUEBPLibrary::DrawCircleUpdate(const FRlDrawCircle& Circle) {
  FRlDrawCircle OutCircle;
  if (Circle.CommandID < 0) {
    OutCircle.CommandID = -1;
    OutCircle = FRlDrawCircle();
    return OutCircle;
  }

  OutCircle = Circle;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircle;
  UpdateCmd.Position = FIntPoint(Circle.CenterX, Circle.CenterY);
  UpdateCmd.Radius = Circle.Radius;
  UpdateCmd.Color = Circle.Color;
  OutCircle.CommandID = rlCmdBuf.Update(UpdateCmd) ? Circle.CommandID : -1; 
  return OutCircle;
}

void URaylibUEBPLibrary::DrawCircleSector(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawCircleSector& CircleSector) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleSector;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CircleSector.CommandID = ID;
  CircleSector.Center = Center;
  CircleSector.Radius = Radius;
  CircleSector.StartAngle = StartAngle;
  CircleSector.EndAngle = EndAngle;
  CircleSector.Segments = Segments;
  CircleSector.Color = Color;
}

FRlDrawCircleSector URaylibUEBPLibrary::DrawCircleSectorUpdate(const FRlDrawCircleSector& CircleSector) {
  FRlDrawCircleSector OutCircleSector;
  if (CircleSector.CommandID < 0) {
    OutCircleSector.CommandID = -1;
    OutCircleSector = FRlDrawCircleSector();
    return OutCircleSector;
  }

  OutCircleSector = CircleSector;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleSector;
  UpdateCmd.Position = CircleSector.Center;
  UpdateCmd.Radius = CircleSector.Radius;
  UpdateCmd.StartAngle = CircleSector.StartAngle;
  UpdateCmd.EndAngle = CircleSector.EndAngle;
  UpdateCmd.Segments = CircleSector.Segments;
  UpdateCmd.Color = CircleSector.Color;
  OutCircleSector.CommandID = rlCmdBuf.Update(UpdateCmd) ? CircleSector.CommandID : -1; 
  return OutCircleSector;
}

void URaylibUEBPLibrary::DrawCircleSectorLines(FIntPoint Center, float Radius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawCircleSectorLines& CircleSectorLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleSectorLines;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CircleSectorLines.CommandID = ID;
  CircleSectorLines.Center = Center;
  CircleSectorLines.Radius = Radius;
  CircleSectorLines.StartAngle = StartAngle;
  CircleSectorLines.EndAngle = EndAngle;
  CircleSectorLines.Segments = Segments;
  CircleSectorLines.Color = Color;
}

FRlDrawCircleSectorLines URaylibUEBPLibrary::DrawCircleSectorLinesUpdate(const FRlDrawCircleSectorLines& CircleSectorLines) {
  FRlDrawCircleSectorLines OutCircleSectorLines;
  if (CircleSectorLines.CommandID < 0) {
    OutCircleSectorLines.CommandID = -1;
    OutCircleSectorLines = FRlDrawCircleSectorLines();
    return OutCircleSectorLines;
  }

  OutCircleSectorLines = CircleSectorLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleSectorLines;
  UpdateCmd.Position = CircleSectorLines.Center;
  UpdateCmd.Radius = CircleSectorLines.Radius;
  UpdateCmd.StartAngle = CircleSectorLines.StartAngle;
  UpdateCmd.EndAngle = CircleSectorLines.EndAngle;
  UpdateCmd.Segments = CircleSectorLines.Segments;
  UpdateCmd.Color = CircleSectorLines.Color;
  OutCircleSectorLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? CircleSectorLines.CommandID : -1; 
  return OutCircleSectorLines;
}

void URaylibUEBPLibrary::DrawCircleGradient(FIntPoint Center, float Radius, FLinearColor Color1, FLinearColor Color2, FRlDrawCircleGradient& CircleGradient) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleGradient;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  int32 ID = rlCmdBuf.Add(Cmd);

  CircleGradient.CommandID = ID;
  CircleGradient.Center = Center;
  CircleGradient.Radius = Radius;
  CircleGradient.Color1 = Color1;
  CircleGradient.Color2 = Color2;
}

FRlDrawCircleGradient URaylibUEBPLibrary::DrawCircleGradientUpdate(const FRlDrawCircleGradient& CircleGradient) {
  FRlDrawCircleGradient OutCircleGradient;
  if (CircleGradient.CommandID < 0) {
    OutCircleGradient.CommandID = -1;
    OutCircleGradient = FRlDrawCircleGradient();
    return OutCircleGradient;
  }

  OutCircleGradient = CircleGradient;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleGradient;
  UpdateCmd.Position = CircleGradient.Center;
  UpdateCmd.Radius = CircleGradient.Radius;
  UpdateCmd.Color1 = CircleGradient.Color1;
  UpdateCmd.Color2 = CircleGradient.Color2;
  OutCircleGradient.CommandID = rlCmdBuf.Update(UpdateCmd) ? CircleGradient.CommandID : -1; 
  return OutCircleGradient;
}

void URaylibUEBPLibrary::DrawCircleV(FIntPoint Center, float Radius, FLinearColor Color, FRlDrawCircleV& CircleV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleV;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CircleV.CommandID = ID;
  CircleV.Center = Center;
  CircleV.Radius = Radius;
  CircleV.Color = Color;
}

FRlDrawCircleV URaylibUEBPLibrary::DrawCircleVUpdate(const FRlDrawCircleV& CircleV) {
  FRlDrawCircleV OutCircleV;
  if (CircleV.CommandID < 0) {
    OutCircleV.CommandID = -1;
    OutCircleV = FRlDrawCircleV();
    return OutCircleV;
  }

  OutCircleV = CircleV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleV;
  UpdateCmd.Position = CircleV.Center;
  UpdateCmd.Radius = CircleV.Radius;
  UpdateCmd.Color = CircleV.Color;
  OutCircleV.CommandID = rlCmdBuf.Update(UpdateCmd) ? CircleV.CommandID : -1; 
  return OutCircleV;
}

void URaylibUEBPLibrary::DrawCircleLines(FIntPoint Center, float Radius, FLinearColor Color, FRlDrawCircleLines& CircleLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircleLines;
  Cmd.Position = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CircleLines.CommandID = ID;
  CircleLines.Center = Center;
  CircleLines.Radius = Radius;
  CircleLines.Color = Color;
}

FRlDrawCircleLines URaylibUEBPLibrary::DrawCircleLinesUpdate(const FRlDrawCircleLines& CircleLines) {
  FRlDrawCircleLines OutCircleLines;
  if (CircleLines.CommandID < 0) {
    OutCircleLines.CommandID = -1;
    OutCircleLines = FRlDrawCircleLines();
    return OutCircleLines;
  }

  OutCircleLines = CircleLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCircleLines;
  UpdateCmd.Position = CircleLines.Center;
  UpdateCmd.Radius = CircleLines.Radius;
  UpdateCmd.Color = CircleLines.Color;
  OutCircleLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? CircleLines.CommandID : -1; 
  return OutCircleLines;
}

void URaylibUEBPLibrary::DrawEllipse(int32 CenterX, int32 CenterY, float RadiusH, float RadiusV, FLinearColor Color, FRlDrawEllipse& Ellipse) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawEllipse;
  Cmd.Position = FIntPoint(CenterX, CenterY);
  Cmd.Radius = RadiusH;
  Cmd.Size.X = (int32)RadiusV;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Ellipse.CommandID = ID;
  Ellipse.CenterX = CenterX;
  Ellipse.CenterY = CenterY;
  Ellipse.RadiusH = RadiusH;
  Ellipse.RadiusV = RadiusV;
  Ellipse.Color = Color;
}

FRlDrawEllipse URaylibUEBPLibrary::DrawEllipseUpdate(const FRlDrawEllipse& Ellipse) {
  FRlDrawEllipse OutEllipse;
  if (Ellipse.CommandID < 0) {
    OutEllipse.CommandID = -1;
    OutEllipse = FRlDrawEllipse();
    return OutEllipse;
  }

  OutEllipse = Ellipse;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawEllipse;
  UpdateCmd.Position = FIntPoint(Ellipse.CenterX, Ellipse.CenterY);
  UpdateCmd.Radius = Ellipse.RadiusH;
  UpdateCmd.Size.X = (int32)Ellipse.RadiusV;
  UpdateCmd.Color = Ellipse.Color;
  OutEllipse.CommandID = rlCmdBuf.Update(UpdateCmd) ? Ellipse.CommandID : -1; 
  return OutEllipse;
}

void URaylibUEBPLibrary::DrawEllipseLines(FIntPoint Center, float RadiusH, float RadiusV, FLinearColor Color, FRlDrawEllipseLines& EllipseLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawEllipseLines;
  Cmd.Position = Center;
  Cmd.Radius = RadiusH;
  Cmd.Size.X = (int32)RadiusV;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  EllipseLines.CommandID = ID;
  EllipseLines.Center = Center;
  EllipseLines.RadiusH = RadiusH;
  EllipseLines.RadiusV = RadiusV;
  EllipseLines.Color = Color;
}

FRlDrawEllipseLines URaylibUEBPLibrary::DrawEllipseLinesUpdate(const FRlDrawEllipseLines& EllipseLines) {
  FRlDrawEllipseLines OutEllipseLines;
  if (EllipseLines.CommandID < 0) {
    OutEllipseLines.CommandID = -1;
    OutEllipseLines = FRlDrawEllipseLines();
    return OutEllipseLines;
  }

  OutEllipseLines = EllipseLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawEllipseLines;
  UpdateCmd.Position = EllipseLines.Center;
  UpdateCmd.Radius = EllipseLines.RadiusH;
  UpdateCmd.Size.X = (int32)EllipseLines.RadiusV;
  UpdateCmd.Color = EllipseLines.Color;
  OutEllipseLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? EllipseLines.CommandID : -1; 
  return OutEllipseLines;
}

void URaylibUEBPLibrary::DrawRing(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawRing& Ring) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRing;
  Cmd.Position = Center;
  Cmd.Radius = OuterRadius;
  Cmd.Size.X = (int32)InnerRadius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Ring.CommandID = ID;
  Ring.Center = Center;
  Ring.InnerRadius = InnerRadius;
  Ring.OuterRadius = OuterRadius;
  Ring.StartAngle = StartAngle;
  Ring.EndAngle = EndAngle;
  Ring.Segments = Segments;
  Ring.Color = Color;
}

FRlDrawRing URaylibUEBPLibrary::DrawRingUpdate(const FRlDrawRing& Ring) {
  FRlDrawRing OutRing;
  if (Ring.CommandID < 0) {
    OutRing.CommandID = -1;
    OutRing = FRlDrawRing();
    return OutRing;
  }

  OutRing = Ring;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRing;
  UpdateCmd.Position = Ring.Center;
  UpdateCmd.Radius = Ring.OuterRadius;
  UpdateCmd.Size.X = (int32)Ring.InnerRadius;
  UpdateCmd.StartAngle = Ring.StartAngle;
  UpdateCmd.EndAngle = Ring.EndAngle;
  UpdateCmd.Segments = Ring.Segments;
  UpdateCmd.Color = Ring.Color;
  OutRing.CommandID = rlCmdBuf.Update(UpdateCmd) ? Ring.CommandID : -1; 
  return OutRing;
}

void URaylibUEBPLibrary::DrawRingLines(FIntPoint Center, float InnerRadius, float OuterRadius, float StartAngle, float EndAngle, int32 Segments, FLinearColor Color, FRlDrawRingLines& RingLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRingLines;
  Cmd.Position = Center;
  Cmd.Radius = OuterRadius;
  Cmd.Size.X = (int32)InnerRadius;
  Cmd.StartAngle = StartAngle;
  Cmd.EndAngle = EndAngle;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RingLines.CommandID = ID;
  RingLines.Center = Center;
  RingLines.InnerRadius = InnerRadius;
  RingLines.OuterRadius = OuterRadius;
  RingLines.StartAngle = StartAngle;
  RingLines.EndAngle = EndAngle;
  RingLines.Segments = Segments;
  RingLines.Color = Color;
}

FRlDrawRingLines URaylibUEBPLibrary::DrawRingLinesUpdate(const FRlDrawRingLines& RingLines) {
  FRlDrawRingLines OutRingLines;
  if (RingLines.CommandID < 0) {
    OutRingLines.CommandID = -1;
    OutRingLines = FRlDrawRingLines();
    return OutRingLines;
  }

  OutRingLines = RingLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRingLines;
  UpdateCmd.Position = RingLines.Center;
  UpdateCmd.Radius = RingLines.OuterRadius;
  UpdateCmd.Size.X = (int32)RingLines.InnerRadius;
  UpdateCmd.StartAngle = RingLines.StartAngle;
  UpdateCmd.EndAngle = RingLines.EndAngle;
  UpdateCmd.Segments = RingLines.Segments;
  UpdateCmd.Color = RingLines.Color;
  OutRingLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? RingLines.CommandID : -1; 
  return OutRingLines;
}

void URaylibUEBPLibrary::DrawRectangle(int32 PosX, int32 PosY, int32 Width, int32 Height, FLinearColor Color, FRlDrawRectangle& Rectangle) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangle;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Size = FIntPoint(Width, Height);
  Cmd.Color = Color;
  if (Cmd.Color.A == 0.f) Cmd.Color.A = 1.f;
  int32 ID = rlCmdBuf.Add(Cmd);
  Rectangle.CommandID = ID;
  Rectangle.PosX = PosX;
  Rectangle.PosY = PosY;
  Rectangle.Width = Width;
  Rectangle.Height = Height;
  Rectangle.Color = Color;
}

FRlDrawRectangle URaylibUEBPLibrary::DrawRectangleUpdate(const FRlDrawRectangle& Rectangle) {
  FRlDrawRectangle OutRectangle;
  if (Rectangle.CommandID < 0) {
    OutRectangle.CommandID = -1;
    OutRectangle = FRlDrawRectangle();
    return OutRectangle;
  }  OutRectangle = Rectangle;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Rectangle.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangle;
  UpdateCmd.Position = FIntPoint(Rectangle.PosX, Rectangle.PosY);
  UpdateCmd.Size = FIntPoint(Rectangle.Width, Rectangle.Height);
  UpdateCmd.Color = Rectangle.Color;
  OutRectangle.CommandID = rlCmdBuf.Update(UpdateCmd) ? OutRectangle.CommandID : -1; 
  return OutRectangle;
}



void URaylibUEBPLibrary::DrawRectangleV(FIntPoint Position, FIntPoint Size, FLinearColor Color, FRlDrawRectangleV& RectangleV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleV;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleV.CommandID = ID;
  RectangleV.Position = Position;
  RectangleV.Size = Size;
  RectangleV.Color = Color;
}

FRlDrawRectangleV URaylibUEBPLibrary::DrawRectangleVUpdate(const FRlDrawRectangleV& RectangleV) {
  FRlDrawRectangleV OutRectangleV;
  if (RectangleV.CommandID < 0) {
    OutRectangleV.CommandID = -1;
    OutRectangleV = FRlDrawRectangleV();
    return OutRectangleV;
  }

  OutRectangleV = RectangleV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleV;
  UpdateCmd.Position = RectangleV.Position;
  UpdateCmd.Size = RectangleV.Size;
  UpdateCmd.Color = RectangleV.Color;
  OutRectangleV.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleV.CommandID : -1; 
  return OutRectangleV;
}

void URaylibUEBPLibrary::DrawRectangleRec(FIntPoint Position, FIntPoint Size, FLinearColor Color, FRlDrawRectangleRec& RectangleRec) {
  FRlDrawRectangleV TempShape;
  DrawRectangleV(Position, Size, Color, TempShape);
  RectangleRec.CommandID = TempShape.CommandID;
  RectangleRec.Position = Position;
  RectangleRec.Size = Size;
  RectangleRec.Color = Color;
}

FRlDrawRectangleRec URaylibUEBPLibrary::DrawRectangleRecUpdate(const FRlDrawRectangleRec& RectangleRec) {
  FRlDrawRectangleRec OutRectangleRec;
  if (RectangleRec.CommandID < 0) {
    OutRectangleRec.CommandID = -1;
    OutRectangleRec = FRlDrawRectangleRec();
    return OutRectangleRec;
  }

  OutRectangleRec = RectangleRec;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectangleRec.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRec;
  UpdateCmd.Position = RectangleRec.Position;
  UpdateCmd.Size = RectangleRec.Size;
  UpdateCmd.Color = RectangleRec.Color;
  OutRectangleRec.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleRec.CommandID : -1; 
  return OutRectangleRec;
}

void URaylibUEBPLibrary::DrawRectanglePro(FIntPoint Position, FIntPoint Size, FIntPoint Origin, float Rotation, FLinearColor Color, FRlDrawRectanglePro& RectanglePro) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectanglePro;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectanglePro.CommandID = ID;
  RectanglePro.Position = Position;
  RectanglePro.Size = Size;
  RectanglePro.Origin = Origin;
  RectanglePro.Rotation = Rotation;
  RectanglePro.Color = Color;
}

FRlDrawRectanglePro URaylibUEBPLibrary::DrawRectangleProUpdate(const FRlDrawRectanglePro& RectanglePro) {
  FRlDrawRectanglePro OutRectanglePro;
  if (RectanglePro.CommandID < 0) {
    OutRectanglePro.CommandID = -1;
    OutRectanglePro = FRlDrawRectanglePro();
    return OutRectanglePro;
  }

  OutRectanglePro = RectanglePro;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectanglePro.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectanglePro;
  UpdateCmd.Position = RectanglePro.Position;
  UpdateCmd.Size = RectanglePro.Size;
  UpdateCmd.StartPos = RectanglePro.Origin;
  UpdateCmd.Rotation = RectanglePro.Rotation;
  UpdateCmd.Color = RectanglePro.Color;
  OutRectanglePro.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectanglePro.CommandID : -1; 
  return OutRectanglePro;
}

void URaylibUEBPLibrary::DrawRectangleGradientV(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, FRlDrawRectangleGradientV& RectangleGradientV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientV;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleGradientV.CommandID = ID;
  RectangleGradientV.Position = Position;
  RectangleGradientV.Size = Size;
  RectangleGradientV.Color1 = Color1;
  RectangleGradientV.Color2 = Color2;
}

FRlDrawRectangleGradientV URaylibUEBPLibrary::DrawRectangleGradientVUpdate(const FRlDrawRectangleGradientV& RectangleGradientV) {
  FRlDrawRectangleGradientV OutRectangleGradientV;
  if (RectangleGradientV.CommandID < 0) {
    OutRectangleGradientV.CommandID = -1;
    OutRectangleGradientV = FRlDrawRectangleGradientV();
    return OutRectangleGradientV;
  }

  OutRectangleGradientV = RectangleGradientV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectangleGradientV.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientV;
  UpdateCmd.Position = RectangleGradientV.Position;
  UpdateCmd.Size = RectangleGradientV.Size;
  UpdateCmd.Color1 = RectangleGradientV.Color1;
  UpdateCmd.Color2 = RectangleGradientV.Color2;
  OutRectangleGradientV.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleGradientV.CommandID : -1; 
  return OutRectangleGradientV;
}

void URaylibUEBPLibrary::DrawRectangleGradientH(FIntPoint Position, FIntPoint Size, FLinearColor Color1, FLinearColor Color2, FRlDrawRectangleGradientH& RectangleGradientH) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientH;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Color1 = Color1;
  Cmd.Color2 = Color2;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleGradientH.CommandID = ID;
  RectangleGradientH.Position = Position;
  RectangleGradientH.Size = Size;
  RectangleGradientH.Color1 = Color1;
  RectangleGradientH.Color2 = Color2;
}

FRlDrawRectangleGradientH URaylibUEBPLibrary::DrawRectangleGradientHUpdate(const FRlDrawRectangleGradientH& RectangleGradientH) {
  FRlDrawRectangleGradientH OutRectangleGradientH;
  if (RectangleGradientH.CommandID < 0) {
    OutRectangleGradientH.CommandID = -1;
    OutRectangleGradientH = FRlDrawRectangleGradientH();
    return OutRectangleGradientH;
  }

  OutRectangleGradientH = RectangleGradientH;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectangleGradientH.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientH;
  UpdateCmd.Position = RectangleGradientH.Position;
  UpdateCmd.Size = RectangleGradientH.Size;
  UpdateCmd.Color1 = RectangleGradientH.Color1;
  UpdateCmd.Color2 = RectangleGradientH.Color2;
  OutRectangleGradientH.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleGradientH.CommandID : -1; 
  return OutRectangleGradientH;
}

void URaylibUEBPLibrary::DrawRectangleGradientEx(FIntPoint TopLeft, FIntPoint TopRight, FIntPoint BottomRight, FIntPoint BottomLeft, FRlDrawRectangleGradientEx& RectangleGradientEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleGradientEx;
  Cmd.Position = TopLeft;
  Cmd.StartPos = TopRight;
  Cmd.EndPos = BottomRight;
  Cmd.Size = BottomLeft;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleGradientEx.CommandID = ID;
  RectangleGradientEx.TopLeft = TopLeft;
  RectangleGradientEx.TopRight = TopRight;
  RectangleGradientEx.BottomRight = BottomRight;
  RectangleGradientEx.BottomLeft = BottomLeft;
}

FRlDrawRectangleGradientEx URaylibUEBPLibrary::DrawRectangleGradientExUpdate(const FRlDrawRectangleGradientEx& RectangleGradientEx) {
  FRlDrawRectangleGradientEx OutRectangleGradientEx;
  if (RectangleGradientEx.CommandID < 0) {
    OutRectangleGradientEx.CommandID = -1;
    OutRectangleGradientEx = FRlDrawRectangleGradientEx();
    return OutRectangleGradientEx;
  }

  OutRectangleGradientEx = RectangleGradientEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectangleGradientEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangleGradientEx;
  UpdateCmd.CommandID = RectangleGradientEx.CommandID;
  UpdateCmd.Position = RectangleGradientEx.TopLeft;
  UpdateCmd.StartPos = RectangleGradientEx.TopRight;
  UpdateCmd.EndPos = RectangleGradientEx.BottomRight;
  UpdateCmd.Size = RectangleGradientEx.BottomLeft;
  OutRectangleGradientEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleGradientEx.CommandID : -1; 
  return OutRectangleGradientEx;
}

void URaylibUEBPLibrary::DrawRectangleLines(FIntPoint Position, FIntPoint Size, int32 LineThick, FLinearColor Color, FRlDrawRectangleLines& RectangleLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleLines;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleLines.CommandID = ID;
  RectangleLines.Position = Position;
  RectangleLines.Size = Size;
  RectangleLines.LineThick = LineThick;
  RectangleLines.Color = Color;
}

FRlDrawRectangleLines URaylibUEBPLibrary::DrawRectangleLinesUpdate(const FRlDrawRectangleLines& RectangleLines) {
  FRlDrawRectangleLines OutRectangleLines;
  if (RectangleLines.CommandID < 0) {
    OutRectangleLines.CommandID = -1;
    OutRectangleLines = FRlDrawRectangleLines();
    return OutRectangleLines;
  }

  OutRectangleLines = RectangleLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleLines;
  UpdateCmd.Position = RectangleLines.Position;
  UpdateCmd.Size = RectangleLines.Size;
  UpdateCmd.Thick = RectangleLines.LineThick;
  UpdateCmd.Color = RectangleLines.Color;
  OutRectangleLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleLines.CommandID : -1; 
  return OutRectangleLines;
}

void URaylibUEBPLibrary::DrawRectangleLinesEx(FIntPoint Position, FIntPoint Size, float LineThick, FLinearColor Color, FRlDrawRectangleLinesEx& RectangleLinesEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleLinesEx;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleLinesEx.CommandID = ID;
  RectangleLinesEx.Position = Position;
  RectangleLinesEx.Size = Size;
  RectangleLinesEx.LineThick = LineThick;
  RectangleLinesEx.Color = Color;
}

FRlDrawRectangleLinesEx URaylibUEBPLibrary::DrawRectangleLinesExUpdate(const FRlDrawRectangleLinesEx& RectangleLinesEx) {
  FRlDrawRectangleLinesEx OutRectangleLinesEx;
  if (RectangleLinesEx.CommandID < 0) {
    OutRectangleLinesEx.CommandID = -1;
    OutRectangleLinesEx = FRlDrawRectangleLinesEx();
    return OutRectangleLinesEx;
  }

  OutRectangleLinesEx = RectangleLinesEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleLinesEx;
  UpdateCmd.Position = RectangleLinesEx.Position;
  UpdateCmd.Size = RectangleLinesEx.Size;
  UpdateCmd.Thick = RectangleLinesEx.LineThick;
  UpdateCmd.Color = RectangleLinesEx.Color;
  OutRectangleLinesEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleLinesEx.CommandID : -1; 
  return OutRectangleLinesEx;
}

void URaylibUEBPLibrary::DrawRectangleRounded(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, FLinearColor Color, FRlDrawRectangleRounded& RectangleRounded) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleRounded;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Roundness = Roundness;
  Cmd.Segments = Segments;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleRounded.CommandID = ID;
  RectangleRounded.Position = Position;
  RectangleRounded.Size = Size;
  RectangleRounded.Roundness = Roundness;
  RectangleRounded.Segments = Segments;
  RectangleRounded.Color = Color;
}

FRlDrawRectangleRounded URaylibUEBPLibrary::DrawRectangleRoundedUpdate(const FRlDrawRectangleRounded& RectangleRounded) {
  FRlDrawRectangleRounded OutRectangleRounded;
  if (RectangleRounded.CommandID < 0) {
    OutRectangleRounded.CommandID = -1;
    OutRectangleRounded = FRlDrawRectangleRounded();
    return OutRectangleRounded;
  }

  OutRectangleRounded = RectangleRounded;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRounded;
  UpdateCmd.Position = RectangleRounded.Position;
  UpdateCmd.Size = RectangleRounded.Size;
  UpdateCmd.Roundness = RectangleRounded.Roundness;
  UpdateCmd.Segments = RectangleRounded.Segments;
  UpdateCmd.Color = RectangleRounded.Color;
  OutRectangleRounded.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleRounded.CommandID : -1; 
  return OutRectangleRounded;
}

void URaylibUEBPLibrary::DrawRectangleRoundedLines(FIntPoint Position, FIntPoint Size, float Roundness, int32 Segments, int32 LineThick, FLinearColor Color, FRlDrawRectangleRoundedLines& RectangleRoundedLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRectangleRoundedLines;
  Cmd.Position = Position;
  Cmd.Size = Size;
  Cmd.Roundness = Roundness;
  Cmd.Segments = Segments;
  Cmd.Thick = LineThick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  RectangleRoundedLines.CommandID = ID;
  RectangleRoundedLines.Position = Position;
  RectangleRoundedLines.Size = Size;
  RectangleRoundedLines.Roundness = Roundness;
  RectangleRoundedLines.Segments = Segments;
  RectangleRoundedLines.LineThick = LineThick;
  RectangleRoundedLines.Color = Color;
}

FRlDrawRectangleRoundedLines URaylibUEBPLibrary::DrawRectangleRoundedLinesUpdate(const FRlDrawRectangleRoundedLines& RectangleRoundedLines) {
  FRlDrawRectangleRoundedLines OutRectangleRoundedLines;
  if (RectangleRoundedLines.CommandID < 0) {
    OutRectangleRoundedLines.CommandID = -1;
    OutRectangleRoundedLines = FRlDrawRectangleRoundedLines();
    return OutRectangleRoundedLines;
  }

  OutRectangleRoundedLines = RectangleRoundedLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = RectangleRoundedLines.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRectangleRoundedLines;
  UpdateCmd.Position = RectangleRoundedLines.Position;
  UpdateCmd.Size = RectangleRoundedLines.Size;
  UpdateCmd.Roundness = RectangleRoundedLines.Roundness;
  UpdateCmd.Segments = RectangleRoundedLines.Segments;
  UpdateCmd.Thick = RectangleRoundedLines.LineThick;
  UpdateCmd.Color = RectangleRoundedLines.Color;
  OutRectangleRoundedLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? RectangleRoundedLines.CommandID : -1; 
  return OutRectangleRoundedLines;
}

void URaylibUEBPLibrary::DrawTriangle(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, FRlDrawTriangle& Triangle) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangle;
  Cmd.Points = {V1, V2, V3};
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Triangle.CommandID = ID;
  Triangle.V1 = V1;
  Triangle.V2 = V2;
  Triangle.V3 = V3;
  Triangle.Color = Color;
}

FRlDrawTriangle URaylibUEBPLibrary::DrawTriangleUpdate(const FRlDrawTriangle& Triangle) {
  FRlDrawTriangle OutTriangle;
  if (Triangle.CommandID < 0) {
    OutTriangle.CommandID = -1;
    OutTriangle = FRlDrawTriangle();
    return OutTriangle;
  }

  OutTriangle = Triangle;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Triangle.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTriangle;
  UpdateCmd.Points = {Triangle.V1, Triangle.V2, Triangle.V3};
  UpdateCmd.Color = Triangle.Color;
  OutTriangle.CommandID = rlCmdBuf.Update(UpdateCmd) ? Triangle.CommandID : -1; 
  return OutTriangle;
}

void URaylibUEBPLibrary::DrawTriangleLines(FIntPoint V1, FIntPoint V2, FIntPoint V3, FLinearColor Color, FRlDrawTriangleLines& TriangleLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangleLines;
  Cmd.Points = {V1, V2, V3};
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TriangleLines.CommandID = ID;
  TriangleLines.V1 = V1;
  TriangleLines.V2 = V2;
  TriangleLines.V3 = V3;
  TriangleLines.Color = Color;
}

FRlDrawTriangleLines URaylibUEBPLibrary::DrawTriangleLinesUpdate(const FRlDrawTriangleLines& TriangleLines) {
  FRlDrawTriangleLines OutTriangleLines;
  if (TriangleLines.CommandID < 0) {
    OutTriangleLines.CommandID = -1;
    OutTriangleLines = FRlDrawTriangleLines();
    return OutTriangleLines;
  }

  OutTriangleLines = TriangleLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TriangleLines.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTriangleLines;
  UpdateCmd.Points = {TriangleLines.V1, TriangleLines.V2, TriangleLines.V3};
  UpdateCmd.Color = TriangleLines.Color;
  OutTriangleLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? TriangleLines.CommandID : -1; 
  return OutTriangleLines;
}

void URaylibUEBPLibrary::DrawPoly(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, FRlDrawPoly& Poly) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPoly;
  Cmd.Position = Center;
  Cmd.Sides = Sides;
  Cmd.Radius = Radius;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Poly.Center = Center;
  Poly.Sides = Sides;
  Poly.Radius = Radius;
  Poly.Rotation = Rotation;
  Poly.Color = Color;
  Poly.CommandID = ID;
}

FRlDrawPoly URaylibUEBPLibrary::DrawPolyUpdate(const FRlDrawPoly& Poly) {
  FRlDrawPoly OutPoly;
  if (Poly.CommandID < 0) {
    OutPoly.CommandID = -1;
    OutPoly = FRlDrawPoly();
    return OutPoly;
  }

  OutPoly = Poly;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPoly;
  UpdateCmd.Position = Poly.Center;
  UpdateCmd.Sides = Poly.Sides;
  UpdateCmd.Radius = Poly.Radius;
  UpdateCmd.Rotation = Poly.Rotation;
  UpdateCmd.Color = Poly.Color;
  OutPoly.CommandID = rlCmdBuf.Update(UpdateCmd) ? Poly.CommandID : -1; 
  return OutPoly;
}

void URaylibUEBPLibrary::DrawPolyLines(FIntPoint Center, int32 Sides, float Radius, float Rotation, FLinearColor Color, FRlDrawPolyLines& PolyLines) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPolyLines;
  Cmd.Position = Center;
  Cmd.Sides = Sides;
  Cmd.Radius = Radius;
  Cmd.Rotation = Rotation;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  PolyLines.Center = Center;
  PolyLines.Sides = Sides;
  PolyLines.Radius = Radius;
  PolyLines.Rotation = Rotation;
  PolyLines.Color = Color;
  PolyLines.CommandID = ID;
}

FRlDrawPolyLines URaylibUEBPLibrary::DrawPolyLinesUpdate(const FRlDrawPolyLines& PolyLines) {
  FRlDrawPolyLines OutPolyLines;
  if (PolyLines.CommandID < 0) {
    OutPolyLines.CommandID = -1;
    OutPolyLines = FRlDrawPolyLines();
    return OutPolyLines;
  }

  OutPolyLines = PolyLines;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPolyLines;
  UpdateCmd.Position = PolyLines.Center;
  UpdateCmd.Sides = PolyLines.Sides;
  UpdateCmd.Radius = PolyLines.Radius;
  UpdateCmd.Rotation = PolyLines.Rotation;
  UpdateCmd.Color = PolyLines.Color;
  OutPolyLines.CommandID = rlCmdBuf.Update(UpdateCmd) ? PolyLines.CommandID : -1; 
  return OutPolyLines;
}

void URaylibUEBPLibrary::DrawPolyLinesEx(const TArray<FIntPoint>& Points, float Thick, FLinearColor Color, FRlDrawPolyLinesEx& PolyLinesEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPolyLinesEx;
  Cmd.Points = Points;
  Cmd.Thick = Thick;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  PolyLinesEx.CommandID = ID;
  PolyLinesEx.Points = Points;
  PolyLinesEx.Thick = Thick;
  PolyLinesEx.Color = Color;
}

FRlDrawPolyLinesEx URaylibUEBPLibrary::DrawPolyLinesExUpdate(const FRlDrawPolyLinesEx& PolyLinesEx) {
  FRlDrawPolyLinesEx OutPolyLinesEx;
  if (PolyLinesEx.CommandID < 0) {
    OutPolyLinesEx.CommandID = -1;
    OutPolyLinesEx = FRlDrawPolyLinesEx();
    return OutPolyLinesEx;
  }

  OutPolyLinesEx = PolyLinesEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawPolyLinesEx;
  UpdateCmd.Points = PolyLinesEx.Points;
  UpdateCmd.Thick = PolyLinesEx.Thick;
  UpdateCmd.Color = PolyLinesEx.Color;
  OutPolyLinesEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? PolyLinesEx.CommandID : -1; 
  return OutPolyLinesEx;
}

void URaylibUEBPLibrary::DrawFPS(int32 PosX, int32 PosY, FRlDrawFPS& FPS) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawFPS;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = FLinearColor::White;
  int32 ID = rlCmdBuf.Add(Cmd);

  FPS.CommandID = ID;
  FPS.PosX = PosX;
  FPS.PosY = PosY;
}

FRlDrawFPS URaylibUEBPLibrary::DrawFPSUpdate(const FRlDrawFPS& FPS) {
  FRlDrawFPS OutFPS;
  if (FPS.CommandID < 0) {
    OutFPS.CommandID = -1;
    OutFPS = FRlDrawFPS();
    return OutFPS;
  }

  OutFPS = FPS;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawFPS;
  UpdateCmd.Position = FIntPoint(FPS.PosX, FPS.PosY);
  UpdateCmd.Color = FLinearColor::White;
  OutFPS.CommandID = rlCmdBuf.Update(UpdateCmd) ? FPS.CommandID : -1; 
  return OutFPS;
}

void URaylibUEBPLibrary::DrawText(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, FRlDrawText& TextShape) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawText;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Text = Text;
  Cmd.FontSize = FontSize;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextShape.CommandID = ID;
  TextShape.Text = Text;
  TextShape.PosX = PosX;
  TextShape.PosY = PosY;
  TextShape.FontSize = FontSize;
  TextShape.Color = Color;
}

FRlDrawText URaylibUEBPLibrary::DrawTextUpdate(const FRlDrawText& TextShape) {
  FRlDrawText OutTextShape;
  if (TextShape.CommandID < 0) {
    OutTextShape.CommandID = -1;
    OutTextShape = FRlDrawText();
    return OutTextShape;
  }

  OutTextShape = TextShape;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextShape.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawText;
  UpdateCmd.Position = FIntPoint(TextShape.PosX, TextShape.PosY);
  UpdateCmd.Text = TextShape.Text;
  UpdateCmd.FontSize = TextShape.FontSize;
  UpdateCmd.Color = TextShape.Color;
  OutTextShape.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextShape.CommandID : -1; 
  return OutTextShape;
}

void URaylibUEBPLibrary::DrawTextEx(const FString& Text, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, FRlDrawTextEx& TextEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextEx;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Text = Text;
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextEx.CommandID = ID;
  TextEx.Text = Text;
  TextEx.PosX = PosX;
  TextEx.PosY = PosY;
  TextEx.FontSize = FontSize;
  TextEx.Spacing = Spacing;
  TextEx.Color = Color;
}

FRlDrawTextEx URaylibUEBPLibrary::DrawTextExUpdate(const FRlDrawTextEx& TextEx) {
  FRlDrawTextEx OutTextEx;
  if (TextEx.CommandID < 0) {
    OutTextEx.CommandID = -1;
    OutTextEx = FRlDrawTextEx();
    return OutTextEx;
  }

  OutTextEx = TextEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextEx;
  UpdateCmd.Position = FIntPoint(TextEx.PosX, TextEx.PosY);
  UpdateCmd.Text = TextEx.Text;
  UpdateCmd.FontSize = TextEx.FontSize;
  UpdateCmd.Spacing = TextEx.Spacing;
  UpdateCmd.Color = TextEx.Color;
  OutTextEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextEx.CommandID : -1; 
  return OutTextEx;
}

void URaylibUEBPLibrary::DrawTextPro(const FString& Text, FIntPoint Position, FIntPoint Origin, float Rotation, float FontSize, float Spacing, FLinearColor Color, FRlDrawTextPro& TextPro) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextPro;
  Cmd.Position = Position;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Text = Text;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextPro.CommandID = ID;
  TextPro.Text = Text;
  TextPro.Position = Position;
  TextPro.Origin = Origin;
  TextPro.Rotation = Rotation;
  TextPro.FontSize = FontSize;
  TextPro.Spacing = Spacing;
  TextPro.Color = Color;
}

FRlDrawTextPro URaylibUEBPLibrary::DrawTextProUpdate(const FRlDrawTextPro& TextPro) {
  FRlDrawTextPro OutTextPro;
  if (TextPro.CommandID < 0) {
    OutTextPro.CommandID = -1;
    OutTextPro = FRlDrawTextPro();
    return OutTextPro;
  }

  OutTextPro = TextPro;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextPro.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextPro;
  UpdateCmd.Position = TextPro.Position;
  UpdateCmd.StartPos = TextPro.Origin;
  UpdateCmd.Rotation = TextPro.Rotation;
  UpdateCmd.FontSize = TextPro.FontSize;
  UpdateCmd.Spacing = TextPro.Spacing;
  UpdateCmd.Text = TextPro.Text;
  UpdateCmd.Color = TextPro.Color;
  OutTextPro.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextPro.CommandID : -1; 
  return OutTextPro;
}

void URaylibUEBPLibrary::DrawTextCodepoint(int32 Codepoint, int32 PosX, int32 PosY, int32 FontSize, FLinearColor Color, FRlDrawTextCodepoint& TextCodepoint) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextCodepoint;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.FontSize = FontSize;
  Cmd.Codepoints = {Codepoint};
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextCodepoint.CommandID = ID;
  TextCodepoint.Codepoint = Codepoint;
  TextCodepoint.PosX = PosX;
  TextCodepoint.PosY = PosY;
  TextCodepoint.FontSize = FontSize;
  TextCodepoint.Color = Color;
}

FRlDrawTextCodepoint URaylibUEBPLibrary::DrawTextCodepointUpdate(const FRlDrawTextCodepoint& TextCodepoint) {
  FRlDrawTextCodepoint OutTextCodepoint;
  if (TextCodepoint.CommandID < 0) {
    OutTextCodepoint.CommandID = -1;
    OutTextCodepoint = FRlDrawTextCodepoint();
    return OutTextCodepoint;
  }

  OutTextCodepoint = TextCodepoint;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextCodepoint.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextCodepoint;
  UpdateCmd.Position = FIntPoint(TextCodepoint.PosX, TextCodepoint.PosY);
  UpdateCmd.FontSize = TextCodepoint.FontSize;
  UpdateCmd.Codepoints = {TextCodepoint.Codepoint};
  UpdateCmd.Color = TextCodepoint.Color;
  OutTextCodepoint.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextCodepoint.CommandID : -1; 
  return OutTextCodepoint;
}

void URaylibUEBPLibrary::DrawTextCodepoints(const TArray<int32>& Codepoints, int32 PosX, int32 PosY, int32 FontSize, float Spacing, FLinearColor Color, FRlDrawTextCodepoints& TextCodepoints) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextCodepoints;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.FontSize = FontSize;
  Cmd.Spacing = Spacing;
  Cmd.Codepoints = Codepoints;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextCodepoints.CommandID = ID;
  TextCodepoints.Codepoints = Codepoints;
  TextCodepoints.PosX = PosX;
  TextCodepoints.PosY = PosY;
  TextCodepoints.FontSize = FontSize;
  TextCodepoints.Spacing = Spacing;
  TextCodepoints.Color = Color;
}

FRlDrawTextCodepoints URaylibUEBPLibrary::DrawTextCodepointsUpdate(const FRlDrawTextCodepoints& TextCodepoints) {
  FRlDrawTextCodepoints OutTextCodepoints;
  if (TextCodepoints.CommandID < 0) {
    OutTextCodepoints.CommandID = -1;
    OutTextCodepoints = FRlDrawTextCodepoints();
    return OutTextCodepoints;
  }

  OutTextCodepoints = TextCodepoints;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextCodepoints.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextCodepoints;
  UpdateCmd.Position = FIntPoint(TextCodepoints.PosX, TextCodepoints.PosY);
  UpdateCmd.FontSize = TextCodepoints.FontSize;
  UpdateCmd.Spacing = TextCodepoints.Spacing;
  UpdateCmd.Codepoints = TextCodepoints.Codepoints;
  UpdateCmd.Color = TextCodepoints.Color;
  OutTextCodepoints.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextCodepoints.CommandID : -1; 
  return OutTextCodepoints;
}

void URaylibUEBPLibrary::DrawLine3D(FVector StartPos, FVector EndPos, FLinearColor Color, FRlDrawLine3D& Line3D) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawLine3D;
  Cmd.Position3D = StartPos;
  Cmd.Origin3D = EndPos;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Line3D.CommandID = ID;
  Line3D.StartPos = StartPos;
  Line3D.EndPos = EndPos;
  Line3D.Color = Color;
}

FRlDrawLine3D URaylibUEBPLibrary::DrawLine3DUpdate(const FRlDrawLine3D& Line3D) {
  FRlDrawLine3D OutLine3D;
  if (Line3D.CommandID < 0) {
    OutLine3D.CommandID = -1;
    OutLine3D = FRlDrawLine3D();
    return OutLine3D;
  }

  OutLine3D = Line3D;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Line3D.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawLine3D;
  UpdateCmd.Position3D = Line3D.StartPos;
  UpdateCmd.Origin3D = Line3D.EndPos;
  UpdateCmd.Color = Line3D.Color;
  OutLine3D.CommandID = rlCmdBuf.Update(UpdateCmd) ? Line3D.CommandID : -1; 
  return OutLine3D;
}

void URaylibUEBPLibrary::DrawPoint3D(FVector Position, FLinearColor Color, FRlDrawPoint3D& Point3D) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPoint3D;
  Cmd.Position3D = Position;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Point3D.CommandID = ID;
  Point3D.Position = Position;
  Point3D.Color = Color;
}

FRlDrawPoint3D URaylibUEBPLibrary::DrawPoint3DUpdate(const FRlDrawPoint3D& Point3D) {
  FRlDrawPoint3D OutPoint3D;
  if (Point3D.CommandID < 0) {
    OutPoint3D.CommandID = -1;
    OutPoint3D = FRlDrawPoint3D();
    return OutPoint3D;
  }

  OutPoint3D = Point3D;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Point3D.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawPoint3D;
  UpdateCmd.Position3D = Point3D.Position;
  UpdateCmd.Color = Point3D.Color;
  OutPoint3D.CommandID = rlCmdBuf.Update(UpdateCmd) ? Point3D.CommandID : -1; 
  return OutPoint3D;
}

void URaylibUEBPLibrary::DrawCircle3D(FVector Center, float Radius, FVector RotationAxis, float RotationAngle, FLinearColor Color, FRlDrawCircle3D& Circle3D) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCircle3D;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Circle3D.CommandID = ID;
  Circle3D.Center = Center;
  Circle3D.Radius = Radius;
  Circle3D.RotationAxis = RotationAxis;
  Circle3D.RotationAngle = RotationAngle;
  Circle3D.Color = Color;
}

FRlDrawCircle3D URaylibUEBPLibrary::DrawCircle3DUpdate(const FRlDrawCircle3D& Circle3D) {
  FRlDrawCircle3D OutCircle3D;
  if (Circle3D.CommandID < 0) {
    OutCircle3D.CommandID = -1;
    OutCircle3D = FRlDrawCircle3D();
    return OutCircle3D;
  }

  OutCircle3D = Circle3D;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Circle3D.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCircle3D;
  UpdateCmd.Position3D = Circle3D.Center;
  UpdateCmd.Radius = Circle3D.Radius;
  UpdateCmd.RotationAxis = Circle3D.RotationAxis;
  UpdateCmd.RotationAngle = Circle3D.RotationAngle;
  UpdateCmd.Color = Circle3D.Color;
  OutCircle3D.CommandID = rlCmdBuf.Update(UpdateCmd) ? Circle3D.CommandID : -1; 
  return OutCircle3D;
}

void URaylibUEBPLibrary::DrawTriangle3D(FVector V1, FVector V2, FVector V3, FLinearColor Color, FRlDrawTriangle3D& Triangle3D) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangle3D;
  Cmd.Points3D = {V1, V2, V3};
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Triangle3D.CommandID = ID;
  Triangle3D.V1 = V1;
  Triangle3D.V2 = V2;
  Triangle3D.V3 = V3;
  Triangle3D.Color = Color;
}

FRlDrawTriangle3D URaylibUEBPLibrary::DrawTriangle3DUpdate(const FRlDrawTriangle3D& Triangle3D) {
  FRlDrawTriangle3D OutTriangle3D;
  if (Triangle3D.CommandID < 0) {
    OutTriangle3D.CommandID = -1;
    OutTriangle3D = FRlDrawTriangle3D();
    return OutTriangle3D;
  }

  OutTriangle3D = Triangle3D;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Triangle3D.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTriangle3D;
  UpdateCmd.Points3D = {Triangle3D.V1, Triangle3D.V2, Triangle3D.V3};
  UpdateCmd.Color = Triangle3D.Color;
  OutTriangle3D.CommandID = rlCmdBuf.Update(UpdateCmd) ? Triangle3D.CommandID : -1; 
  return OutTriangle3D;
}

void URaylibUEBPLibrary::DrawTriangleStrip3D(const TArray<FVector>& Points, FLinearColor Color, FRlDrawTriangleStrip3D& TriangleStrip3D) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTriangleStrip3D;
  Cmd.Points3D = Points;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  TriangleStrip3D.CommandID = ID;
  TriangleStrip3D.Points = Points;
  TriangleStrip3D.Color = Color;
}

FRlDrawTriangleStrip3D URaylibUEBPLibrary::DrawTriangleStrip3DUpdate(const FRlDrawTriangleStrip3D& TriangleStrip3D) {
  FRlDrawTriangleStrip3D OutTriangleStrip3D;
  if (TriangleStrip3D.CommandID < 0) {
    OutTriangleStrip3D.CommandID = -1;
    OutTriangleStrip3D = FRlDrawTriangleStrip3D();
    return OutTriangleStrip3D;
  }

  OutTriangleStrip3D = TriangleStrip3D;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TriangleStrip3D.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTriangleStrip3D;
  UpdateCmd.Points3D = TriangleStrip3D.Points;
  UpdateCmd.Color = TriangleStrip3D.Color;
  OutTriangleStrip3D.CommandID = rlCmdBuf.Update(UpdateCmd) ? TriangleStrip3D.CommandID : -1; 
  return OutTriangleStrip3D;
}

void URaylibUEBPLibrary::DrawCube(FVector Position, float Width, float Height, float Length, FLinearColor Color, FRlDrawCube& Cube) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCube;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Width, Height, Length);
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Cube.CommandID = ID;
  Cube.Position = Position;
  Cube.Width = Width;
  Cube.Height = Height;
  Cube.Length = Length;
  Cube.Color = Color;
}

FRlDrawCube URaylibUEBPLibrary::DrawCubeUpdate(const FRlDrawCube& Cube) {
  FRlDrawCube OutCube;
  if (Cube.CommandID < 0) {
    OutCube.CommandID = -1;
    OutCube = FRlDrawCube();
    return OutCube;
  }

  OutCube = Cube;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCube;
  UpdateCmd.Position3D = Cube.Position;
  UpdateCmd.Scale3D = FVector(Cube.Width, Cube.Height, Cube.Length);
  UpdateCmd.Color = Cube.Color;
  OutCube.CommandID = rlCmdBuf.Update(UpdateCmd) ? Cube.CommandID : -1; 
  return OutCube;
}

void URaylibUEBPLibrary::DrawCubeV(FVector Position, FVector Size, FLinearColor Color, FRlDrawCubeV& CubeV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeV;
  Cmd.Position3D = Position;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CubeV.CommandID = ID;
  CubeV.Position = Position;
  CubeV.Size = Size;
  CubeV.Color = Color;
}

FRlDrawCubeV URaylibUEBPLibrary::DrawCubeVUpdate(const FRlDrawCubeV& CubeV) {
  FRlDrawCubeV OutCubeV;
  if (CubeV.CommandID < 0) {
    OutCubeV.CommandID = -1;
    OutCubeV = FRlDrawCubeV();
    return OutCubeV;
  }

  OutCubeV = CubeV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeV;
  UpdateCmd.Position3D = CubeV.Position;
  UpdateCmd.Scale3D = CubeV.Size;
  UpdateCmd.Color = CubeV.Color;
  OutCubeV.CommandID = rlCmdBuf.Update(UpdateCmd) ? CubeV.CommandID : -1; 
  return OutCubeV;
}

void URaylibUEBPLibrary::DrawCubeWires(FVector Position, float Width, float Height, float Length, FLinearColor Color, FRlDrawCubeWires& CubeWires) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeWires;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Width, Height, Length);
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CubeWires.CommandID = ID;
  CubeWires.Position = Position;
  CubeWires.Width = Width;
  CubeWires.Height = Height;
  CubeWires.Length = Length;
  CubeWires.Color = Color;
}

FRlDrawCubeWires URaylibUEBPLibrary::DrawCubeWiresUpdate(const FRlDrawCubeWires& CubeWires) {
  FRlDrawCubeWires OutCubeWires;
  if (CubeWires.CommandID < 0) {
    OutCubeWires.CommandID = -1;
    OutCubeWires = FRlDrawCubeWires();
    return OutCubeWires;
  }

  OutCubeWires = CubeWires;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeWires;
  UpdateCmd.Position3D = CubeWires.Position;
  UpdateCmd.Scale3D = FVector(CubeWires.Width, CubeWires.Height, CubeWires.Length);
  UpdateCmd.Color = CubeWires.Color;
  OutCubeWires.CommandID = rlCmdBuf.Update(UpdateCmd) ? CubeWires.CommandID : -1; 
  return OutCubeWires;
}

void URaylibUEBPLibrary::DrawCubeWiresV(FVector Position, FVector Size, FLinearColor Color, FRlDrawCubeWiresV& CubeWiresV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCubeWiresV;
  Cmd.Position3D = Position;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CubeWiresV.CommandID = ID;
  CubeWiresV.Position = Position;
  CubeWiresV.Size = Size;
  CubeWiresV.Color = Color;
}

FRlDrawCubeWiresV URaylibUEBPLibrary::DrawCubeWiresVUpdate(const FRlDrawCubeWiresV& CubeWiresV) {
  FRlDrawCubeWiresV OutCubeWiresV;
  if (CubeWiresV.CommandID < 0) {
    OutCubeWiresV.CommandID = -1;
    OutCubeWiresV = FRlDrawCubeWiresV();
    return OutCubeWiresV;
  }

  OutCubeWiresV = CubeWiresV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawCubeWiresV;
  UpdateCmd.Position3D = CubeWiresV.Position;
  UpdateCmd.Scale3D = CubeWiresV.Size;
  UpdateCmd.Color = CubeWiresV.Color;
  OutCubeWiresV.CommandID = rlCmdBuf.Update(UpdateCmd) ? CubeWiresV.CommandID : -1; 
  return OutCubeWiresV;
}

void URaylibUEBPLibrary::DrawSphere(FVector Center, float Radius, FLinearColor Color, FRlDrawSphere& Sphere) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphere;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Sphere.CommandID = ID;
  Sphere.Center = Center;
  Sphere.Radius = Radius;
  Sphere.Color = Color;
}

FRlDrawSphere URaylibUEBPLibrary::DrawSphereUpdate(const FRlDrawSphere& Sphere) {
  FRlDrawSphere OutSphere;
  if (Sphere.CommandID < 0) {
    OutSphere.CommandID = -1;
    OutSphere = FRlDrawSphere();
    return OutSphere;
  }

  OutSphere = Sphere;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.Type = ERlDrawType::DrawSphere;
  UpdateCmd.Position3D = Sphere.Center;
  UpdateCmd.Radius = Sphere.Radius;
  UpdateCmd.Color = Sphere.Color;
  OutSphere.CommandID = rlCmdBuf.Update(UpdateCmd) ? Sphere.CommandID : -1; 
  return OutSphere;
}

void URaylibUEBPLibrary::DrawSphereEx(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, FRlDrawSphereEx& SphereEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphereEx;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Segments = Rings;
  Cmd.Sides = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  SphereEx.CommandID = ID;
  SphereEx.Center = Center;
  SphereEx.Radius = Radius;
  SphereEx.Rings = Rings;
  SphereEx.Slices = Slices;
  SphereEx.Color = Color;
}

FRlDrawSphereEx URaylibUEBPLibrary::DrawSphereExUpdate(const FRlDrawSphereEx& SphereEx) {
  FRlDrawSphereEx OutSphereEx;
  if (SphereEx.CommandID < 0) {
    OutSphereEx.CommandID = -1;
    OutSphereEx = FRlDrawSphereEx();
    return OutSphereEx;
  }

  OutSphereEx = SphereEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = SphereEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawSphereEx;
  UpdateCmd.Position3D = SphereEx.Center;
  UpdateCmd.Radius = SphereEx.Radius;
  UpdateCmd.Segments = SphereEx.Rings;
  UpdateCmd.Sides = SphereEx.Slices;
  UpdateCmd.Color = SphereEx.Color;
  OutSphereEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? SphereEx.CommandID : -1; 
  return OutSphereEx;
}

void URaylibUEBPLibrary::DrawSphereWires(FVector Center, float Radius, int32 Rings, int32 Slices, FLinearColor Color, FRlDrawSphereWires& SphereWires) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawSphereWires;
  Cmd.Position3D = Center;
  Cmd.Radius = Radius;
  Cmd.Segments = Rings;
  Cmd.Sides = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  SphereWires.CommandID = ID;
  SphereWires.Center = Center;
  SphereWires.Radius = Radius;
  SphereWires.Rings = Rings;
  SphereWires.Slices = Slices;
  SphereWires.Color = Color;
}

FRlDrawSphereWires URaylibUEBPLibrary::DrawSphereWiresUpdate(const FRlDrawSphereWires& SphereWires) {
  FRlDrawSphereWires OutSphereWires;
  if (SphereWires.CommandID < 0) {
    OutSphereWires.CommandID = -1;
    OutSphereWires = FRlDrawSphereWires();
    return OutSphereWires;
  }

  OutSphereWires = SphereWires;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = SphereWires.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawSphereWires;
  UpdateCmd.Position3D = SphereWires.Center;
  UpdateCmd.Radius = SphereWires.Radius;
  UpdateCmd.Segments = SphereWires.Rings;
  UpdateCmd.Sides = SphereWires.Slices;
  UpdateCmd.Color = SphereWires.Color;
  OutSphereWires.CommandID = rlCmdBuf.Update(UpdateCmd) ? SphereWires.CommandID : -1; 
  return OutSphereWires;
}

void URaylibUEBPLibrary::DrawCylinder(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, FRlDrawCylinder& Cylinder) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinder;
  Cmd.Position3D = Position;
  Cmd.Radius = RadiusTop;
  Cmd.Size.X = (int32)RadiusBottom;
  Cmd.Scale3D.Z = Height;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Cylinder.CommandID = ID;
  Cylinder.Position = Position;
  Cylinder.RadiusTop = RadiusTop;
  Cylinder.RadiusBottom = RadiusBottom;
  Cylinder.Height = Height;
  Cylinder.Slices = Slices;
  Cylinder.Color = Color;
}

FRlDrawCylinder URaylibUEBPLibrary::DrawCylinderUpdate(const FRlDrawCylinder& Cylinder) {
  FRlDrawCylinder OutCylinder;
  if (Cylinder.CommandID < 0) {
    OutCylinder.CommandID = -1;
    OutCylinder = FRlDrawCylinder();
    return OutCylinder;
  }

  OutCylinder = Cylinder;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Cylinder.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCylinder;
  UpdateCmd.Position3D = Cylinder.Position;
  UpdateCmd.Radius = Cylinder.RadiusTop;
  UpdateCmd.Size.X = (int32)Cylinder.RadiusBottom;
  UpdateCmd.Scale3D.Z = Cylinder.Height;
  UpdateCmd.Slices = Cylinder.Slices;
  UpdateCmd.Color = Cylinder.Color;
  OutCylinder.CommandID = rlCmdBuf.Update(UpdateCmd) ? Cylinder.CommandID : -1; 
  return OutCylinder;
}

void URaylibUEBPLibrary::DrawCylinderEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, FRlDrawCylinderEx& CylinderEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderEx;
  Cmd.Position3D = StartVertex;
  Cmd.Origin3D = EndVertex;
  Cmd.Radius = StartRadius;
  Cmd.Size.X = (int32)EndRadius;
  Cmd.Sides = Sides;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CylinderEx.CommandID = ID;
  CylinderEx.StartVertex = StartVertex;
  CylinderEx.EndVertex = EndVertex;
  CylinderEx.StartRadius = StartRadius;
  CylinderEx.EndRadius = EndRadius;
  CylinderEx.Sides = Sides;
  CylinderEx.Slices = Slices;
  CylinderEx.Color = Color;
}

FRlDrawCylinderEx URaylibUEBPLibrary::DrawCylinderExUpdate(const FRlDrawCylinderEx& CylinderEx) {
  FRlDrawCylinderEx OutCylinderEx;
  if (CylinderEx.CommandID < 0) {
    OutCylinderEx.CommandID = -1;
    OutCylinderEx = FRlDrawCylinderEx();
    return OutCylinderEx;
  }

  OutCylinderEx = CylinderEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = CylinderEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCylinderEx;
  UpdateCmd.Position3D = CylinderEx.StartVertex;
  UpdateCmd.Origin3D = CylinderEx.EndVertex;
  UpdateCmd.Radius = CylinderEx.StartRadius;
  UpdateCmd.Size.X = (int32)CylinderEx.EndRadius;
  UpdateCmd.Sides = CylinderEx.Sides;
  UpdateCmd.Slices = CylinderEx.Slices;
  UpdateCmd.Color = CylinderEx.Color;
  OutCylinderEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? CylinderEx.CommandID : -1; 
  return OutCylinderEx;
}

void URaylibUEBPLibrary::DrawCylinderWires(FVector Position, float RadiusTop, float RadiusBottom, float Height, int32 Slices, FLinearColor Color, FRlDrawCylinderWires& CylinderWires) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderWires;
  Cmd.Position3D = Position;
  Cmd.Radius = RadiusTop;
  Cmd.Size.X = (int32)RadiusBottom;
  Cmd.Scale3D.Z = Height;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CylinderWires.CommandID = ID;
  CylinderWires.Position = Position;
  CylinderWires.RadiusTop = RadiusTop;
  CylinderWires.RadiusBottom = RadiusBottom;
  CylinderWires.Height = Height;
  CylinderWires.Slices = Slices;
  CylinderWires.Color = Color;
}

FRlDrawCylinderWires URaylibUEBPLibrary::DrawCylinderWiresUpdate(const FRlDrawCylinderWires& CylinderWires) {
  FRlDrawCylinderWires OutCylinderWires;
  if (CylinderWires.CommandID < 0) {
    OutCylinderWires.CommandID = -1;
    OutCylinderWires = FRlDrawCylinderWires();
    return OutCylinderWires;
  }

  OutCylinderWires = CylinderWires;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = CylinderWires.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCylinderWires;
  UpdateCmd.Position3D = CylinderWires.Position;
  UpdateCmd.Radius = CylinderWires.RadiusTop;
  UpdateCmd.Size.X = (int32)CylinderWires.RadiusBottom;
  UpdateCmd.Scale3D.Z = CylinderWires.Height;
  UpdateCmd.Slices = CylinderWires.Slices;
  UpdateCmd.Color = CylinderWires.Color;
  OutCylinderWires.CommandID = rlCmdBuf.Update(UpdateCmd) ? CylinderWires.CommandID : -1; 
  return OutCylinderWires;
}

void URaylibUEBPLibrary::DrawCylinderWiresEx(FVector StartVertex, FVector EndVertex, float StartRadius, float EndRadius, int32 Sides, int32 Slices, FLinearColor Color, FRlDrawCylinderWiresEx& CylinderWiresEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCylinderWiresEx;
  Cmd.Position3D = StartVertex;
  Cmd.Origin3D = EndVertex;
  Cmd.Radius = StartRadius;
  Cmd.Size.X = (int32)EndRadius;
  Cmd.Sides = Sides;
  Cmd.Slices = Slices;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CylinderWiresEx.CommandID = ID;
  CylinderWiresEx.StartVertex = StartVertex;
  CylinderWiresEx.EndVertex = EndVertex;
  CylinderWiresEx.StartRadius = StartRadius;
  CylinderWiresEx.EndRadius = EndRadius;
  CylinderWiresEx.Sides = Sides;
  CylinderWiresEx.Slices = Slices;
  CylinderWiresEx.Color = Color;
}

FRlDrawCylinderWiresEx URaylibUEBPLibrary::DrawCylinderWiresExUpdate(const FRlDrawCylinderWiresEx& CylinderWiresEx) {
  FRlDrawCylinderWiresEx OutCylinderWiresEx;
  if (CylinderWiresEx.CommandID < 0) {
    OutCylinderWiresEx.CommandID = -1;
    OutCylinderWiresEx = FRlDrawCylinderWiresEx();
    return OutCylinderWiresEx;
  }

  OutCylinderWiresEx = CylinderWiresEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = CylinderWiresEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCylinderWiresEx;
  UpdateCmd.Position3D = CylinderWiresEx.StartVertex;
  UpdateCmd.Origin3D = CylinderWiresEx.EndVertex;
  UpdateCmd.Radius = CylinderWiresEx.StartRadius;
  UpdateCmd.Size.X = (int32)CylinderWiresEx.EndRadius;
  UpdateCmd.Sides = CylinderWiresEx.Sides;
  UpdateCmd.Slices = CylinderWiresEx.Slices;
  UpdateCmd.Color = CylinderWiresEx.Color;
  OutCylinderWiresEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? CylinderWiresEx.CommandID : -1; 
  return OutCylinderWiresEx;
}

void URaylibUEBPLibrary::DrawCapsule(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, FRlDrawCapsule& Capsule) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCapsule;
  Cmd.Position3D = Start;
  Cmd.Origin3D = End;
  Cmd.Radius = Radius;
  Cmd.Slices = Slices;
  Cmd.Segments = Rings;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Capsule.CommandID = ID;
  Capsule.Start = Start;
  Capsule.End = End;
  Capsule.Radius = Radius;
  Capsule.Slices = Slices;
  Capsule.Rings = Rings;
  Capsule.Color = Color;
}

FRlDrawCapsule URaylibUEBPLibrary::DrawCapsuleUpdate(const FRlDrawCapsule& Capsule) {
  FRlDrawCapsule OutCapsule;
  if (Capsule.CommandID < 0) {
    OutCapsule.CommandID = -1;
    OutCapsule = FRlDrawCapsule();
    return OutCapsule;
  }

  OutCapsule = Capsule;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Capsule.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCapsule;
  UpdateCmd.Position3D = Capsule.Start;
  UpdateCmd.Origin3D = Capsule.End;
  UpdateCmd.Radius = Capsule.Radius;
  UpdateCmd.Slices = Capsule.Slices;
  UpdateCmd.Segments = Capsule.Rings;
  UpdateCmd.Color = Capsule.Color;
  OutCapsule.CommandID = rlCmdBuf.Update(UpdateCmd) ? Capsule.CommandID : -1; 
  return OutCapsule;
}

void URaylibUEBPLibrary::DrawCapsuleWires(FVector Start, FVector End, float Radius, int32 Slices, int32 Rings, FLinearColor Color, FRlDrawCapsuleWires& CapsuleWires) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawCapsuleWires;
  Cmd.Position3D = Start;
  Cmd.Origin3D = End;
  Cmd.Radius = Radius;
  Cmd.Slices = Slices;
  Cmd.Segments = Rings;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  CapsuleWires.CommandID = ID;
  CapsuleWires.Start = Start;
  CapsuleWires.End = End;
  CapsuleWires.Radius = Radius;
  CapsuleWires.Slices = Slices;
  CapsuleWires.Rings = Rings;
  CapsuleWires.Color = Color;
}

FRlDrawCapsuleWires URaylibUEBPLibrary::DrawCapsuleWiresUpdate(const FRlDrawCapsuleWires& CapsuleWires) {
  FRlDrawCapsuleWires OutCapsuleWires;
  if (CapsuleWires.CommandID < 0) {
    OutCapsuleWires.CommandID = -1;
    OutCapsuleWires = FRlDrawCapsuleWires();
    return OutCapsuleWires;
  }

  OutCapsuleWires = CapsuleWires;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = CapsuleWires.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawCapsuleWires;
  UpdateCmd.Position3D = CapsuleWires.Start;
  UpdateCmd.Origin3D = CapsuleWires.End;
  UpdateCmd.Radius = CapsuleWires.Radius;
  UpdateCmd.Slices = CapsuleWires.Slices;
  UpdateCmd.Segments = CapsuleWires.Rings;
  UpdateCmd.Color = CapsuleWires.Color;
  OutCapsuleWires.CommandID = rlCmdBuf.Update(UpdateCmd) ? CapsuleWires.CommandID : -1; 
  return OutCapsuleWires;
}

void URaylibUEBPLibrary::DrawPlane(FVector CenterPos, FVector Size, FLinearColor Color, FRlDrawPlane& Plane) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawPlane;
  Cmd.Position3D = CenterPos;
  Cmd.Scale3D = Size;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Plane.CommandID = ID;
  Plane.CenterPos = CenterPos;
  Plane.Size = Size;
  Plane.Color = Color;
}

FRlDrawPlane URaylibUEBPLibrary::DrawPlaneUpdate(const FRlDrawPlane& Plane) {
  FRlDrawPlane OutPlane;
  if (Plane.CommandID < 0) {
    OutPlane.CommandID = -1;
    OutPlane = FRlDrawPlane();
    return OutPlane;
  }

  OutPlane = Plane;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Plane.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawPlane;
  UpdateCmd.Position3D = Plane.CenterPos;
  UpdateCmd.Scale3D = Plane.Size;
  UpdateCmd.Color = Plane.Color;
  OutPlane.CommandID = rlCmdBuf.Update(UpdateCmd) ? Plane.CommandID : -1; 
  return OutPlane;
}

void URaylibUEBPLibrary::DrawRay(FVector RayPos, FVector RayDir, FLinearColor Color, FRlDrawRay& Ray) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawRay;
  Cmd.RayOrigin = RayPos;
  Cmd.RayDir = RayDir;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  Ray.CommandID = ID;
  Ray.RayPos = RayPos;
  Ray.RayDir = RayDir;
  Ray.Color = Color;
}

FRlDrawRay URaylibUEBPLibrary::DrawRayUpdate(const FRlDrawRay& Ray) {
  FRlDrawRay OutRay;
  if (Ray.CommandID < 0) {
    OutRay.CommandID = -1;
    OutRay = FRlDrawRay();
    return OutRay;
  }

  OutRay = Ray;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Ray.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawRay;
  UpdateCmd.RayOrigin = Ray.RayPos;
  UpdateCmd.RayDir = Ray.RayDir;
  UpdateCmd.Color = Ray.Color;
  OutRay.CommandID = rlCmdBuf.Update(UpdateCmd) ? Ray.CommandID : -1; 
  return OutRay;
}

void URaylibUEBPLibrary::DrawGrid(int32 Slices, float Spacing, FRlDrawGrid& Grid) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawGrid;
  Cmd.Slices = Slices;
  Cmd.Thick = Spacing;
  int32 ID = rlCmdBuf.Add(Cmd);

  Grid.CommandID = ID;
  Grid.Slices = Slices;
  Grid.Spacing = Spacing;
}

FRlDrawGrid URaylibUEBPLibrary::DrawGridUpdate(const FRlDrawGrid& Grid) {
  FRlDrawGrid OutGrid;
  if (Grid.CommandID < 0) {
    OutGrid.CommandID = -1;
    OutGrid = FRlDrawGrid();
    return OutGrid;
  }

  OutGrid = Grid;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Grid.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawGrid;
  UpdateCmd.Slices = Grid.Slices;
  UpdateCmd.Thick = Grid.Spacing;
  OutGrid.CommandID = rlCmdBuf.Update(UpdateCmd) ? Grid.CommandID : -1; 
  return OutGrid;
}

void URaylibUEBPLibrary::DrawModel(const FString& ModelPath, FVector Position, float Scale, FLinearColor Tint, FRlDrawModel& Model) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModel;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  Model.CommandID = ID;
  Model.ModelPath = ModelPath;
  Model.Position = Position;
  Model.Scale = Scale;
  Model.Tint = Tint;
}

FRlDrawModel URaylibUEBPLibrary::DrawModelUpdate(const FRlDrawModel& Model) {
  FRlDrawModel OutModel;
  if (Model.CommandID < 0) {
    OutModel.CommandID = -1;
    OutModel = FRlDrawModel();
    return OutModel;
  }

  OutModel = Model;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Model.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawModel;
  UpdateCmd.ModelPath = Model.ModelPath;
  UpdateCmd.Position3D = Model.Position;
  UpdateCmd.Scale3D = FVector(Model.Scale);
  UpdateCmd.Color = Model.Tint;
  OutModel.CommandID = rlCmdBuf.Update(UpdateCmd) ? Model.CommandID : -1; 
  return OutModel;
}

void URaylibUEBPLibrary::DrawModelEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor Tint, FRlDrawModelEx& ModelEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelEx;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Scale3D = Scale;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  ModelEx.CommandID = ID;
  ModelEx.ModelPath = ModelPath;
  ModelEx.Position = Position;
  ModelEx.RotationAxis = RotationAxis;
  ModelEx.RotationAngle = RotationAngle;
  ModelEx.Scale = Scale;
  ModelEx.Tint = Tint;
}

FRlDrawModelEx URaylibUEBPLibrary::DrawModelExUpdate(const FRlDrawModelEx& ModelEx) {
  FRlDrawModelEx OutModelEx;
  if (ModelEx.CommandID < 0) {
    OutModelEx.CommandID = -1;
    OutModelEx = FRlDrawModelEx();
    return OutModelEx;
  }

  OutModelEx = ModelEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = ModelEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawModelEx;
  UpdateCmd.ModelPath = ModelEx.ModelPath;
  UpdateCmd.Position3D = ModelEx.Position;
  UpdateCmd.RotationAxis = ModelEx.RotationAxis;
  UpdateCmd.RotationAngle = ModelEx.RotationAngle;
  UpdateCmd.Scale3D = ModelEx.Scale;
  UpdateCmd.Color = ModelEx.Tint;
  OutModelEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? ModelEx.CommandID : -1; 
  return OutModelEx;
}

void URaylibUEBPLibrary::DrawModelWires(const FString& ModelPath, FVector Position, float Scale, FLinearColor WireColor, FRlDrawModelWires& ModelWires) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelWires;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = WireColor;
  int32 ID = rlCmdBuf.Add(Cmd);

  ModelWires.CommandID = ID;
  ModelWires.ModelPath = ModelPath;
  ModelWires.Position = Position;
  ModelWires.Scale = Scale;
  ModelWires.WireColor = WireColor;
}

FRlDrawModelWires URaylibUEBPLibrary::DrawModelWiresUpdate(const FRlDrawModelWires& ModelWires) {
  FRlDrawModelWires OutModelWires;
  if (ModelWires.CommandID < 0) {
    OutModelWires.CommandID = -1;
    OutModelWires = FRlDrawModelWires();
    return OutModelWires;
  }

  OutModelWires = ModelWires;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = ModelWires.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawModelWires;
  UpdateCmd.ModelPath = ModelWires.ModelPath;
  UpdateCmd.Position3D = ModelWires.Position;
  UpdateCmd.Scale3D = FVector(ModelWires.Scale);
  UpdateCmd.Color = ModelWires.WireColor;
  OutModelWires.CommandID = rlCmdBuf.Update(UpdateCmd) ? ModelWires.CommandID : -1; 
  return OutModelWires;
}

void URaylibUEBPLibrary::DrawModelWiresEx(const FString& ModelPath, FVector Position, FVector RotationAxis, float RotationAngle, FVector Scale, FLinearColor WireColor, FRlDrawModelWiresEx& ModelWiresEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawModelWiresEx;
  Cmd.ModelPath = ModelPath;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = RotationAxis;
  Cmd.RotationAngle = RotationAngle;
  Cmd.Scale3D = Scale;
  Cmd.Color = WireColor;
  int32 ID = rlCmdBuf.Add(Cmd);

  ModelWiresEx.CommandID = ID;
  ModelWiresEx.ModelPath = ModelPath;
  ModelWiresEx.Position = Position;
  ModelWiresEx.RotationAxis = RotationAxis;
  ModelWiresEx.RotationAngle = RotationAngle;
  ModelWiresEx.Scale = Scale;
  ModelWiresEx.WireColor = WireColor;
}

FRlDrawModelWiresEx URaylibUEBPLibrary::DrawModelWiresExUpdate(const FRlDrawModelWiresEx& ModelWiresEx) {
  FRlDrawModelWiresEx OutModelWiresEx;
  if (ModelWiresEx.CommandID < 0) {
    OutModelWiresEx.CommandID = -1;
    OutModelWiresEx = FRlDrawModelWiresEx();
    return OutModelWiresEx;
  }

  OutModelWiresEx = ModelWiresEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = ModelWiresEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawModelWiresEx;
  UpdateCmd.ModelPath = ModelWiresEx.ModelPath;
  UpdateCmd.Position3D = ModelWiresEx.Position;
  UpdateCmd.RotationAxis = ModelWiresEx.RotationAxis;
  UpdateCmd.RotationAngle = ModelWiresEx.RotationAngle;
  UpdateCmd.Scale3D = ModelWiresEx.Scale;
  UpdateCmd.Color = ModelWiresEx.WireColor;
  OutModelWiresEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? ModelWiresEx.CommandID : -1; 
  return OutModelWiresEx;
}

void URaylibUEBPLibrary::DrawBoundingBox(const FVector& Min, const FVector& Max, FLinearColor Color, FRlDrawBoundingBox& BoundingBox) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBoundingBox;
  Cmd.Position3D = Min;
  Cmd.Scale3D = Max - Min;
  Cmd.Color = Color;
  int32 ID = rlCmdBuf.Add(Cmd);

  BoundingBox.CommandID = ID;
  BoundingBox.Min = Min;
  BoundingBox.Max = Max;
  BoundingBox.Color = Color;
}

FRlDrawBoundingBox URaylibUEBPLibrary::DrawBoundingBoxUpdate(const FRlDrawBoundingBox& BoundingBox) {
  FRlDrawBoundingBox OutBoundingBox;
  if (BoundingBox.CommandID < 0) {
    OutBoundingBox.CommandID = -1;
    OutBoundingBox = FRlDrawBoundingBox();
    return OutBoundingBox;
  }

  OutBoundingBox = BoundingBox;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = BoundingBox.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawBoundingBox;
  UpdateCmd.Position3D = BoundingBox.Min;
  UpdateCmd.Scale3D = BoundingBox.Max - BoundingBox.Min;
  UpdateCmd.Color = BoundingBox.Color;
  OutBoundingBox.CommandID = rlCmdBuf.Update(UpdateCmd) ? BoundingBox.CommandID : -1; 
  return OutBoundingBox;
}

void URaylibUEBPLibrary::DrawBillboard(const FString& TexturePath, FVector Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboard& Billboard) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboard;
  Cmd.TexturePath = TexturePath;
  Cmd.Position3D = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  Billboard.CommandID = ID;
  Billboard.TexturePath = TexturePath;
  Billboard.Position = Position;
  Billboard.Rotation = Rotation;
  Billboard.Scale = Scale;
  Billboard.Tint = Tint;
}

FRlDrawBillboard URaylibUEBPLibrary::DrawBillboardUpdate(const FRlDrawBillboard& Billboard) {
  FRlDrawBillboard OutBillboard;
  if (Billboard.CommandID < 0) {
    OutBillboard.CommandID = -1;
    OutBillboard = FRlDrawBillboard();
    return OutBillboard;
  }

  OutBillboard = Billboard;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Billboard.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawBillboard;
  UpdateCmd.TexturePath = Billboard.TexturePath;
  UpdateCmd.Position3D = Billboard.Position;
  UpdateCmd.Rotation = Billboard.Rotation;
  UpdateCmd.Scale3D = FVector(Billboard.Scale);
  UpdateCmd.Color = Billboard.Tint;
  OutBillboard.CommandID = rlCmdBuf.Update(UpdateCmd) ? Billboard.CommandID : -1; 
  return OutBillboard;
}

void URaylibUEBPLibrary::DrawBillboardRec(const FString& TexturePath, FIntPoint SourceRec, FVector Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboardRec& BillboardRec) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboardRec;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Position3D = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  BillboardRec.CommandID = ID;
  BillboardRec.TexturePath = TexturePath;
  BillboardRec.SourceRec = SourceRec;
  BillboardRec.Position = Position;
  BillboardRec.Rotation = Rotation;
  BillboardRec.Scale = Scale;
  BillboardRec.Tint = Tint;
}

FRlDrawBillboardRec URaylibUEBPLibrary::DrawBillboardRecUpdate(const FRlDrawBillboardRec& BillboardRec) {
  FRlDrawBillboardRec OutBillboardRec;
  if (BillboardRec.CommandID < 0) {
    OutBillboardRec.CommandID = -1;
    OutBillboardRec = FRlDrawBillboardRec();
    return OutBillboardRec;
  }

  OutBillboardRec = BillboardRec;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = BillboardRec.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawBillboardRec;
  UpdateCmd.TexturePath = BillboardRec.TexturePath;
  UpdateCmd.SourcePos = BillboardRec.SourceRec;
  UpdateCmd.Position3D = BillboardRec.Position;
  UpdateCmd.Rotation = BillboardRec.Rotation;
  UpdateCmd.Scale3D = FVector(BillboardRec.Scale);
  UpdateCmd.Color = BillboardRec.Tint;
  OutBillboardRec.CommandID = rlCmdBuf.Update(UpdateCmd) ? BillboardRec.CommandID : -1; 
  return OutBillboardRec;
}

void URaylibUEBPLibrary::DrawBillboardPro(const FString& TexturePath, FIntPoint SourceRec, FVector Position, FVector Up, FVector Right, FVector Forward, float Rotation, float Scale, FLinearColor Tint, FRlDrawBillboardPro& BillboardPro) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawBillboardPro;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Position3D = Position;
  Cmd.RotationAxis = Up;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  BillboardPro.CommandID = ID;
  BillboardPro.TexturePath = TexturePath;
  BillboardPro.SourceRec = SourceRec;
  BillboardPro.Position = Position;
  BillboardPro.Up = Up;
  BillboardPro.Right = Right;
  BillboardPro.Forward = Forward;
  BillboardPro.Rotation = Rotation;
  BillboardPro.Scale = Scale;
  BillboardPro.Tint = Tint;
}

FRlDrawBillboardPro URaylibUEBPLibrary::DrawBillboardProUpdate(const FRlDrawBillboardPro& BillboardPro) {
  FRlDrawBillboardPro OutBillboardPro;
  if (BillboardPro.CommandID < 0) {
    OutBillboardPro.CommandID = -1;
    OutBillboardPro = FRlDrawBillboardPro();
    return OutBillboardPro;
  }

  OutBillboardPro = BillboardPro;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = BillboardPro.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawBillboardPro;
  UpdateCmd.TexturePath = BillboardPro.TexturePath;
  UpdateCmd.SourcePos = BillboardPro.SourceRec;
  UpdateCmd.Position3D = BillboardPro.Position;
  UpdateCmd.RotationAxis = BillboardPro.Up;
  UpdateCmd.Scale3D = FVector(BillboardPro.Scale);
  UpdateCmd.Rotation = BillboardPro.Rotation;
  UpdateCmd.Color = BillboardPro.Tint;
  OutBillboardPro.CommandID = rlCmdBuf.Update(UpdateCmd) ? BillboardPro.CommandID : -1; 
  return OutBillboardPro;
}

void URaylibUEBPLibrary::DrawTexture(const FString& TexturePath, int32 PosX, int32 PosY, FLinearColor Tint, FRlDrawTexture& Texture) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTexture;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = FIntPoint(PosX, PosY);
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  Texture.CommandID = ID;
  Texture.TexturePath = TexturePath;
  Texture.PosX = PosX;
  Texture.PosY = PosY;
  Texture.Tint = Tint;
}

FRlDrawTexture URaylibUEBPLibrary::DrawTextureUpdate(const FRlDrawTexture& Texture) {
  FRlDrawTexture OutTexture;
  if (Texture.CommandID < 0) {
    OutTexture.CommandID = -1;
    OutTexture = FRlDrawTexture();
    return OutTexture;
  }

  OutTexture = Texture;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = Texture.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTexture;
  UpdateCmd.TexturePath = Texture.TexturePath;
  UpdateCmd.Position = FIntPoint(Texture.PosX, Texture.PosY);
  UpdateCmd.Color = Texture.Tint;
  OutTexture.CommandID = rlCmdBuf.Update(UpdateCmd) ? Texture.CommandID : -1; 
  return OutTexture;
}

void URaylibUEBPLibrary::DrawTextureV(const FString& TexturePath, FIntPoint Position, FLinearColor Tint, FRlDrawTextureV& TextureV) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureV;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = Position;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextureV.CommandID = ID;
  TextureV.TexturePath = TexturePath;
  TextureV.Position = Position;
  TextureV.Tint = Tint;
}

FRlDrawTextureV URaylibUEBPLibrary::DrawTextureVUpdate(const FRlDrawTextureV& TextureV) {
  FRlDrawTextureV OutTextureV;
  if (TextureV.CommandID < 0) {
    OutTextureV.CommandID = -1;
    OutTextureV = FRlDrawTextureV();
    return OutTextureV;
  }

  OutTextureV = TextureV;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextureV.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextureV;
  UpdateCmd.TexturePath = TextureV.TexturePath;
  UpdateCmd.Position = TextureV.Position;
  UpdateCmd.Color = TextureV.Tint;
  OutTextureV.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextureV.CommandID : -1; 
  return OutTextureV;
}

void URaylibUEBPLibrary::DrawTextureEx(const FString& TexturePath, FIntPoint Position, float Rotation, float Scale, FLinearColor Tint, FRlDrawTextureEx& TextureEx) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureEx;
  Cmd.TexturePath = TexturePath;
  Cmd.Position = Position;
  Cmd.Rotation = Rotation;
  Cmd.Scale3D = FVector(Scale);
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextureEx.CommandID = ID;
  TextureEx.TexturePath = TexturePath;
  TextureEx.Position = Position;
  TextureEx.Rotation = Rotation;
  TextureEx.Scale = Scale;
  TextureEx.Tint = Tint;
}

FRlDrawTextureEx URaylibUEBPLibrary::DrawTextureExUpdate(const FRlDrawTextureEx& TextureEx) {
  FRlDrawTextureEx OutTextureEx;
  if (TextureEx.CommandID < 0) {
    OutTextureEx.CommandID = -1;
    OutTextureEx = FRlDrawTextureEx();
    return OutTextureEx;
  }

  OutTextureEx = TextureEx;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextureEx.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextureEx;
  UpdateCmd.TexturePath = TextureEx.TexturePath;
  UpdateCmd.Position = TextureEx.Position;
  UpdateCmd.Rotation = TextureEx.Rotation;
  UpdateCmd.Scale3D = FVector(TextureEx.Scale);
  UpdateCmd.Color = TextureEx.Tint;
  OutTextureEx.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextureEx.CommandID : -1; 
  return OutTextureEx;
}

void URaylibUEBPLibrary::DrawTextureRec(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FLinearColor Tint, FRlDrawTextureRec& TextureRec) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureRec;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Size = DestRec;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextureRec.CommandID = ID;
  TextureRec.TexturePath = TexturePath;
  TextureRec.SourceRec = SourceRec;
  TextureRec.DestRec = DestRec;
  TextureRec.Tint = Tint;
}

FRlDrawTextureRec URaylibUEBPLibrary::DrawTextureRecUpdate(const FRlDrawTextureRec& TextureRec) {
  FRlDrawTextureRec OutTextureRec;
  if (TextureRec.CommandID < 0) {
    OutTextureRec.CommandID = -1;
    OutTextureRec = FRlDrawTextureRec();
    return OutTextureRec;
  }

  OutTextureRec = TextureRec;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextureRec.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextureRec;
  UpdateCmd.TexturePath = TextureRec.TexturePath;
  UpdateCmd.SourcePos = TextureRec.SourceRec;
  UpdateCmd.Size = TextureRec.DestRec;
  UpdateCmd.Color = TextureRec.Tint;
  OutTextureRec.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextureRec.CommandID : -1; 
  return OutTextureRec;
}

void URaylibUEBPLibrary::DrawTexturePro(const FString& TexturePath, FIntPoint SourceRec, FIntPoint DestRec, FIntPoint Origin, float Rotation, FLinearColor Tint, FRlDrawTexturePro& TexturePro) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTexturePro;
  Cmd.TexturePath = TexturePath;
  Cmd.SourcePos = SourceRec;
  Cmd.Size = DestRec;
  Cmd.StartPos = Origin;
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  TexturePro.CommandID = ID;
  TexturePro.TexturePath = TexturePath;
  TexturePro.SourceRec = SourceRec;
  TexturePro.DestRec = DestRec;
  TexturePro.Origin = Origin;
  TexturePro.Rotation = Rotation;
  TexturePro.Tint = Tint;
}

FRlDrawTexturePro URaylibUEBPLibrary::DrawTextureProUpdate(const FRlDrawTexturePro& TexturePro) {
  FRlDrawTexturePro OutTexturePro;
  if (TexturePro.CommandID < 0) {
    OutTexturePro.CommandID = -1;
    OutTexturePro = FRlDrawTexturePro();
    return OutTexturePro;
  }

  OutTexturePro = TexturePro;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TexturePro.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTexturePro;
  UpdateCmd.TexturePath = TexturePro.TexturePath;
  UpdateCmd.SourcePos = TexturePro.SourceRec;
  UpdateCmd.Size = TexturePro.DestRec;
  UpdateCmd.StartPos = TexturePro.Origin;
  UpdateCmd.Rotation = TexturePro.Rotation;
  UpdateCmd.Color = TexturePro.Tint;
  OutTexturePro.CommandID = rlCmdBuf.Update(UpdateCmd) ? TexturePro.CommandID : -1; 
  return OutTexturePro;
}

void URaylibUEBPLibrary::DrawTextureNPatch(const FString& TexturePath, const TArray<FIntPoint>& NPatchInfo, FIntPoint Dest, float Rotation, FLinearColor Tint, FRlDrawTextureNPatch& TextureNPatch) {
  FRlDrawCommand Cmd;
  Cmd.Type = ERlDrawType::DrawTextureNPatch;
  Cmd.TexturePath = TexturePath;
  Cmd.Points = NPatchInfo;
  Cmd.Position = Dest;
  Cmd.Rotation = Rotation;
  Cmd.Color = Tint;
  int32 ID = rlCmdBuf.Add(Cmd);

  TextureNPatch.CommandID = ID;
  TextureNPatch.TexturePath = TexturePath;
  TextureNPatch.NPatchInfo = NPatchInfo;
  TextureNPatch.Dest = Dest;
  TextureNPatch.Rotation = Rotation;
  TextureNPatch.Tint = Tint;
}

FRlDrawTextureNPatch URaylibUEBPLibrary::DrawTextureNPatchUpdate(const FRlDrawTextureNPatch& TextureNPatch) {
  FRlDrawTextureNPatch OutTextureNPatch;
  if (TextureNPatch.CommandID < 0) {
    OutTextureNPatch.CommandID = -1;
    OutTextureNPatch = FRlDrawTextureNPatch();
    return OutTextureNPatch;
  }

  OutTextureNPatch = TextureNPatch;
  FRlDrawCommand UpdateCmd;
  UpdateCmd.CommandID = TextureNPatch.CommandID;
  UpdateCmd.Type = ERlDrawType::DrawTextureNPatch;
  UpdateCmd.TexturePath = TextureNPatch.TexturePath;
  UpdateCmd.Points = TextureNPatch.NPatchInfo;
  UpdateCmd.Position = TextureNPatch.Dest;
  UpdateCmd.Rotation = TextureNPatch.Rotation;
  UpdateCmd.Color = TextureNPatch.Tint;
  OutTextureNPatch.CommandID = rlCmdBuf.Update(UpdateCmd) ? TextureNPatch.CommandID : -1; 
  return OutTextureNPatch;
}

void URaylibUEBPLibrary::rlCreateDrawCommand(FRlDrawCommand InCommand, FRlDrawCommand& OutCommand) {
  FRlDrawCommand NewCmd = InCommand;
  if (NewCmd.Color.A == 0) {
  NewCmd.Color.A = 255;
  }
  OutCommand.CommandID = rlCmdBuf.Add(NewCmd);
  NewCmd.CommandID = InCommand.CommandID;
  OutCommand = NewCmd;
}

void URaylibUEBPLibrary::rlUpdateDrawCommand(FRlDrawCommand InCommand, FRlDrawCommand& OutCommand) {
  if (InCommand.CommandID <= 0) {
  UE_LOG(LogTemp, Warning, TEXT("rlUpdateDrawCommand invalid CommandID  %d"), InCommand.CommandID );
  OutCommand = InCommand;
  return;
  }

  FRlDrawCommand UpdateCmd = InCommand;
  if (UpdateCmd.Color.A == 0) {
  UpdateCmd.Color.A = 255;
  }
  UpdateCmd.CommandID = InCommand.CommandID ;
  if (InCommand.Color.A == 0) {
  InCommand.Color.A = 255;
  }
  if (rlCmdBuf.Update(UpdateCmd)) {
  OutCommand = UpdateCmd;
  } else {
  UE_LOG(LogTemp, Warning, TEXT("rlUpdateDrawCommand failed for ID %d"), InCommand.CommandID );
  }
}

void URaylibUEBPLibrary::rlGetDrawCommand(int32& CommandID , FRlDrawCommand& OutCommand) {
  if (int32* IndexPtr = rlCmdBuf.IDToIndex.Find(CommandID )) {
    int32 Index = *IndexPtr;
    if (rlCmdBuf.rlDrawCommands.IsValidIndex(Index)) {
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
