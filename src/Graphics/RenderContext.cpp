#include "Graphics/RenderContext.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

GLuint RenderContext::sProgram = 0;
GLuint RenderContext::sTexture = 0;

bool RenderContext::Initialize()
{
    sProgram = 0;
    sTexture = 0;

    Logger::Info("RenderContext initialized");

    return true;
}

void RenderContext::Shutdown()
{
    Reset();

    Logger::Info("RenderContext shutdown");
}

void RenderContext::Reset()
{
    sProgram = 0;
    sTexture = 0;
}

void RenderContext::SetProgram(GLuint program)
{
    sProgram = program;
}

GLuint RenderContext::GetProgram()
{
    return sProgram;
}

void RenderContext::SetTexture(GLuint texture)
{
    sTexture = texture;
}

GLuint RenderContext::GetTexture()
{
    return sTexture;
}

}
