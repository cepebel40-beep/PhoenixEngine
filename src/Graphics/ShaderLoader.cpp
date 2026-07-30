#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderLoader::Load(const char* vertexPath, const char* fragmentPath)
{
    Logger::Info("================================");
    Logger::Info("Phoenix ShaderLoader");
    Logger::Info("Initializing...");
    Logger::Info("================================");

    if (vertexPath == nullptr)
    {
        Logger::Error("Vertex shader path is null.");
        return false;
    }

    if (fragmentPath == nullptr)
    {
        Logger::Error("Fragment shader path is null.");
        return false;
    }

    Logger::Info("Vertex shader path OK.");
    Logger::Info("Fragment shader path OK.");

    Logger::Info("ShaderLoader ready.");

    return true;
}

}
