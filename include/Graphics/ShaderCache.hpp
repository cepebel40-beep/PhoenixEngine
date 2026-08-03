#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class ShaderCache
{
public:

    static bool Initialize();

    static void Shutdown();

    static void SetCurrentProgram(GLuint program);

    static GLuint GetCurrentProgram();

private:

    static GLuint sCurrentProgram;
};

}
