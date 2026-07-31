#include "Graphics/ShaderCache.hpp"

namespace PHX
{

std::unordered_map<std::string, GLuint> ShaderCache::mPrograms;

bool ShaderCache::Has(const std::string& name)
{
    return mPrograms.find(name) != mPrograms.end();
}

GLuint ShaderCache::Get(const std::string& name)
{
    auto it = mPrograms.find(name);

    if(it == mPrograms.end())
        return 0;

    return it->second;
}

void ShaderCache::Store(const std::string& name, GLuint program)
{
    mPrograms[name] = program;
}

void ShaderCache::Clear()
{
    mPrograms.clear();
}

}
