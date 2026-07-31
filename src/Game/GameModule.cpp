#include "Game/GameModule.hpp"

namespace PHX
{
    uintptr_t GameModule::mBase = 0;

    bool GameModule::Locate()
    {
        // Placeholder.
        // Tahap berikutnya akan mencari base address libGTASA.so.
        mBase = 0;
        return true;
    }

    uintptr_t GameModule::GetBase()
    {
        return mBase;
    }
}
