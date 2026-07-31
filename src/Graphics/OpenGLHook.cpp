
#include "Hook/OpenGLHook.hpp"

#include "Graphics/OpenGLHook.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

bool InstallOpenGLHooks()
{
    Logger::Info("Installing OpenGL hooks...");

    if (!OpenGLHook::Install())
    {
        Logger::Error("OpenGLHook::Install() failed.");
        return false;
    }

    Logger::Info("OpenGL hooks installed.");

    return true;
}

}
