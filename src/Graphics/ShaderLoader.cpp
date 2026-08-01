#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <fstream>
#include <sstream>

namespace PHX
{

static bool ReadFileInternal(const char* path, std::string& output)
{
    std::ifstream file(path, std::ios::binary);

    if (!file.is_open())
    {
        Logger::Error("Cannot open shader file:");
        Logger::Error(path);
        return false;
    }

    std::stringstream stream;
    stream << file.rdbuf();

    output = stream.str();

    if (output.empty())
    {
        Logger::Error("Shader file is empty:");
        Logger::Error(path);
        return false;
    }

    Logger::Info("Loaded shader:");
    Logger::Info(path);

    return true;
}

bool ShaderLoader::LoadDefaultShaders()
{
    std::string commonShader;
    std::string vertexShader;
    std::string fragmentShader;

    if (!ReadFileInternal(
            "gta/files/phoenix/shaders/include/common.glsl",
            commonShader))
    {
        return false;
    }

    if (!ReadFileInternal(
            "gta/files/phoenix/shaders/vs/default.vs",
            vertexShader))
    {
        return false;
    }

    if (!ReadFileInternal(
            "gta/files/phoenix/shaders/ps/default.ps",
            fragmentShader))
    {
        return false;
    }

    Logger::Info("Default shaders loaded successfully.");

    return true;
}

bool ShaderLoader::ReadTextFile(const char* path,
                                std::string& buffer)
{
    return ReadFileInternal(path, buffer);
}

}
