using UnrealBuildTool;

public class WidgetsAndUi : ModuleRules
{
    public WidgetsAndUi(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG", "Slate", "SlateCore" });
    }
}
