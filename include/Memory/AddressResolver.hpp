#pragma once

#include <cstdint>

namespace PHX
{
    class AddressResolver
    {
    public:
        static uintptr_t Resolve(uintptr_t offset);
        static void SetBase(uintptr_t base);

    private:
        static uintptr_t mBase;
    };
}
