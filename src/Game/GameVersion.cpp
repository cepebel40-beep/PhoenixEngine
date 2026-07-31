#include "Game/GameVersion.hpp"

namespace PHX
{
    std::string GameVersion::mVersion = "Unknown";

    bool GameVersion::Detect()
    {
        mVersion = "GTA SA AML ARM64";
        return true;
    }

    std::string GameVersion::GetVersion()
    {
        return mVersion;
    }
}
