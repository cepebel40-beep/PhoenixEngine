#pragma once

#include <string>

namespace PHX
{
    class GameVersion
    {
    public:
        static bool Detect();
        static std::string GetVersion();

    private:
        static std::string mVersion;
    };
}
