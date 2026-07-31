#include "Hook/Trampoline.hpp"

namespace PHX
{
    void* Trampoline::Allocate(size_t)
    {
        return nullptr;
    }

    void Trampoline::Free(void*)
    {
    }

    uintptr_t Trampoline::GetAddress(void*)
    {
        return 0;
    }
}
