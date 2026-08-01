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
};

}
