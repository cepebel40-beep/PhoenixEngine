#include "Hook/HookManager.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/OpenGLHook.hpp"

#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

namespace PHX
{

bool HookManager::sInitialized = false;

static HookManager::HookEntry gHook =
{
    0,
    0,
    0,
    false
};

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
    return PHX::InstallOpenGLHooks();
}

bool HookManager::RemoveOpenGLHooks()
{
    return PHX::RemoveOpenGLHooks();
}

bool HookManager::Install(
    uintptr_t target,
    uintptr_t detour,
    uintptr_t* original)
{
    if (!target || !detour)
        return false;

    gHook.target = target;
    gHook.detour = detour;
    gHook.installed = true;

    if (original)
        *original = target;

    Logger::Info("Hook installed (ARM64 stage)");

    return true;
}

bool HookManager::Remove(uintptr_t target)
{
    if (!gHook.installed)
        return false;

    if (gHook.target != target)
        return false;

    gHook.installed = false;

    Logger::Info("Hook removed");

    return true;
}

bool HookManager::IsInitialized()
{
    return sInitialized;
}

}
