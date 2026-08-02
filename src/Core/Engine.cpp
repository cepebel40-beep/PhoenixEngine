#include "Core/Engine.hpp"
#include "Core/Logger.hpp"
#include "Core/LibraryLoader.hpp"

#include "Graphics/ShaderManager.hpp"
#include "Graphics/Renderer.hpp"

#include "Hook/HookManager.hpp"
#include "Hook/RenderHook.hpp"

namespace PHX
{

bool InitializeEngine()
{
    if (!LibraryLoader::Initialize())
    {
        Logger::Error("Failed to initialize LibraryLoader");
        return false;
    }

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

    if (!HookManager::Initialize())
    {
        Logger::Error("Failed to initialize HookManager");
        return false;
    }

    if (!HookManager::InstallOpenGLHooks())
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
