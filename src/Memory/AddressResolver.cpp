#include "Memory/AddressResolver.hpp"

namespace PHX
{
    uintptr_t AddressResolver::mBase = 0;

    void AddressResolver::SetBase(uintptr_t base)
    {
        mBase = base;
    }

    uintptr_t AddressResolver::Resolve(uintptr_t offset)
    {
        return mBase + offset;
    }
}
