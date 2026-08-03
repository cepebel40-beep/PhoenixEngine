#include "Hook/DrawHook.hpp"

#include "Hook/HookManager.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Core/Logger.hpp"
#include "Graphics/Renderer.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

static void (*Original_glDrawElements)(
        GLenum,
        GLsizei,
        GLenum,
        const void*) = nullptr;

static void (*Original_glDrawArrays)(
        GLenum,
        GLint,
        GLsizei) = nullptr;

static void Hook_glDrawElements(
        GLenum mode,
        GLsizei count,
        GLenum type,
        const void* indices)
{
    RenderFrame();

    if (Original_glDrawElements)
    {
        Original_glDrawElements(
                mode,
                count,
                type,
                indices);
    }
}

static void Hook_glDrawArrays(
        GLenum mode,
        GLint first,
        GLsizei count)
{
    RenderFrame();

    if (Original_glDrawArrays)
    {
        Original_glDrawArrays(
                mode,
                first,
                count);
    }
}

bool InstallDrawHooks()
{
    bool success = true;

    auto drawElements =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawElements"));

    if (drawElements)
    {
        success &= HookManager::Install(
                drawElements,
                reinterpret_cast<uintptr_t>(
                    &Hook_glDrawElements),
                reinterpret_cast<uintptr_t*>(
                    &Original_glDrawElements));
    }

    auto drawArrays =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawArrays"));

    if (drawArrays)
    {
        success &= HookManager::Install(
                drawArrays,
                reinterpret_cast<uintptr_t>(
                    &Hook_glDrawArrays),
                reinterpret_cast<uintptr_t*>(
                    &Original_glDrawArrays));
    }

    if (success)
        Logger::Info("Draw hooks installed");
    else
        Logger::Error("Failed installing Draw hooks");

    return success;
}

bool RemoveDrawHooks()
{
    bool success = true;

    auto drawElements =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawElements"));

    if (drawElements)
        success &= HookManager::Remove(drawElements);

    auto drawArrays =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawArrays"));

    if (drawArrays)
        success &= HookManager::Remove(drawArrays);

    return success;
}

}
