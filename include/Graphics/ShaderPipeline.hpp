#pragma once

#include <string>
#include <GLES3/gl3.h>

namespace PHX
{

class ShaderPipeline
{
public:
    static GLuint Create(const std::string& name,
                         const std::string& vertexSource,
                         const std::string& fragmentSource);

    static void Use(GLuint program);

    static void Destroy(GLuint program);
};

}
