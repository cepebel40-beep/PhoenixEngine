#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

bool InstallOpenGLHooks();
bool RemoveOpenGLHooks();

extern void (*Original_glUseProgram)(GLuint);

void Hook_glUseProgram(GLuint program);

}
