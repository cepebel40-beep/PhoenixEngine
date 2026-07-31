#include "Graphics/Renderer.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool InitializeRenderer()
{
    Logger::Info("Initializing Renderer...");

    ShaderManager shaderManager;

    if (!shaderManager.Initialize())
    {
        Logger::Error("Renderer initialization failed.");
        return false;
    }

    Logger::Info("Renderer ready.");

    return true;
}

}
