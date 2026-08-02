#include "Hook/OpenGLHook.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/HookManager.hpp"

namespace PHX
{

void (*Original_glUseProgram)(GLuint) = nullptr;

void Hook_glUseProgram(GLuint program)
{
    if (Original_glUseProgram)
    {
        Original_glUseProgram(program);
    }
}

bool InstallRenderHooks()
{
    auto target =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL("glUseProgram"));

    if (!target)
    {
        Logger::Error("glUseProgram not found");
        return false;
    }

    if (!HookManager::Install(
            target,
            reinterpret_cast<uintptr_t>(&Hook_glUseProgram),
            reinterpret_cast<uintptr_t*>(&Original_glUseProgram)))
    {
        Logger::Error("Failed to install glUseProgram hook");
        return false;
    }

    Logger::Info("glUseProgram hooked");

    return true;
}

bool RemoveRenderHooks()
{
    auto target =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL("glUseProgram"));

    if (!target)
        return false;

    return HookManager::Remove(target);
}

}
