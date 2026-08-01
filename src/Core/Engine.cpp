#include "Core/Engine.hpp"
#include "Core/Logger.hpp"

#include "Graphics/ShaderManager.hpp"
#include "Graphics/Renderer.hpp"

#include "Hook/OpenGLHook.hpp"
#include "Hook/RenderHook.hpp"

namespace PHX
{

bool InitializeEngine()
{
    static ShaderManager shaderManager;

    if (!shaderManager.Initialize())
    {
        Logger::Error("Failed to initialize ShaderManager");
        return false;
    }

    if (!InitializeRenderer())
    {
        Logger::Error("Failed to initialize Renderer");
        return false;
    }

    if (!InstallOpenGLHooks())
    {
        Logger::Error("Failed to install OpenGL hooks");
        return false;
    }
    
    if (!InstallRenderHooks())
    {
        Logger::Error("Failed to install Render hooks");
        return false;
    }
    
    Logger::Info("Engine initialized");

    return true;
}

}
