#pragma once

#include <string>
#include <GLES3/gl3.h>

namespace PHX
{

class ShaderCompiler
{
public:

    static GLuint CompileVertex(
        const std::string& source);

    static GLuint CompileFragment(
        const std::string& source);

    static std::string GetLastError();

private:

    static GLuint Compile(
        GLenum type,
        const std::string& source);

private:

    static std::string sLastError;
};

}
