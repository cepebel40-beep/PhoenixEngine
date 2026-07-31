#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderLoader::LoadDefaultShaders()
{
    std::string shaderSource;

    if (!ReadTextFile("gta/files/phoenix/shaders/include/common.glsl", shaderSource))
    {
        Logger::Error("Failed to load common.glsl");
        return false;
    }

    Logger::Info("common.glsl loaded successfully");

    return true;
}

}
