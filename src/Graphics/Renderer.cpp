#include "Graphics/Renderer.hpp"

#include "Graphics/ShaderManager.hpp"
#include "Graphics/RenderState.hpp"
#include "Hook/OpenGLHook.hpp"
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

    if (Original_glUseProgram)
    {
        Original_glUseProgram(gProgram);
    }
    else
    {
        glUseProgram(gProgram);
    }

    sRendererReady = true;

    Logger::Info("Shader program activated.");
    Logger::Info("Renderer initialized successfully.");

    return true;
}

void RenderFrame()
{
    if (!sRendererReady)
        return;

    if (gProgram == 0)
        return;

    if (Original_glUseProgram)
    {
        Original_glUseProgram(gProgram);
    }
    else
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
