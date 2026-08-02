#include "Hook/Relocator.hpp"

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
    m_source = source;
    m_destination = destination;
    m_instructionCount = instructionCount;

    return true;
}

bool Relocator::Relocate()
{
    if (m_source == 0)
        return false;

    if (m_destination == 0)
        return false;

    if (m_instructionCount == 0)
        return false;

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
