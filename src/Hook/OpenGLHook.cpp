#include "Hook/OpenGLHook.hpp"

#include "Hook/HookManager.hpp"
#include "Graphics/OpenGLFunctionTable.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool OpenGLHook::Initialize()
{
    Logger::Info("Initializing OpenGLHook");

    if (!HookManager::Initialize())
    {
        Logger::Error("HookManager initialization failed");
        return false;
    }

    if (!OpenGLFunctionTable::Initialize())
    {
        Logger::Error("OpenGLFunctionTable initialization failed");
        return false;
    }

    if (!HookManager::InstallOpenGLHooks())
    {
        Logger::Error("InstallOpenGLHooks failed");
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
    HookManager::RemoveOpenGLHooks();

    OpenGLFunctionTable::Shutdown();

    HookManager::Shutdown();

    Logger::Info("OpenGLHook shutdown");
}

void OpenGLHook::HookUseProgram()
{
    if (OpenGLFunctionTable::glUseProgramPtr)
        Logger::Info("glUseProgram ready");
}

void OpenGLHook::HookCompileShader()
{
    if (OpenGLFunctionTable::glCompileShaderPtr)
        Logger::Info("glCompileShader ready");
}

void OpenGLHook::HookLinkProgram()
{
    if (OpenGLFunctionTable::glLinkProgramPtr)
        Logger::Info("glLinkProgram ready");
}

}
