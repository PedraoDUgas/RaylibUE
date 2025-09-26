using UnrealBuildTool;
using System.IO;

public class RaylibUE : ModuleRules {
	public RaylibUE(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { });
    PrivateIncludePaths.AddRange(new string[] { });

    PublicDependencyModuleNames.AddRange(new string[] {
				"Core",
		});
			
		PrivateDependencyModuleNames.AddRange(new string[] {
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
        "InputCore",
    });

    if (Target.bBuildEditor == true) {
      PrivateDependencyModuleNames.AddRange(new string[] {
        "UnrealEd",
      });
    }

    DynamicallyLoadedModuleNames.AddRange(new string[] { });

    // RayLib
    PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/raylib/include"));
    PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Private/raylib/lib/raylib.lib"));
  }
}