#include "Memory/MemoryPatch.hpp"

namespace PHX
{
    bool MemoryPatch::Write(uintptr_t,
                            const void*,
                            size_t)
    {
        return false;
    }

    bool MemoryPatch::Fill(uintptr_t,
                           uint8_t,
                           size_t)
    {
        return false;
    }

    bool MemoryPatch::Nop(uintptr_t,
                          size_t)
    {
        return false;
    }
}
