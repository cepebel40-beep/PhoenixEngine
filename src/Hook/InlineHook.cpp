#include "Hook/InlineHook.hpp"

namespace PHX
{
    bool InlineHook::Install(uintptr_t,
                             uintptr_t,
                             uintptr_t*)
    {
        return false;
    }

    bool InlineHook::Remove(uintptr_t)
    {
        return false;
    }
}
