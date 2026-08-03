#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

bool InstallOpenGLHooks();
bool RemoveOpenGLHooks();

extern void (*Original_glUseProgram)(GLuint);
extern void (*Original_glBindTexture)(GLenum, GLuint);

void Hook_glUseProgram(GLuint program);
void Hook_glBindTexture(GLenum target, GLuint texture);

}
