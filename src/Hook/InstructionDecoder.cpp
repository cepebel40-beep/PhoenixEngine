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

bool InstructionDecoder::IsBranchLink(uint32_t)
{
    return false;
}

bool InstructionDecoder::IsAdr(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x10000000;
}

bool InstructionDecoder::IsAdrp(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x90000000;
}

bool InstructionDecoder::IsB(uint32_t)
{
    return false;
}

}
