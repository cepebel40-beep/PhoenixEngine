#include "System/EngineState.hpp"

namespace PHX
{

bool EngineState::sInitialized = false;

bool EngineState::IsInitialized()
{
    return sInitialized;
}

void EngineState::SetInitialized(bool initialized)
{
    sInitialized = initialized;
}

}
