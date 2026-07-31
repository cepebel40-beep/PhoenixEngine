#pragma once

#include <GLES3/gl3.h>
#include <string>

namespace PHX
{

class ShaderManager
{
public:
    ShaderManager();

    bool Initialize();

    GLuint LoadShader(GLenum type,
                      const std::string& source);

    GLuint CreateProgram(const std::string& vertexSource,
                         const std::string& fragmentSource);

    void Destroy();

private:
    GLuint mProgram;
};

}
