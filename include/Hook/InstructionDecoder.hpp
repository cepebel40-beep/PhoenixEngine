#pragma once

#include <cstdint>

namespace PHX
{
    class InstructionDecoder
    {
    public:

        static uint32_t Read(uintptr_t address);

        static bool IsBranch(uint32_t instruction);

        static bool IsLoadLiteral(uint32_t instruction);

        static bool IsPcRelative(uint32_t instruction);
    };
}
