#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class OpenGLRuntime
{
public:
    static bool Initialize();

    static void Shutdown();

    static GLuint CurrentProgram();
};

}
