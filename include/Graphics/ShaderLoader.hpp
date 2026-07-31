#pragma once

namespace PHX
{

class ShaderLoader
{
public:
    bool LoadDefaultShaders();

private:
    bool ReadTextFile(const char* path, char*& buffer);
};

}
