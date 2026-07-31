#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include "Core/RuntimeMonitor.hpp"

namespace PHX
{

bool Application::Start()
{
    if (!InitializeEngine())
        return false;

    RuntimeMonitor::Update();

    return true;
}

}
