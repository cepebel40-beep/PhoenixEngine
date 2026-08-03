#include "Graphics/ShaderReplacer.hpp"
#include "Graphics/ShaderLoader.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

static bool LoadReplacementShader(
    const char* path,
    std::string& output)
{
    ShaderLoader loader;

    return loader.ReadTextFile(
        path,
        output);
}

bool ShaderReplacer::Initialize()
{
    Logger::Info(
        "ShaderReplacer initialized");

    return true;
}

void ShaderReplacer::Shutdown()
{
    Logger::Info(
        "ShaderReplacer shutdown");
}

std::string ShaderReplacer::Replace(
    const std::string& source)
{
    std::string replacement;

    if (LoadReplacementShader(
            "gta/files/phoenix/shaders/ps/default.ps",
            replacement))
    {
        Logger::Info(
            "Replacement shader loaded.");

        return replacement;
    }

    return source;
}

}
