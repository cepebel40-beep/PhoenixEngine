#include "Graphics/ShaderCache.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

GLuint ShaderCache::sCurrentProgram = 0;

bool ShaderCache::Initialize()
{
    sCurrentProgram = 0;

    Logger::Info("ShaderCache initialized");

    return true;
}

void ShaderCache::Shutdown()
{
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

}
