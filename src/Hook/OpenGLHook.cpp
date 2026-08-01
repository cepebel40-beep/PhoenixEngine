#include "Hook/OpenGLHook.hpp"

#include "Graphics/OpenGLFunctionTable.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool OpenGLHook::Initialize()
{
    Logger::Info("Initializing OpenGLHook");

    if (!OpenGLFunctionTable::Initialize())
    {
        Logger::Error("Failed to initialize OpenGLFunctionTable");
        return false;
    }

    HookUseProgram();
    HookCompileShader();
    HookLinkProgram();

    Logger::Info("OpenGLHook initialized");

    return true;
}

void OpenGLHook::Shutdown()
{
    OpenGLFunctionTable::Shutdown();

    Logger::Info("OpenGLHook shutdown");
}

void OpenGLHook::HookUseProgram()
{
    if (OpenGLFunctionTable::glUseProgramPtr)
    {
        Logger::Info("glUseProgram located");
    }
}

void OpenGLHook::HookCompileShader()
{
    if (OpenGLFunctionTable::glCompileShaderPtr)
    {
        Logger::Info("glCompileShader located");
    }
}

void OpenGLHook::HookLinkProgram()
{
    if (OpenGLFunctionTable::glLinkProgramPtr)
    {
        Logger::Info("glLinkProgram located");
    }
}

}
