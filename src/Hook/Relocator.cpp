#include "Hook/Relocator.hpp"
#include "Hook/InstructionDecoder.hpp"

#include <cstring>

namespace PHX
{

Relocator::Relocator()
    : m_source(0),
      m_destination(0),
      m_instructionCount(0)
{
}

bool Relocator::Prepare(uintptr_t source,
                        uintptr_t destination,
                        size_t instructionCount)
{
    if (source == 0)
        return false;

    if (destination == 0)
        return false;

    if (instructionCount == 0)
        return false;

    m_source = source;
    m_destination = destination;
    m_instructionCount = instructionCount;

    return true;
}

bool Relocator::Relocate()
{
    auto* src = reinterpret_cast<uint32_t*>(m_source);
    auto* dst = reinterpret_cast<uint32_t*>(m_destination);

    for (size_t i = 0; i < m_instructionCount; ++i)
    {
        uintptr_t sourcePc =
            m_source + (i * sizeof(uint32_t));

        uintptr_t destinationPc =
            m_destination + (i * sizeof(uint32_t));

        uint32_t instruction =
            InstructionDecoder::Read(sourcePc);

        /*
         * Stage 3
         *
         * Untuk sementara:
         * - Instruksi biasa langsung dicopy.
         * - Instruksi PC-relative dikenali.
         * - Relocation sebenarnya akan dibuat
         *   pada commit berikutnya.
         */

        if (InstructionDecoder::IsPcRelative(instruction))
        {
            dst[i] = instruction;
            continue;
        }

        if (InstructionDecoder::IsBranch(instruction))
        {
            dst[i] = instruction;
            continue;
        }

        if (InstructionDecoder::IsLoadLiteral(instruction))
        {
            dst[i] = instruction;
            continue;
        }

        dst[i] = instruction;

        (void)sourcePc;
        (void)destinationPc;
    }

    return true;
}

uintptr_t Relocator::GetSource() const
{
    return m_source;
}

uintptr_t Relocator::GetDestination() const
{
    return m_destination;
}

size_t Relocator::GetInstructionCount() const
{
    return m_instructionCount;
}

}
