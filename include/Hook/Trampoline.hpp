#pragma once

#include <cstddef>
#include <cstdint>

namespace PHX
{

class Trampoline
{
public:

    static constexpr size_t kMaxInstructions = 8;

    static bool Create(void* target,
                       void* replacement,
                       void** trampoline);

private:

    static bool CopyInstructions(uint32_t* destination,
                                 const uint32_t* source,
                                 size_t count);

    static bool RelocateInstruction(uint32_t* destination,
                                    uintptr_t sourcePc,
                                    uintptr_t destinationPc);

    static void WriteAbsoluteJump(uint32_t* destination,
                                  uintptr_t address);
};

}
