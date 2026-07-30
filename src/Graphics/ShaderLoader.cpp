#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <fstream>
#include <sstream>
#include <string>

#ifdef __ANDROID__
#include <GLES3/gl3.h>
#endif

namespace PHX
{

static std::string ReadTextFile(const char* path)
{
    std::ifstream file(path);

    if(!file.is_open())
    {
        Logger::Error("Failed to open shader file.");
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

ShaderLoader::ShaderLoader()
{
    Logger::Info("ShaderLoader initialized");
}

ShaderLoader::~ShaderLoader()
{
    Logger::Info("ShaderLoader destroyed");
}

bool ShaderLoader::Load(const char* vertexPath, const char* fragmentPath)
{
    if(vertexPath == nullptr || fragmentPath == nullptr)
    {
        Logger::Error("Shader path invalid.");
        return false;
    }

    std::string vertexSource = ReadTextFile(vertexPath);
    std::string fragmentSource = ReadTextFile(fragmentPath);

    if(vertexSource.empty())
    {
        Logger::Error("Vertex shader empty.");
        return false;
    }

    if(fragmentSource.empty())
    {
        Logger::Error("Fragment shader empty.");
        return false;
    }

    Logger::Info("Vertex shader loaded.");
    Logger::Info("Fragment shader loaded.");

    return true;
}

}
