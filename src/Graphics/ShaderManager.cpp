#include "Graphics/ShaderManager.hpp"
#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

bool ShaderManager::Initialize()
{
    Logger::Info("ShaderManager initializing...");

    ShaderLoader loader;

    if (!loader.LoadDefaultShaders())
    {
        Logger::Error("Failed to load default shaders.");
        return false;
    }

    Logger::Info("Creating OpenGL program...");

    mProgram = glCreateProgram();

    if (mProgram == 0)
    {
        Logger::Error("glCreateProgram failed.");
        return false;
    }

    Logger::Info("OpenGL program created.");

    Logger::Info("ShaderManager ready.");

    return true;
}

GLuint ShaderManager::GetProgram() const
{
    return mProgram;
}

}
