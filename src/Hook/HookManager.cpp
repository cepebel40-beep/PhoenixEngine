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

static void* AllocateExecutableMemory(size_t size)
{
    void* memory = mmap(
        nullptr,
        size,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0);

    if (memory == MAP_FAILED)
        return nullptr;

    return memory;
}

static void FreeExecutableMemory(void* memory, size_t size)
{
    if (memory)
        munmap(memory, size);
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

    constexpr size_t kTrampolineSize = 64;

    void* trampoline = AllocateExecutableMemory(kTrampolineSize);

    if (!trampoline)
    {
        Logger::Error("Failed to allocate executable trampoline");
        return false;
    }

    std::memcpy(
        trampoline,
        reinterpret_cast<void*>(target),
        16);

    gHook.target = target;
    gHook.detour = detour;
    gHook.trampoline = reinterpret_cast<uintptr_t>(trampoline);
    gHook.installed = true;

    if (original)
        *original = gHook.trampoline;

    Logger::Info("Executable trampoline allocated");

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
            reinterpret_cast<void*>(gHook.trampoline),
            64);

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
