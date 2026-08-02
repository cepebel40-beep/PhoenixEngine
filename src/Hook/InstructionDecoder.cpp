#include "Hook/InstructionDecoder.hpp"

namespace PHX
{

uint32_t InstructionDecoder::Read(uintptr_t address)
{
    return *reinterpret_cast<uint32_t*>(address);
}

bool InstructionDecoder::IsBranch(uint32_t instruction)
{
    return (instruction & 0x7C000000) == 0x14000000;
}

bool InstructionDecoder::IsBranchLink(uint32_t instruction)
{
    return (instruction & 0xFC000000) == 0x94000000;
}

bool InstructionDecoder::IsLoadLiteral(uint32_t instruction)
{
    return (instruction & 0x3B000000) == 0x18000000;
}

bool InstructionDecoder::IsADR(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x10000000;
}

bool InstructionDecoder::IsADRP(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x90000000;
}

bool InstructionDecoder::IsPcRelative(uint32_t instruction)
{
    return IsADR(instruction)
        || IsADRP(instruction)
        || IsLoadLiteral(instruction);
}

bool InstructionDecoder::IsB(uint32_t instruction)
{
    return (instruction & 0xFC000000) == 0x14000000;
}

}
