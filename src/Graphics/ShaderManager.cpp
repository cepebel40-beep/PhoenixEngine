#include "Graphics/ShaderManager.hpp"
#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

static const char* DefaultVertexShader = R"(#version 300 es

layout(location = 0) in vec3 aPosition;

void main()
{
    gl_Position = vec4(aPosition, 1.0);
}

)";

bool ShaderManager::Initialize()
{
    Logger::Info("ShaderManager initializing...");

    ShaderLoader loader;

    if (!loader.LoadDefaultShaders())
    {
        Logger::Error("Failed to load default shaders.");
        return false;
    }

    mProgram = glCreateProgram();

    if (!mProgram)
    {
        Logger::Error("Failed to create OpenGL Program.");
        return false;
    }

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    if (!vertexShader)
    {
        Logger::Error("Failed to create Vertex Shader.");
        return false;
    }

    glShaderSource(vertexShader, 1, &DefaultVertexShader, nullptr);
    glCompileShader(vertexShader);

    GLint compiled = GL_FALSE;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);

    if (compiled != GL_TRUE)
    {
        Logger::Error("Vertex Shader compilation failed.");

        glDeleteShader(vertexShader);

        return false;
    }

    Logger::Info("Vertex Shader compiled successfully.");

    glDeleteShader(vertexShader);

    Logger::Info("ShaderManager ready.");

    return true;
}

GLuint ShaderManager::GetProgram() const
{
    return mProgram;
}

}
