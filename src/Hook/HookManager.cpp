#include "Hook/HookManager.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"

namespace PHX
{

bool HookManager::sInitialized = false;

bool HookManager::Initialize()
{
    if (sInitialized)
        return true;

    Logger::Info("Initializing HookManager");

    if (!SymbolResolver::Initialize())
    {
        Logger::Error("Failed to initialize SymbolResolver");
        return false;
    }

    sInitialized = true;

    Logger::Info("HookManager initialized");

    return true;
}

bool HookManager::Shutdown()
{
    if (!sInitialized)
        return true;

    RemoveOpenGLHooks();

    SymbolResolver::Shutdown();

    sInitialized = false;

    Logger::Info("HookManager shutdown");

    return true;
}

bool HookManager::InstallOpenGLHooks()
{
    Logger::Info("Installing OpenGL hooks");

    return true;
}

bool HookManager::RemoveOpenGLHooks()
{
    Logger::Info("Removing OpenGL hooks");

    return true;
}

bool HookManager::Install(uintptr_t target,
                          uintptr_t detour,
                          uintptr_t* original)
{
    (void)target;
    (void)detour;
    (void)original;

    Logger::Info("HookManager::Install()");

    return true;
}

bool HookManager::Remove(uintptr_t target)
{
    (void)target;

    Logger::Info("HookManager::Remove()");

    return true;
}

bool HookManager::IsInitialized()
{
    return sInitialized;
}

}
