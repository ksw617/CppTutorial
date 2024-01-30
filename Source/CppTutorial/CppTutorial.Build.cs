// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CppTutorial : ModuleRules
{
	public CppTutorial(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayTasks", "NavigationSystem", "AIModule", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
