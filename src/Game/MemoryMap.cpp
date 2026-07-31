#include "Game/MemoryMap.hpp"

namespace PHX
{
    bool MemoryMap::Refresh()
    {
        // Placeholder.
        // Alpha berikutnya akan membaca /proc/self/maps.
        return true;
    }

    bool MemoryMap::Contains(const std::string&)
    {
        return false;
    }
}
