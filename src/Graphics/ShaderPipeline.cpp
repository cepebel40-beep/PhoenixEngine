#include "Graphics/ShaderPipeline.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Graphics/RenderState.hpp"
#include "Graphics/UniformManager.hpp"

namespace PHX
{

bool ShaderPipeline::Initialize()
{
    return ShaderManager::Initialize();
}

void ShaderPipeline::Shutdown()
{
    ShaderManager::Shutdown();
    RenderState::Reset();
}

void ShaderPipeline::Update()
{
    UniformManager::SetProgram(RenderState::GetProgram());
}

}
