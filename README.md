     .----------------.  .----------------.  .----------------. 
    | .--------------. || .--------------. || .--------------. |
    | |  ________    | || |  _________   | || |  ____  ____  | |
    | | |_   ___ `.  | || | |_   ___  |  | || | |_  _||_  _| | |
    | |   | |   `. \ | || |   | |_  \_|  | || |   \ \  / /   | |
    | |   | |    | | | || |   |  _|      | || |    > `' <    | |
    | |  _| |___.' / | || |  _| |_       | || |  _/ /'`\ \_  | |
    | | |________.'  | || | |_____|      | || | |____||____| | |
    | |              | || |              | || |              | |
    | '--------------' || '--------------' || '--------------' |
     '----------------'  '----------------'  '----------------' 

           DarknessFX @ https://dfx.lv | X : @DrkFX

# RaylibUE plugin For Unreal Engine 5

<img src=".git_img/RaylibUE_banner.png" alt="RaylibUE" width="640" />

## About

RaylibUE plugin seamlessly bridges [Raylib](https://www.raylib.com/)'s powerful 2D/3D drawing API with [Unreal Engine](https://www.unrealengine.com)'s intuitive Blueprint system.<br/>
Draw shapes, text, lines, textures and more, directly on your game viewport via transparent overlay, no code barriers.<br/>

## Why RaylibUE?

- Educational Bridge: Ideal for teachers/students, learn with Raylib's simplicity alongside Unreal Engine's depth, from basic shapes to 3D models.
- Raylib Fidelity: 50+ Raylib draw functions as Blueprint nodes (e.g., DrawCircle, DrawText, DrawModelEx) with exact parameters for 1:1 learning.
- Independent Render: RaylibUE render on it's raylib graphics API (OpenGL), it's independent of your graphics settings and is compatible with DirectX11/12 or Vulkan Unreal Engine projects.
- Non-Intrusive Overlay: Rendering to an independet overlay window atop UE game viewport, syncs on resize/drag/maximize, preserves UE input/focus.
- Command Buffer: Queue/update commands with handles, reorder, purge by type, or bulk set for real-world pipeline practice.

## Features
| Category | Highlights |
|----------|------------|
| **2D Basics** | Pixels, lines, circles, rects w/ gradients/rounding |
| **Text** | Dynamic fonts, texture fonts, codepoints, pro transforms |
| **3D** | Spheres, cubes, cylinders, models w/ wires |
| **Textures** | Billboard, NPatch, pro UVs |
| **Utils** |  Camera, FPS counter, grid, ray |

- **Blueprint Chain**: All nodes return OutShape pins, enabling to connect values to Update nodes for zero-friction development.
<img src=".git_img/screenshot_07.png" alt="RaylibUE" width="640" />

- **C++ Friendly**: Static calls, e.g., `URaylibUEBPLibrary::DrawPixel(10, 10, FLinearColor::Red, ID, Shape);`.
```cpp
#include "RaylibUEBPLibrary.h"
int32 ID;
FRlDrawText Shape;
URaylibUEBPLibrary::DrawText("Hello RaylibUE!", 100, 100, 24, FLinearColor::Yellow, ID, Shape);
```

##  Installing and Building

1. git clone https://github.com/darknessfx/RaylibUE.git
2. Create a new Unreal Engine C++ Project named *YourProject*.
3. Create a new folder named *Plugins* at *YourProject/*.
4. Copy **RaylibUE** to *YourProject/Plugins/* folder.
5. Regenerate project files. (right-click *YourProject.uproject* and Generate Project Files).
6. Open *YourProject.uproject* and reply that you want to buld the project.
7. Inside the *Unreal Editor*, go to menu Edit > Plugins and enable **RaylibUE** plugin.
8. Confirm to restart the editor.

> __Dependencies :__
>- Windows (WinAPI overlay)
>- UE 5.6.1 (can build to previous Unreal Engine versions, not tested)
>- Raylib library is bundled.
>- Visual Studio or VS Code, more information at [Unreal Engine: Setting Up Visual Studio](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine) and [Setting Up Visual Studio for Unreal Engine](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-5-6-documentation).

##  Quick start

<img src=".git_img/screenshot_02.png" alt="RaylibUE" width="640" />

1. Open Level Blueprint.
2. Event BeginPlay, add a new node: Raylib DrawText.
3. Set DrawText node to PosX 30, PosY 30, Text "Hello Raylib", FontSize: 64, Color: Green
4. Play.

Next step: See the image above to make your text grow every frame.

##  Sample
*(Under construction)*

##  Releases
*(Under construction)*

## Credits

[Unreal Engine](https://www.unrealengine.com/) from Epic Games.<br/>
[RayLib](https://www.raylib.com/) from Ramon Santamaria (X : [@raysan5](https://x.com/raysan5)).<br/>


## License

@MIT - Free for everyone and any use. <br/><br/>
DarknessFX @ [https://dfx.lv](https://dfx.lv) | X : [@DrkFX](https://x.com/DrkFX)
<br/>
https://github.com/DarknessFX/RaylibUE
