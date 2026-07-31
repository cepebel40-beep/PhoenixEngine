#include "Graphics/ShaderManager.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

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
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs,1,&DefaultVertexShader,nullptr);
    glCompileShader(vs);

    GLint success = GL_FALSE;
    glGetShaderiv(vs,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        LOGE("Vertex shader compile failed");
        return false;
    }

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs,1,&DefaultFragmentShader,nullptr);
    glCompileShader(fs);

    glGetShaderiv(fs,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        LOGE("Fragment shader compile failed");
        glDeleteShader(vs);
        return false;
    }

    mProgram = glCreateProgram();
    glAttachShader(mProgram,vs);
    glAttachShader(mProgram,fs);
    glLinkProgram(mProgram);

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
