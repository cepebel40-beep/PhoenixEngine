#include "Game/GameProcess.hpp"

namespace PHX
{
    static bool gRunning = false;

    bool GameProcess::Initialize()
    {
        gRunning = true;
        return true;
    }

    bool GameProcess::IsRunning()
    {
        return gRunning;
    }
}
