#pragma once

#include <cstddef>
#include <cstdint>

namespace PHX
{
    class Trampoline
    {
    public:

        static void* Allocate(size_t size);

        static void Free(void* address);

        static uintptr_t GetAddress(void* trampoline);
    };
}
