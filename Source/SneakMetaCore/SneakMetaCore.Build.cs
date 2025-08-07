using UnrealBuildTool;

public class SneakMetaCore: ModuleRules
{
    public SneakMetaCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "Slate", "SlateCore" });
    }
}
