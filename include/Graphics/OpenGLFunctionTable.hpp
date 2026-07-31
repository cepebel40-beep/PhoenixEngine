#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class OpenGLFunctionTable
{
public:
    static bool Initialize();

    static void Shutdown();

    static PFNGLUSEPROGRAMPROC glUseProgramPtr;
    static PFNGLLINKPROGRAMPROC glLinkProgramPtr;
    static PFNGLCOMPILESHADERPROC glCompileShaderPtr;
};

}
