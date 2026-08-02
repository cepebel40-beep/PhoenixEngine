#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class OpenGLHook
{
public:

    static bool Initialize();

    static void Shutdown();

private:

    static void HookUseProgram();
    static void HookCompileShader();
    static void HookLinkProgram();

    static void APIENTRY HookedUseProgram(GLuint program);
    static void APIENTRY HookedCompileShader(GLuint shader);
    static void APIENTRY HookedLinkProgram(GLuint program);

    static void (APIENTRY* OriginalUseProgram)(GLuint);
    static void (APIENTRY* OriginalCompileShader)(GLuint);
    static void (APIENTRY* OriginalLinkProgram)(GLuint);
};

}
