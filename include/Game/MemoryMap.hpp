#pragma once

#include <string>

namespace PHX
{
    class MemoryMap
    {
    public:
        static bool Refresh();
        static bool Contains(const std::string& module);
    };
}
