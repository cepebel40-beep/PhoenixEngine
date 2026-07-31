#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <string>
#include <fstream>
#include <sstream>

namespace PHX
{

bool ShaderLoader::LoadDefaultShaders()
{
    std::string shaderSource;

    if (!ReadTextFile(
            "gta/files/phoenix/shaders/include/common.glsl",
            shaderSource))
    {
        Logger::Error("Failed to load common.glsl");
        return false;
    }

    Logger::Info("common.glsl loaded successfully");
    return true;
}

bool ShaderLoader::ReadTextFile(const char* path, std::string& buffer)
{
    std::ifstream file(path);

    if (!file.is_open())
        return false;

    std::stringstream stream;
    stream << file.rdbuf();

    buffer = stream.str();

    return true;
}

}
