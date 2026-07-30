#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#ifdef __ANDROID__
#include <GLES3/gl3.h>
#endif

namespace PHX
{

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
    Logger::Info("================================");
    Logger::Info("Phoenix ShaderLoader");
    Logger::Info("Preparing shader system...");
    Logger::Info("================================");

    if(vertexPath == nullptr)
    {
        Logger::Error("Vertex shader path is null");
        return false;
    }

    if(fragmentPath == nullptr)
    {
        Logger::Error("Fragment shader path is null");
        return false;
    }

    Logger::Info("Vertex Shader:");
    Logger::Info(vertexPath);

    Logger::Info("Fragment Shader:");
    Logger::Info(fragmentPath);

    Logger::Info("ShaderLoader ready.");

    return true;
}

}
