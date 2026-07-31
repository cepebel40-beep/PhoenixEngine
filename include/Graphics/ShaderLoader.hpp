#pragma once

#include <string>

namespace PHX
{

class ShaderLoader
{
public:
    bool LoadDefaultShaders();

private:
    bool ReadTextFile(const char* path, std::string& buffer);
};

}
