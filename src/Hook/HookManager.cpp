#include "Hook/HookManager.hpp"

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

    RemoveOpenGLHooks();

    sInitialized = false;

    Logger::Info("HookManager shutdown");

    return true;
}

bool HookManager::InstallOpenGLHooks()
{
    Logger::Info("Installing OpenGL hooks...");

    return true;
}

bool HookManager::RemoveOpenGLHooks()
{
    Logger::Info("Removing OpenGL hooks...");

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
