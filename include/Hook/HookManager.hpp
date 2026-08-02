#pragma once

#include <cstdint>

namespace PHX
{

class HookManager
{
public:
    static bool Initialize();
    static bool Shutdown();

    static bool InstallOpenGLHooks();
    static bool RemoveOpenGLHooks();

    static bool Install(
        uintptr_t target,
        uintptr_t detour,
        uintptr_t* original);

    static bool Remove(
        uintptr_t target);

    static bool IsInitialized();

public:
    struct HookEntry
    {
        uintptr_t target;
        uintptr_t detour;
        uintptr_t trampoline;
        bool installed;
    };

private:
    static bool sInitialized;
