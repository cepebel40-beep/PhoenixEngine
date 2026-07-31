#pragma once

#include <cstdint>

namespace PHX
{
    class InlineHook
    {
    public:

        static bool Install(uintptr_t target,
                            uintptr_t detour,
                            uintptr_t* trampoline);

        static bool Remove(uintptr_t target);
    };
}
