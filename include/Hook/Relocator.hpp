#pragma once

#include <cstdint>

namespace PHX
{

class Relocator
{
public:

    Relocator();

    bool Prepare(uintptr_t source,
                 uintptr_t destination,
                 size_t instructionCount);

    bool Relocate();

    uintptr_t GetSource() const;

    uintptr_t GetDestination() const;

    size_t GetInstructionCount() const;

private:

    uintptr_t m_source;

    uintptr_t m_destination;

    size_t m_instructionCount;
};

}
