#include "Hook/OpenGLHook.hpp"

#include "Core/Logger.hpp"
#include "Memory/SymbolResolver.hpp"
#include "Hook/HookManager.hpp"
#include "Graphics/Renderer.hpp"
#include "Graphics/RenderContext.hpp"
#include "Graphics/ShaderInterceptor.hpp"

namespace PHX
{

GLuint (*Original_glCreateShader)(GLenum) = nullptr;

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

GLuint Hook_glCreateShader(GLenum type)
{
    GLuint shader = 0;

    if (Original_glCreateShader)
    {
        shader =
            Original_glCreateShader(type);
    }

    if (shader != 0)
    {
        ShaderInterceptor::OnCreateShader(
            shader,
            type);

        Logger::Info(
            "glCreateShader intercepted");
    }

    return shader;
}

void Hook_glUseProgram(GLuint program)
{
    if (sFirstProgram)
    {
        Logger::Info(
            "First OpenGL shader detected");

        sFirstProgram = false;
    }

    if (program != sCurrentProgram)
    {
        sCurrentProgram = program;

        RenderContext::SetProgram(
            program);

        RenderContext::BeginFrame();
    }

    if (Original_glUseProgram)
    {
        Original_glUseProgram(
            program);
    }

    RenderFrame();
}

void Hook_glBindTexture(
    GLenum target,
    GLuint texture)
{
    RenderContext::SetTexture(
        texture);

    if (Original_glBindTexture)
    {
        Original_glBindTexture(
            target,
            texture);
    }
}

void Hook_glDrawElements(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void* indices)
{
    RenderContext::IncrementDrawCall();

    if (Original_glDrawElements)
    {
        Original_glDrawElements(
            mode,
            count,
            type,
            indices);
    }

    RenderFrame();
}

void Hook_glDrawArrays(
    GLenum mode,
    GLint first,
    GLsizei count)
{
    RenderContext::IncrementDrawCall();

    if (Original_glDrawArrays)
    {
        Original_glDrawArrays(
            mode,
            first,
            count);
    }

    RenderFrame();
}

bool InstallOpenGLHooks()
{
    bool success = true;

    auto createShader =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glCreateShader"));

    if (createShader)
    {
        if (!HookManager::Install(
                createShader,
                reinterpret_cast<uintptr_t>(
                    &Hook_glCreateShader),
                reinterpret_cast<uintptr_t*>(
                    &Original_glCreateShader)))
        {
            Logger::Error(
                "Failed to hook glCreateShader");

            success = false;
        }
    }

    auto useProgram =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glUseProgram"));

    if (useProgram)
    {
        if (!HookManager::Install(
                useProgram,
                reinterpret_cast<uintptr_t>(
                    &Hook_glUseProgram),
                reinterpret_cast<uintptr_t*>(
                    &Original_glUseProgram)))
        {
            Logger::Error(
                "Failed to hook glUseProgram");

            success = false;
        }
    }

         auto bindTexture =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glBindTexture"));

    if (bindTexture)
    {
        if (!HookManager::Install(
                bindTexture,
                reinterpret_cast<uintptr_t>(
                    &Hook_glBindTexture),
                reinterpret_cast<uintptr_t*>(
                    &Original_glBindTexture)))
        {
            Logger::Error(
                "Failed to hook glBindTexture");

            success = false;
        }
    }

    auto drawElements =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawElements"));

    if (drawElements)
    {
        if (!HookManager::Install(
                drawElements,
                reinterpret_cast<uintptr_t>(
                    &Hook_glDrawElements),
                reinterpret_cast<uintptr_t*>(
                    &Original_glDrawElements)))
        {
            Logger::Error(
                "Failed to hook glDrawElements");

            success = false;
        }
    }

    auto drawArrays =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawArrays"));

    if (drawArrays)
    {
        if (!HookManager::Install(
                drawArrays,
                reinterpret_cast<uintptr_t>(
                    &Hook_glDrawArrays),
                reinterpret_cast<uintptr_t*>(
                    &Original_glDrawArrays)))
        {
            Logger::Error(
                "Failed to hook glDrawArrays");

            success = false;
        }
    }

    if (success)
    {
        Logger::Info(
            "OpenGL Hook Stage 10 ready");
    }

    return success;
}

bool RemoveOpenGLHooks()
{
    sCurrentProgram = 0;
    sFirstProgram = true;

    auto createShader =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glCreateShader"));

    if (createShader)
    {
        HookManager::Remove(
            createShader);
    }

    auto useProgram =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glUseProgram"));

    if (useProgram)
    {
        HookManager::Remove(
            useProgram);
    }

    auto bindTexture =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glBindTexture"));

    if (bindTexture)
    {
        HookManager::Remove(
            bindTexture);
    }

    auto drawElements =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawElements"));

    if (drawElements)
    {
        HookManager::Remove(
            drawElements);
    }

    auto drawArrays =
        reinterpret_cast<uintptr_t>(
            SymbolResolver::ResolveOpenGL(
                "glDrawArrays"));

    if (drawArrays)
    {
        HookManager::Remove(
            drawArrays);
    }

    RenderContext::Reset();

    Logger::Info(
        "OpenGL hooks removed");

    return true;
}

}
