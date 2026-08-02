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
        Logger::Error("OpenGLFunctionTable initialization failed");
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
    if (OpenGLFunctionTable::glUseProgramPtr == nullptr)
    {
        Logger::Error("glUseProgram pointer is null");
        return;
    }

    Logger::Info("glUseProgram hook ready");
}

void OpenGLHook::HookCompileShader()
{
    if (OpenGLFunctionTable::glCompileShaderPtr == nullptr)
    {
        Logger::Error("glCompileShader pointer is null");
        return;
    }

    Logger::Info("glCompileShader hook ready");
}

void OpenGLHook::HookLinkProgram()
{
    if (OpenGLFunctionTable::glLinkProgramPtr == nullptr)
    {
        Logger::Error("glLinkProgram pointer is null");
        return;
    }

    Logger::Info("glLinkProgram hook ready");
}

}
