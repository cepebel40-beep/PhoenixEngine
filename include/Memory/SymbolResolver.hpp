#pragma once

#include <cstdint>

namespace PHX
{
    class SymbolResolver
    {
    public:
        static bool Initialize();

        static uintptr_t Resolve(const char* symbol);
    };
}
