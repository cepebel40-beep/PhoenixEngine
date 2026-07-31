#pragma once

#include <cstdint>

namespace PHX
{
    class ModuleScanner
    {
    public:
        static bool Scan();
        static uintptr_t GetBase();

    private:
        static uintptr_t mBase;
    };
}
