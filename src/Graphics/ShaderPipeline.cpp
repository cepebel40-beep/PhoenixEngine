#include "Graphics/ShaderPipeline.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

static ShaderManager gShader;

bool InitializeShaderPipeline()
{
    Logger::Info("Initializing Shader Pipeline...");

    if (!gShader.Initialize())
    {
        Logger::Error("Failed to initialize Shader Pipeline");
        return false;
    }

    Logger::Info("Shader Pipeline initialized");

    return true;
}

GLuint GetShaderProgram()
{
    return gShader.GetProgram();
}

void ShutdownShaderPipeline()
{
    gShader.Destroy();

    Logger::Info("Shader Pipeline destroyed");
}

}
