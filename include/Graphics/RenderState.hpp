#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class RenderState
{
public:
    static bool Initialize();

    static void SetProgram(GLuint program);
    static GLuint GetProgram();

    static void Reset();

private:
    static GLuint sCurrentProgram;
};

}
