#include "Memory/SymbolResolver.hpp"

#include <dlfcn.h>

namespace PHX
{
    static void* gHandle = nullptr;

    bool SymbolResolver::Initialize()
    {
        if (gHandle)
            return true;

        gHandle = dlopen(nullptr, RTLD_NOW);

        return gHandle != nullptr;
    }

    uintptr_t SymbolResolver::Resolve(const char* symbol)
    {
        if (!gHandle)
            return 0;

        if (!symbol)
            return 0;

        void* address = dlsym(gHandle, symbol);

        if (!address)
            return 0;

        return reinterpret_cast<uintptr_t>(address);
    }
}
