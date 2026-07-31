#include "ShaderManager.h"
#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

static GLuint gVertexShader = 0;
static GLuint gFragmentShader = 0;
static GLuint gProgram = 0;

static const char* DefaultVertexShader =
"#version 300 es\n"
"layout(location=0) in vec3 aPos;\n"
"void main(){\n"
"gl_Position=vec4(aPos,1.0);\n"
"}";

static const char* DefaultFragmentShader =
"#version 300 es\n"
"precision mediump float;\n"
"out vec4 FragColor;\n"
"void main(){\n"
"FragColor=vec4(1.0,1.0,1.0,1.0);\n"
"}";

bool ShaderManager::Initialize()
{
    gVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(gVertexShader,1,&DefaultVertexShader,nullptr);
    glCompileShader(gVertexShader);

    GLint success = 0;
    glGetShaderiv(gVertexShader,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        LOGE("Vertex Shader Compile Failed");
        return false;
    }

    LOGI("Vertex Shader OK");

    gFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(gFragmentShader,1,&DefaultFragmentShader,nullptr);
    glCompileShader(gFragmentShader);

    glGetShaderiv(gFragmentShader,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        LOGE("Fragment Shader Compile Failed");
        return false;
    }

    LOGI("Fragment Shader OK");

    gProgram = glCreateProgram();
    glAttachShader(gProgram,gVertexShader);
    glAttachShader(gProgram,gFragmentShader);
    glLinkProgram(gProgram);

    return true;
}
