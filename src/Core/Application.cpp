#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include "Core/RuntimeMonitor.hpp"

namespace PHX
{

bool Application::Start()
{
    if (!InitializeEngine())
        return false;

    #include "System/RuntimeMonitor.hpp"

    return true;
}

}
