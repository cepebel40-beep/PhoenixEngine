#include "Graphics/ShaderManager.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "Phoenix", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "Phoenix", __VA_ARGS__)

namespace PHX
{

static const char* DefaultVertexShader =
"#version 300 es\n"
"layout(location=0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos,1.0);\n"
"}";

static const char* DefaultFragmentShader =
"#version 300 es\n"
"precision mediump float;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0,1.0,1.0,1.0);\n"
"}";

bool ShaderManager::Initialize()
{
    GLint success = GL_FALSE;

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &DefaultVertexShader, nullptr);
    glCompileShader(vs);

    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        LOGE("Vertex shader compile failed");
        glDeleteShader(vs);
        return false;
    }

    LOGI("Vertex shader compiled");

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &DefaultFragmentShader, nullptr);
    glCompileShader(fs);

    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        LOGE("Fragment shader compile failed");
        glDeleteShader(vs);
        glDeleteShader(fs);
        return false;
    }

    LOGI("Fragment shader compiled");

    mProgram = glCreateProgram();

    glAttachShader(mProgram, vs);
    glAttachShader(mProgram, fs);

    glLinkProgram(mProgram);

    glGetProgramiv(mProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        char infoLog[1024] = {};
        glGetProgramInfoLog(mProgram, sizeof(infoLog), nullptr, infoLog);

        LOGE("Program link failed: %s", infoLog);

        glDeleteProgram(mProgram);
        mProgram = 0;

        glDeleteShader(vs);
        glDeleteShader(fs);

        return false;
    }

    LOGI("Program linked");

    glValidateProgram(mProgram);

    glGetProgramiv(mProgram, GL_VALIDATE_STATUS, &success);

    if (!success)
    {
        char infoLog[1024] = {};
        glGetProgramInfoLog(mProgram, sizeof(infoLog), nullptr, infoLog);

        LOGE("Program validation failed: %s", infoLog);

        glDeleteProgram(mProgram);
        mProgram = 0;

        glDeleteShader(vs);
        glDeleteShader(fs);

        return false;
    }

    LOGI("Program validated");

    glDeleteShader(vs);
    glDeleteShader(fs);

    LOGI("ShaderManager initialized");

    return true;
}

GLuint ShaderManager::GetProgram() const
{
    return mProgram;
}

}
