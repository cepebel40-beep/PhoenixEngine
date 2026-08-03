#pragma once

#include <string>
#include <unordered_map>

#include <GLES3/gl3.h>

namespace PHX
{

class ShaderCache
{
public:

    static bool Initialize();

    static void Shutdown();

    static void SetCurrentProgram(GLuint program);

    static GLuint GetCurrentProgram();

    static bool Has(const std::string& name);

    static GLuint Get(const std::string& name);

    static void Store(const std::string& name,
                      GLuint program);

private:

    static GLuint sCurrentProgram;

    static std::unordered_map<std::string, GLuint> sPrograms;
};

}
