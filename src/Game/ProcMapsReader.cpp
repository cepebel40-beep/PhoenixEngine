#include "Game/ProcMapsReader.hpp"

namespace PHX
{
    std::vector<std::string> ProcMapsReader::mEntries;

    bool ProcMapsReader::Refresh()
    {
        mEntries.clear();

        // Placeholder.
        // Alpha berikutnya akan membaca
        // /proc/self/maps.

        return true;
    }

    const std::vector<std::string>& ProcMapsReader::GetEntries()
    {
        return mEntries;
    }
}
