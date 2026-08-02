#include "Hook/Trampoline.hpp"

#include <cstring>

namespace PHX
{

bool Trampoline::Create(void*,
                        void*,
                        void**)
{
    return false;
}

bool Trampoline::CopyInstructions(uint32_t* destination,
                                  const uint32_t* source,
                                  size_t count)
{
    std::memcpy(destination,
                source,
                count * sizeof(uint32_t));

    return true;
}

bool Trampoline::RelocateInstruction(uint32_t* destination,
                                     uintptr_t,
                                     uintptr_t)
{
    (void)destination;

    return true;
}

void Trampoline::WriteAbsoluteJump(uint32_t* destination,
                                   uintptr_t address)
{
    destination[0] = 0x58000050; // LDR X16, #8
    destination[1] = 0xD61F0200; // BR X16

    uint64_t* literal =
        reinterpret_cast<uint64_t*>(&destination[2]);

    *literal = static_cast<uint64_t>(address);
}
