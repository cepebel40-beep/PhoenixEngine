#pragma once

#include <string>
#include <GLES3/gl3.h>

namespace PHX
{

class ShaderPipeline
{
public:
    static GLuint Create(const std::string& name,
                         GLuint vertexShader,
                         GLuint fragmentShader);

    static void Use(GLuint program);

    static void Destroy(GLuint program);
};

}
