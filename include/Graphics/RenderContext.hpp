#pragma once

#include <GLES3/gl3.h>
#include <cstdint>

namespace PHX
{

class RenderContext
{
public:

    static bool Initialize();

    static void Shutdown();

    static void Reset();

    static void SetProgram(GLuint program);
    static GLuint GetProgram();

    static void SetTexture(GLuint texture);
    static GLuint GetTexture();

    static void SetFramebuffer(GLuint framebuffer);
    static GLuint GetFramebuffer();

    static void SetVertexArray(GLuint vao);
    static GLuint GetVertexArray();

    static void SetViewport(GLint x,
                            GLint y,
                            GLsizei width,
                            GLsizei height);

    static void GetViewport(GLint& x,
                            GLint& y,
                            GLsizei& width,
                            GLsizei& height);

    static void BeginFrame();

    static void EndFrame();

    static uint64_t GetFrameCount();

    static uint64_t GetDrawCallCount();

    static void IncrementDrawCall();

private:

    static GLuint sProgram;
    static GLuint sTexture;
    static GLuint sFramebuffer;
    static GLuint sVertexArray;

    static GLint sViewportX;
    static GLint sViewportY;
    static GLsizei sViewportWidth;
    static GLsizei sViewportHeight;

    static uint64_t sFrameCount;
    static uint64_t sDrawCallCount;
};

}
