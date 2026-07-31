#include "Graphics/OpenGLRuntime.hpp"

namespace PHX
{

bool OpenGLRuntime::Initialize()
{
    return true;
}

void OpenGLRuntime::Shutdown()
{
}

GLuint OpenGLRuntime::CurrentProgram()
{
    GLint program = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &program);
    return static_cast<GLuint>(program);
}

}
