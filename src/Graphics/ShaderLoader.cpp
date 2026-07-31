#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <fstream>
#include <sstream>

namespace PHX
{

bool ShaderLoader::LoadDefaultShaders()
{
    std::string commonShader;
    std::string vertexShader;
    std::string fragmentShader;

    if (!ReadTextFile(
            "gta/files/phoenix/shaders/include/common.glsl",
            commonShader))
    {
        Logger::Error("Failed to load common.glsl");
        return false;
    }

    if (!ReadTextFile(
            "gta/files/phoenix/shaders/vs/default.vs",
            vertexShader))
    {
        Logger::Error("Failed to load default.vs");
        return false;
    }

    if (!ReadTextFile(
            "gta/files/phoenix/shaders/ps/default.ps",
            fragmentShader))
    {
        Logger::Error("Failed to load default.ps");
        return false;
    }

    Logger::Info("ShaderLoader loaded all default shaders");

    return true;
}

bool ShaderLoader::ReadTextFile(const char* path,
                                std::string& buffer)
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
