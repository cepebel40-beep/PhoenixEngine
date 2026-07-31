
#include "Graphics/OpenGLHook.hpp"

namespace PHX
{

bool OpenGLHook::sInstalled = false;

bool OpenGLHook::Install()
{
    sInstalled = true;
    return true;
}

void OpenGLHook::Remove()
{
    sInstalled = false;
}

bool OpenGLHook::IsInstalled()
{
    return sInstalled;
}

}
