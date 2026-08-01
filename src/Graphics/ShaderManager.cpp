#include "Graphics/ShaderManager.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

namespace PHX
{

ShaderManager::ShaderManager()
    : mProgram(0)
{
}

ShaderManager::~ShaderManager()
{
    Destroy();
}

bool ShaderManager::Initialize()
{
    Destroy();

    const char* vsSource =
        "#version 300 es\n"
        "layout(location=0) in vec3 aPos;\n"
        "void main(){\n"
        "gl_Position=vec4(aPos,1.0);\n"
        "}";

    const char* fsSource =
        "#version 300 es\n"
        "precision mediump float;\n"
        "out vec4 FragColor;\n"
        "void main(){\n"
        "FragColor=vec4(1.0,1.0,1.0,1.0);\n"
        "}";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs,1,&vsSource,nullptr);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs,1,&fsSource,nullptr);
    glCompileShader(fs);

    mProgram = glCreateProgram();
    glAttachShader(mProgram,vs);
    glAttachShader(mProgram,fs);
    glLinkProgram(mProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    if (mProgram == 0)
    {
        LOGE("Failed creating shader program");
        return false;
    }

    LOGI("ShaderManager initialized");
    return true;
}

GLuint ShaderManager::LoadShader(GLenum,
                                 const std::string&)
{
    return 0;
}

GLuint ShaderManager::CreateProgram(const std::string&,
                                    const std::string&)
{
    return mProgram;
}

GLuint ShaderManager::GetProgram() const
{
    return mProgram;
}

void ShaderManager::Destroy()
{
    if (mProgram != 0)
    {
        glDeleteProgram(mProgram);
        mProgram = 0;
    }
}

}
