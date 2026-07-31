#pragma once

namespace PHX
{

class EngineState
{
public:
    static bool IsInitialized();
    static void SetInitialized(bool initialized);

private:
    static bool sInitialized;
};

}
