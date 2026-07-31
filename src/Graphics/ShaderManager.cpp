#include "Graphics/ShaderManager.hpp"
#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderManager::Initialize()
{
    Logger::Info("ShaderManager initializing...");

    ShaderLoader loader;

    Logger::Info("ShaderLoader linked.");

    Logger::Info("ShaderManager ready.");

    return true;
}

}
