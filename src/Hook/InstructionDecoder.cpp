#include "Hook/InstructionDecoder.hpp"

namespace PHX
{
    uint32_t InstructionDecoder::Read(uintptr_t)
    {
        return 0;
    }

    bool InstructionDecoder::IsBranch(uint32_t)
    {
        return false;
    }

    bool InstructionDecoder::IsLoadLiteral(uint32_t)
    {
        return false;
    }

    bool InstructionDecoder::IsPcRelative(uint32_t)
    {
        return false;
    }
}
