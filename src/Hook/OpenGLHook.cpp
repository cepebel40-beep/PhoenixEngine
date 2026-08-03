#include "Hook/OpenGLHook.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/HookManager.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/RenderContext.hpp"

namespace PHX
{

void (*Original_glUseProgram)(GLuint) = nullptr;

static bool sFirstProgram = true;
static GLuint sCurrentProgram = 0;

void Hook_glUseProgram(GLuint program)
{
    if (sFirstProgram)
    {
        Logger::Info("First OpenGL shader program detected");
        sFirstProgram = false;
    }

    if (program != sCurrentProgram)
    {
        sCurrentProgram = program;
        RenderContext::SetProgram(program);
    }

    /*
     * Panggil OpenGL asli terlebih dahulu.
     * Renderer nantinya juga akan memakai
     * Original_glUseProgram agar tidak
     * terjadi recursive hook.
     */
    if (Original_glUseProgram)
    {
        Original_glUseProgram(program);
    }

    RenderFrame();
}

bool InstallOpenGLHooks()
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

    Logger::Info("glUseProgram hook installed");

    return true;
}

bool RemoveOpenGLHooks()
{
    auto target =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL("glUseProgram"));

    if (!target)
        return false;

    sCurrentProgram = 0;
    sFirstProgram = true;

    Logger::Info("Removing glUseProgram hook");

    return HookManager::Remove(target);
}

}
