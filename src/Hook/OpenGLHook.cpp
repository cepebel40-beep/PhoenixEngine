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
    Logger::Info("Preparing glUseProgram hook");
}

void OpenGLHook::HookCompileShader()
{
    Logger::Info("Preparing glCompileShader hook");
}

void OpenGLHook::HookLinkProgram()
{
    Logger::Info("Preparing glLinkProgram hook");
}

void OpenGLHook::HookedUseProgram(GLuint program)
{
    Logger::Info("Hooked glUseProgram");

    if (OpenGLFunctionTable::glUseProgramPtr)
    {
        OpenGLFunctionTable::glUseProgramPtr(program);
    }
}

void OpenGLHook::HookedCompileShader(GLuint shader)
{
    Logger::Info("Hooked glCompileShader");

    if (OpenGLFunctionTable::glCompileShaderPtr)
    {
        OpenGLFunctionTable::glCompileShaderPtr(shader);
    }
}

void OpenGLHook::HookedLinkProgram(GLuint program)
{
    Logger::Info("Hooked glLinkProgram");

    if (OpenGLFunctionTable::glLinkProgramPtr)
    {
        OpenGLFunctionTable::glLinkProgramPtr(program);
    }
}

}
