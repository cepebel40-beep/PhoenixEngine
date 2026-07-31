#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include "System/RuntimeMonitor.hpp"

namespace PHX
{

bool Application::Start()
{
    if (!InitializeEngine())
        return false;

    return true;
}

}
