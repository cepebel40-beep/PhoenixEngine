#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class ShaderManager
{
public:
    bool Initialize();

    GLuint GetProgram() const;

private:
    GLuint mProgram = 0;
};

}
