#include "Graphics/UniformManager.hpp"

namespace PHX
{

GLuint UniformManager::sProgram = 0;

void UniformManager::SetProgram(GLuint program)
{
    sProgram = program;
}

void UniformManager::SetTime(float value)
{
    if(!sProgram)
        return;

    GLint location = glGetUniformLocation(sProgram,"u_Time");

    if(location >= 0)
        glUniform1f(location,value);
}

void UniformManager::SetResolution(float width,float height)
{
    if(!sProgram)
        return;

    GLint location = glGetUniformLocation(sProgram,"u_Resolution");

    if(location >= 0)
        glUniform2f(location,width,height);
}

}
