#include "Graphics/ShaderManager.hpp"
#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderManager::Initialize()
{
    Logger::Info("Initializing ShaderManager...");

    ShaderLoader loader;

    Logger::Info("ShaderLoader ready.");
    Logger::Info("ShaderManager initialized.");

    return true;
}

}
