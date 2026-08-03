#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class ShaderManager
{
public:

    bool Initialize();

    void Destroy();

    GLuint GetProgram() const;

private:

    bool CreateVertexShader();

    bool CreateFragmentShader();

    bool LinkProgram();

private:

    GLuint mVertexShader = 0;
    GLuint mFragmentShader = 0;
    GLuint mProgram = 0;
};

}
