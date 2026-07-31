#pragma once

#include <GLES3/gl3.h>
#include <string>
#include <unordered_map>

namespace PHX
{

class ShaderCache
{
public:
    static bool Has(const std::string& name);

    static GLuint Get(const std::string& name);

    static void Store(const std::string& name, GLuint program);

    static void Clear();

private:
    static std::unordered_map<std::string, GLuint> mPrograms;
};

}
