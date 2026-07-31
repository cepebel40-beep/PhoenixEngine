#include "Graphics/Renderer.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

static ShaderManager gShaderManager;

bool InitializeRenderer()
{
    Logger::Info("Initializing Renderer...");

    if (!gShaderManager.Initialize())
    {
        Logger::Error("Renderer initialization failed.");
        return false;
    }

    Logger::Info("Renderer ready.");

    return true;
}

}
