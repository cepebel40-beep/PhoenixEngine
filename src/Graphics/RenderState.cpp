#include "Graphics/RenderState.hpp"

namespace PHX
{

GLuint RenderState::sCurrentProgram = 0;

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
