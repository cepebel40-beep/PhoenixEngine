#pragma once

namespace PHX
{

class RuntimeMonitor
{
public:
    static void Update();
    static bool IsRunning();

private:
    static bool sRunning;
};

}
