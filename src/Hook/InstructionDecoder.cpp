#include "Hook/InstructionDecoder.hpp"

namespace PHX
{

uint32_t InstructionDecoder::Read(uintptr_t address)
{
    return *reinterpret_cast<uint32_t*>(address);
}

bool InstructionDecoder::IsBranch(uint32_t instruction)
{
    return IsB(instruction) || IsBranchLink(instruction);
}

bool InstructionDecoder::IsLoadLiteral(uint32_t instruction)
{
    return (instruction & 0x3B000000) == 0x18000000;
}

bool InstructionDecoder::IsPcRelative(uint32_t instruction)
{
    return IsAdr(instruction) || IsAdrp(instruction);
}

bool InstructionDecoder::IsBranchLink(uint32_t instruction)
{
    return (instruction & 0xFC000000) == 0x94000000;
}

bool InstructionDecoder::IsAdr(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x10000000;
}

bool InstructionDecoder::IsAdrp(uint32_t instruction)
{
    return (instruction & 0x9F000000) == 0x90000000;
}

bool InstructionDecoder::IsB(uint32_t instruction)
{
    return (instruction & 0xFC000000) == 0x14000000;
}

}
