#include "Graphics/ShaderCompiler.hpp"

#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

namespace PHX
{

GLuint ShaderCompiler::Compile(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);

    const char* src = source.c_str();

    glShaderSource(shader,1,&src,nullptr);
    glCompileShader(shader);

    GLint success = GL_FALSE;

    glGetShaderiv(shader,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        char log[1024]{};

        glGetShaderInfoLog(shader,sizeof(log),nullptr,log);

        LOGE("%s",log);

        glDeleteShader(shader);

        return 0;
    }

    LOGI("Shader compiled");

    return shader;
}

GLuint ShaderCompiler::CompileVertex(const std::string& source)
{
    return Compile(GL_VERTEX_SHADER,source);
}

GLuint ShaderCompiler::CompileFragment(const std::string& source)
{
    return Compile(GL_FRAGMENT_SHADER,source);
}

}
