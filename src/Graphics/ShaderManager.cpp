#include "Graphics/ShaderManager.hpp"
#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderManager::Initialize()
{
    Logger::Info("ShaderManager initializing...");

    ShaderLoader loader;

    if (!loader.LoadDefaultShaders())
    {
        Logger::Error("Failed to load default shaders.");
        return false;
    }

    Logger::Info("Default shaders loaded.");

    Logger::Info("ShaderManager ready.");

    return true;
}

}
