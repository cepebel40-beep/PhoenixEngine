#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

bool InitializeRenderer();

GLuint GetRendererProgram();

void ShutdownRenderer();

}
