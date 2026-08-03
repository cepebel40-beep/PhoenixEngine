#include "Graphics/ShaderManager.hpp"

#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

bool ShaderManager::Initialize()
{
    Destroy();

    if (!CreateVertexShader())
    {
        Logger::Error("Failed to create vertex shader");
        return false;
    }

    if (!CreateFragmentShader())
    {
        Logger::Error("Failed to create fragment shader");
        return false;
    }

    if (!LinkProgram())
    {
        Logger::Error("Failed to link shader program");
        return false;
    }

    Logger::Info("ShaderManager initialized");

    return true;
}

bool ShaderManager::CreateVertexShader()
{
    const char* source =
        "#version 300 es\n"
        "layout(location=0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(aPos,1.0);\n"
        "}";

    mVertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        mVertexShader,
        1,
        &source,
        nullptr);

    glCompileShader(mVertexShader);

    return (mVertexShader != 0);
}

bool ShaderManager::CreateFragmentShader()
{
    const char* source =
        "#version 300 es\n"
        "precision mediump float;\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0);\n"
        "}";

    mFragmentShader =
        glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        mFragmentShader,
        1,
        &source,
        nullptr);

    glCompileShader(mFragmentShader);

    return (mFragmentShader != 0);
}

bool ShaderManager::LinkProgram()
{
    mProgram = glCreateProgram();

    glAttachShader(
        mProgram,
        mVertexShader);

    glAttachShader(
        mProgram,
        mFragmentShader);

    glLinkProgram(mProgram);

    glDeleteShader(mVertexShader);
    glDeleteShader(mFragmentShader);

    mVertexShader = 0;
    mFragmentShader = 0;

    return (mProgram != 0);
}

GLuint ShaderManager::GetProgram() const
{
    return mProgram;
}

void ShaderManager::Destroy()
{
    if (mProgram)
    {
        glDeleteProgram(mProgram);
        mProgram = 0;
    }

    if (mVertexShader)
    {
        glDeleteShader(mVertexShader);
        mVertexShader = 0;
    }

    if (mFragmentShader)
    {
        glDeleteShader(mFragmentShader);
        mFragmentShader = 0;
    }
}

}
