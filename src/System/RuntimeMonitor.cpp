#include "System/RuntimeMonitor.hpp"

namespace PHX
{

bool RuntimeMonitor::sRunning = false;

void RuntimeMonitor::Update()
{
    sRunning = true;
}

bool RuntimeMonitor::IsRunning()
{
    return sRunning;
}

}
