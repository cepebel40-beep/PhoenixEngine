#include "Hook/HookManager.hpp"

#include "Hook/OpenGLHook.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool HookManager::sInitialized = false;

bool HookManager::Initialize()
{
    if (sInitialized)
        return true;

    Logger::Info("HookManager initialized");

    sInitialized = true;

    return true;
}

bool HookManager::Shutdown()
{
    if (!sInitialized)
        return true;

    OpenGLHook::Shutdown();

    sInitialized = false;

    Logger::Info("HookManager shutdown");

    return true;
}

bool HookManager::InstallOpenGLHooks()
{
    Logger::Info("Installing OpenGL hooks");

    if (!OpenGLHook::Initialize())
    {
        Logger::Error("OpenGLHook initialization failed");
        return false;
    }

    Logger::Info("OpenGL hooks installed");

    return true;
}

bool HookManager::RemoveOpenGLHooks()
{
    OpenGLHook::Shutdown();

    Logger::Info("OpenGL hooks removed");

    return true;
}

bool HookManager::Install(uintptr_t,
                          uintptr_t,
                          uintptr_t*)
{
    return false;
}

bool HookManager::Remove(uintptr_t)
{
    return false;
}

bool HookManager::IsInitialized()
{
    return sInitialized;
}

}
