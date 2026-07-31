#include "Graphics/ShaderPipeline.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

static ShaderManager gShaderManager;

bool ShaderPipeline::Initialize()
{
    Logger::Info("Initializing Shader Pipeline...");

    if (!gShaderManager.Initialize())
    {
        Logger::Error("Failed to initialize Shader Pipeline");
        return false;
    }

    Logger::Info("Shader Pipeline initialized");

    return true;
}

void ShaderPipeline::Update()
{
    // Runtime update (reserved)
}

void ShaderPipeline::Shutdown()
{
    gShaderManager.Destroy();

    Logger::Info("Shader Pipeline destroyed");
}

}
