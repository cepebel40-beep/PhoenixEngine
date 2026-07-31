#include "Memory/SymbolResolver.hpp"

namespace PHX
{
    bool SymbolResolver::Initialize()
    {
        return true;
    }

    uintptr_t SymbolResolver::Resolve(const char*)
    {
        return 0;
    }
}
