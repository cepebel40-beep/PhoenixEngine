#include "Hook/OpenGLHook.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/HookManager.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/RenderContext.hpp"

namespace PHX
{

void (*Original_glUseProgram)(GLuint) = nullptr;

void (*Original_glBindTexture)(
    GLenum,
    GLuint) = nullptr;

void (*Original_glDrawElements)(
    GLenum,
    GLsizei,
    GLenum,
    const void*) = nullptr;

void (*Original_glDrawArrays)(
    GLenum,
    GLint,
    GLsizei) = nullptr;

static bool sFirstProgram = true;
static GLuint sCurrentProgram = 0;

void Hook_glUseProgram(GLuint program)
{
    if (sFirstProgram)
    {
        Logger::Info("First OpenGL shader detected");
        sFirstProgram = false;
    }

    if (program != sCurrentProgram)
    {
        sCurrentProgram = program;
        RenderContext::SetProgram(program);
    }

    if (Original_glUseProgram)
        Original_glUseProgram(program);

    RenderFrame();
}

void Hook_glBindTexture(
    GLenum target,
    GLuint texture)
{
    RenderContext::SetTexture(texture);

    if (Original_glBindTexture)
        Original_glBindTexture(target, texture);
}

void Hook_glDrawElements(
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

void Hook_glDrawArrays(
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

bool InstallOpenGLHooks()
{
    bool success = true;

    auto useProgram =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glUseProgram"));

    if (useProgram)
    {
        success &= HookManager::Install(
            useProgram,
            reinterpret_cast<uintptr_t>(
                &Hook_glUseProgram),
            reinterpret_cast<uintptr_t*>(
                &Original_glUseProgram));
    }

    auto bindTexture =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glBindTexture"));

    if (bindTexture)
    {
        success &= HookManager::Install(
            bindTexture,
            reinterpret_cast<uintptr_t>(
                &Hook_glBindTexture),
            reinterpret_cast<uintptr_t*>(
                &Original_glBindTexture));
    }

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
        Logger::Info("OpenGL hook stage 6 ready");

    return success;
}

bool RemoveOpenGLHooks()
{
    sCurrentProgram = 0;
    sFirstProgram = true;

    auto useProgram =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glUseProgram"));

    if (useProgram)
        HookManager::Remove(useProgram);

    auto bindTexture =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glBindTexture"));

    if (bindTexture)
        HookManager::Remove(bindTexture);

    auto drawElements =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawElements"));

    if (drawElements)
        HookManager::Remove(drawElements);

    auto drawArrays =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawArrays"));

    if (drawArrays)
        HookManager::Remove(drawArrays);

    Logger::Info("OpenGL hooks removed");

    return true;
}

}
