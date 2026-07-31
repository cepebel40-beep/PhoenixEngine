#pragma once

#include <cstddef>
#include <cstdint>

namespace PHX
{
    class MemoryPatch
    {
    public:
        static bool Write(uintptr_t address,
                          const void* data,
                          size_t size);

        static bool Fill(uintptr_t address,
                         uint8_t value,
                         size_t size);

        static bool Nop(uintptr_t address,
                        size_t size);
    };
}
