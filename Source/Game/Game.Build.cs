using Flax.Build;
using Flax.Build.NativeCpp;
using System.IO;

public class Game : GameModule
{
    /// <inheritdoc />
    public override void Init()
    {
        base.Init();

        // C#-only scripting
        BuildNativeCode = true;
    }

    /// <inheritdoc />
    public override void Setup(BuildOptions options)
    {
        base.Setup(options);

        options.ScriptingAPI.IgnoreMissingDocumentationWarnings = true;

        var rmlUiPath = Path.Combine(FolderPath, "..", "RmlUI");

        options.CompileEnv.IncludePaths.Add(Path.Combine(rmlUiPath, "include"));
        options.LinkEnv.InputLibraries.Add(Path.Combine(rmlUiPath, "libs", "freetype.lib"));
        options.LinkEnv.InputLibraries.Add(Path.Combine(rmlUiPath, "libs", "RmlCore.lib"));
        options.LinkEnv.InputLibraries.Add(Path.Combine(rmlUiPath, "libs", "RmlControls.lib"));
        options.LinkEnv.InputLibraries.Add(Path.Combine(rmlUiPath, "libs", "RmlDebugger.lib"));

        options.CompileEnv.PreprocessorDefinitions.Add("RMLUI_STATIC_LIB");
        /*
         options.CompileEnv.IncludePaths.Add(Path.Combine(bcryptPath, "include"));
options.LinkEnv.InputLibraries.Add(Path.Combine(bcryptPath, "lib", "bcrypt.lib"));
options.DependencyFiles.Add(Path.Combine(bcryptPath, "bin", "bcrypt.dll"));
         */


        // Here you can modify the build options for your game module
        // To reference another module use: options.PublicDependencies.Add("Audio");
        // To add C++ define use: options.PublicDefinitions.Add("COMPILE_WITH_FLAX");
        // To learn more see scripting documentation.
    }
}
