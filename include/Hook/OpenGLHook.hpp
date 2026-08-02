#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

bool InstallRenderHooks();
bool RemoveRenderHooks();

extern void (*Original_glUseProgram)(GLuint);

void Hook_glUseProgram(GLuint program);

}
