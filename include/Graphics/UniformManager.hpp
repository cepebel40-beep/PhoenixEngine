#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class UniformManager
{
public:
    static void SetProgram(GLuint program);

    static void SetTime(float value);

    static void SetResolution(float width, float height);

private:
    static GLuint sProgram;
};

}
