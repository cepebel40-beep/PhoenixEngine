#include "Graphics/ShaderCache.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

GLuint ShaderCache::sCurrentProgram = 0;

std::unordered_map<std::string, GLuint>
ShaderCache::sPrograms;

bool ShaderCache::Initialize()
{
    sPrograms.clear();

    sCurrentProgram = 0;

    Logger::Info("ShaderCache initialized");

    return true;
}

void ShaderCache::Shutdown()
{
    sPrograms.clear();

    sCurrentProgram = 0;

    Logger::Info("ShaderCache shutdown");
}

void ShaderCache::SetCurrentProgram(GLuint program)
{
    sCurrentProgram = program;
}

GLuint ShaderCache::GetCurrentProgram()
{
    return sCurrentProgram;
}

bool ShaderCache::Has(const std::string& name)
{
    return sPrograms.find(name) != sPrograms.end();
}

GLuint ShaderCache::Get(const std::string& name)
{
    auto it = sPrograms.find(name);

    if (it == sPrograms.end())
        return 0;

    return it->second;
}

void ShaderCache::Store(const std::string& name,
                        GLuint program)
{
    sPrograms[name] = program;
}

}
