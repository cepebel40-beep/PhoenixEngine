#include "Graphics/RenderContext.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

GLuint RenderContext::sProgram = 0;
GLuint RenderContext::sTexture = 0;
GLuint RenderContext::sFramebuffer = 0;
GLuint RenderContext::sVertexArray = 0;

GLint RenderContext::sViewportX = 0;
GLint RenderContext::sViewportY = 0;
GLsizei RenderContext::sViewportWidth = 0;
GLsizei RenderContext::sViewportHeight = 0;

uint64_t RenderContext::sFrameCount = 0;
uint64_t RenderContext::sDrawCallCount = 0;

bool RenderContext::Initialize()
{
    Reset();

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
    sFramebuffer = 0;
    sVertexArray = 0;

    sViewportX = 0;
    sViewportY = 0;
    sViewportWidth = 0;
    sViewportHeight = 0;

    sFrameCount = 0;
    sDrawCallCount = 0;
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

void RenderContext::SetFramebuffer(GLuint framebuffer)
{
    sFramebuffer = framebuffer;
}

GLuint RenderContext::GetFramebuffer()
{
    return sFramebuffer;
}

void RenderContext::SetVertexArray(GLuint vao)
{
    sVertexArray = vao;
}

GLuint RenderContext::GetVertexArray()
{
    return sVertexArray;
}

void RenderContext::SetViewport(GLint x,
                                GLint y,
                                GLsizei width,
                                GLsizei height)
{
    sViewportX = x;
    sViewportY = y;
    sViewportWidth = width;
    sViewportHeight = height;
}

void RenderContext::GetViewport(GLint& x,
                                GLint& y,
                                GLsizei& width,
                                GLsizei& height)
{
    x = sViewportX;
    y = sViewportY;
    width = sViewportWidth;
    height = sViewportHeight;
}

void RenderContext::BeginFrame()
{
    ++sFrameCount;
    sDrawCallCount = 0;
}

void RenderContext::EndFrame()
{
}

uint64_t RenderContext::GetFrameCount()
{
    return sFrameCount;
}

uint64_t RenderContext::GetDrawCallCount()
{
    return sDrawCallCount;
}

void RenderContext::IncrementDrawCall()
{
    ++sDrawCallCount;
}

}
