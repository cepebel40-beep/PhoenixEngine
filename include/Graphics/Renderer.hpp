#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

bool InitializeRenderer();

void RenderFrame();

GLuint GetRendererProgram();

void ShutdownRenderer();

}
