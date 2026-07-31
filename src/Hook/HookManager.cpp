#include "Hook/HookManager.hpp"

namespace PHX
{
    bool HookManager::Initialize()
    {
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
}
