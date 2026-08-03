#include "Graphics/Renderer.hpp"

#include "Graphics/ShaderManager.hpp"
#include "Graphics/RenderState.hpp"
#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

static ShaderManager gShaderManager;
static GLuint gProgram = 0;
static bool sRendererReady = false;

bool InitializeRenderer()
{
    Logger::Info("Initializing Renderer...");

    if (!gShaderManager.Initialize())
    {
        Logger::Error("Failed to initialize ShaderManager.");
        return false;
    }

    gProgram = gShaderManager.GetProgram();

    RenderState::SetProgram(gProgram);

    if (gProgram == 0)
    {
        Logger::Error("Shader program is invalid.");
        return false;
    }

    glUseProgram(gProgram);

    sRendererReady = true;

    Logger::Info("Shader program activated.");
    Logger::Info("Renderer initialized successfully.");

    return true;
}

void RenderFrame()
{
    if (!sRendererReady)
        return;

    /*
        TODO:
        Saat OpenGL Hook sudah final,
        glUseProgram() di sini akan diganti menggunakan
        Original_glUseProgram()
        agar tidak terjadi recursive hook.
    */

    if (gProgram != 0)
    {
        glUseProgram(gProgram);
    }
}

GLuint GetRendererProgram()
{
    return gProgram;
}

void ShutdownRenderer()
{
    gShaderManager.Destroy();

    gProgram = 0;

    RenderState::Reset();

    sRendererReady = false;

    Logger::Info("Renderer shutdown complete.");
}

}
