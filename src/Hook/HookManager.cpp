#include "Hook/HookManager.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/OpenGLHook.hpp"

#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

namespace PHX
{

constexpr size_t kTrampolineSize = 64;

bool HookManager::sInitialized = false;

static HookManager::HookEntry gHook =
{
    0,      // target
    0,      // detour
    0,      // trampoline
    false   // installed
};

static void* AllocateExecutableMemory(size_t size)
{
    return mmap(
        nullptr,
        size,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0);
}

static void FreeExecutableMemory(void* memory)
{
    if (memory)
        munmap(memory, kTrampolineSize);
}

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

    if (gHook.trampoline)
    {
        FreeExecutableMemory(
            reinterpret_cast<void*>(gHook.trampoline));

        gHook.trampoline = 0;
    }

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

    void* trampoline =
        AllocateExecutableMemory(kTrampolineSize);

    if (!trampoline)
    {
        Logger::Error("Failed to allocate trampoline");
        return false;
    }

    gHook.target = target;
    gHook.detour = detour;
    gHook.trampoline =
        reinterpret_cast<uintptr_t>(trampoline);
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

    if (gHook.trampoline)
    {
        FreeExecutableMemory(
            reinterpret_cast<void*>(gHook.trampoline));

        gHook.trampoline = 0;
    }

    gHook.installed = false;

    Logger::Info("Hook removed");

    return true;
}

bool HookManager::IsInitialized()
{
    return sInitialized;
}

}
