#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class RenderContext
{
public:

    static bool Initialize();

    static void Shutdown();

    static void SetProgram(GLuint program);
    static GLuint GetProgram();

    static void SetTexture(GLuint texture);
    static GLuint GetTexture();

    static void Reset();

private:

    static GLuint sProgram;
    static GLuint sTexture;
};

}
