#include "Hook/OpenGLHooks.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/HookManager.hpp"

namespace PHX
{

void (*Original_glUseProgram)(GLuint) = nullptr;

void Hook_glUseProgram(GLuint program)
{
    if (Original_glUseProgram)
        Original_glUseProgram(program);
}

bool InstallOpenGLHooks()
{
    auto target =
        (uintptr_t)SymbolResolver::ResolveOpenGL("glUseProgram");

    if (!target)
    {
        Logger::Error("glUseProgram not found");
        return false;
    }

    if (!HookManager::Install(
            target,
            (uintptr_t)&Hook_glUseProgram,
            (uintptr_t*)&Original_glUseProgram))
    {
        Logger::Error("Failed hook glUseProgram");
        return false;
    }

    Logger::Info("Hooked glUseProgram");

    return true;
}

void RemoveOpenGLHooks()
{
    auto target =
        (uintptr_t)SymbolResolver::ResolveOpenGL("glUseProgram");

    if (target)
        HookManager::Remove(target);
}

}
