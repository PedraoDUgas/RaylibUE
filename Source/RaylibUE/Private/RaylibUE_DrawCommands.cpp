#include "RaylibUE_DrawCommands.h"

int32 FRlDrawCommandBuffer::Add(FRlDrawCommand& Cmd) {
  static int32 NextID = 1;
  int32 NewID = NextID++;
  Cmd.CommandID = NewID;
  int32 NewIndex = rlDrawCommands.Add(Cmd);
  IDToIndex.Add(NewID, NewIndex);
  return NewID;
}

bool FRlDrawCommandBuffer::Update(const FRlDrawCommand& Cmd) {
  if (int32* IndexPtr = IDToIndex.Find(Cmd.CommandID )) {
    int32 Index = *IndexPtr;
    if (rlDrawCommands.IsValidIndex(Index)) {
      FRlDrawCommand& Target = rlDrawCommands[Index];
      Target.Type = Cmd.Type;
      Target.Position = Cmd.Position;
      Target.Size = Cmd.Size;
      Target.Radius = Cmd.Radius;
      Target.Color = Cmd.Color;
      Target.Text = Cmd.Text;
      Target.FontSize = Cmd.FontSize;
      Target.Points = Cmd.Points;
      Target.Points3D = Cmd.Points3D;
      Target.Thick = Cmd.Thick;
      Target.StartPos = Cmd.StartPos;
      Target.EndPos = Cmd.EndPos;
      Target.StartAngle = Cmd.StartAngle;
      Target.EndAngle = Cmd.EndAngle;
      Target.Segments = Cmd.Segments;
      Target.Roundness = Cmd.Roundness;
      Target.Color1 = Cmd.Color1;
      Target.Color2 = Cmd.Color2;
      Target.Color3 = Cmd.Color3;
      Target.Color4 = Cmd.Color4;
      Target.Sides = Cmd.Sides;
      Target.Rotation = Cmd.Rotation;
      Target.Origin3D = Cmd.Origin3D;
      Target.Spacing = Cmd.Spacing;
      Target.Codepoints = Cmd.Codepoints;
      Target.Position3D = Cmd.Position3D;
      Target.Scale3D = Cmd.Scale3D;
      Target.RotationAxis = Cmd.RotationAxis;
      Target.RotationAngle = Cmd.RotationAngle;
      Target.ModelPath = Cmd.ModelPath;
      Target.TexturePath = Cmd.TexturePath;
      Target.SourcePos = Cmd.SourcePos;
      Target.SourceSize = Cmd.SourceSize;
      Target.RayOrigin = Cmd.RayOrigin;
      Target.RayDir = Cmd.RayDir;
      Target.Slices = Cmd.Slices;
      return true;
    }
  }
  return false;
}

bool FRlDrawCommandBuffer::Remove(int32 CommandID ) {
  if (int32* IndexPtr = IDToIndex.Find(CommandID )) {
    int32 Index = *IndexPtr;
    IDToIndex.Remove(CommandID );
    if (rlDrawCommands.IsValidIndex(Index)) {
      int32 LastIndex = rlDrawCommands.Num() - 1;
      if (Index != LastIndex) {
        rlDrawCommands[Index] = MoveTemp(rlDrawCommands[LastIndex]);
        int32 SwappedID = rlDrawCommands[Index].CommandID;
        if (IDToIndex.Contains(SwappedID)) {
          IDToIndex[SwappedID] = Index;
        }
      }
      rlDrawCommands.Pop();
      return true;
    }
  }
  return false;
}

void FRlDrawCommandBuffer::Clear() {
  rlDrawCommands.Empty();
  IDToIndex.Empty();
}
