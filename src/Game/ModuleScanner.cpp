#include "Game/ModuleScanner.hpp"

namespace PHX
{
    uintptr_t ModuleScanner::mBase = 0;

    bool ModuleScanner::Scan()
    {
        // Placeholder.
        // Alpha berikutnya akan membaca /proc/self/maps
        // untuk mencari base address libGTASA.so.
        mBase = 0;
        return true;
    }

    uintptr_t ModuleScanner::GetBase()
    {
        return mBase;
    }
}
