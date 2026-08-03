#include "Graphics/RenderState.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

GLuint RenderState::sCurrentProgram = 0;

bool RenderState::Initialize()
{
    sCurrentProgram = 0;

    Logger::Info("RenderState initialized");

    return true;
}

void RenderState::SetProgram(GLuint program)
{
    sCurrentProgram = program;
}

GLuint RenderState::GetProgram()
{
    return sCurrentProgram;
}

void RenderState::Reset()
{
    sCurrentProgram = 0;
}

}
