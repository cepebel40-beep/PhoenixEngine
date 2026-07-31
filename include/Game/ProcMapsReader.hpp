#pragma once

#include <string>
#include <vector>

namespace PHX
{
    class ProcMapsReader
    {
    public:
        static bool Refresh();
        static const std::vector<std::string>& GetEntries();

    private:
        static std::vector<std::string> mEntries;
    };
}
