#include "Game/ModuleScanner.hpp"
#include "Game/ProcMapsReader.hpp"

namespace PHX
{
    uintptr_t ModuleScanner::mBase = 0;

    bool ModuleScanner::Scan()
    {
        if (!ProcMapsReader::Refresh())
            return false;

        // Tahap berikutnya:
        // Cari libGTASA.so dari daftar memory map.

        mBase = 0;

        return true;
    }

    uintptr_t ModuleScanner::GetBase()
    {
        return mBase;
    }
}
