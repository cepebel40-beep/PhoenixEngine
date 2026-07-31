#include "Core/Application.hpp"
#include "Core/Engine.hpp"

namespace PHX
{

bool Application::Start()
{
    return InitializeEngine();
}

}
