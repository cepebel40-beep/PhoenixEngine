#include "Graphics/ShaderCompiler.hpp"
#include "Graphics/ShaderInterceptor.hpp"

#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

namespace PHX
{

std::string ShaderCompiler::sLastError;

GLuint ShaderCompiler::Compile(
    GLenum type,
    const std::string& source)
{
    sLastError.clear();

    GLuint shader = glCreateShader(type);

    if(shader == 0)
    {
        sLastError = "glCreateShader failed";
        return 0;
    }

    ShaderInterceptor::OnCreateShader(
        shader,
        type);

    ShaderInterceptor::OnShaderSource(
        shader,
        source);

    const char* src = source.c_str();

    glShaderSource(
        shader,
        1,
        &src,
        nullptr);

    glCompileShader(shader);

    GLint success = GL_FALSE;

    glGetShaderiv(
        shader,
        GL_COMPILE_STATUS,
        &success);

    if(!success)
    {
        char log[2048]{};

        glGetShaderInfoLog(
            shader,
            sizeof(log),
            nullptr,
            log);

        sLastError = log;

        LOGE("%s",log);

        glDeleteShader(shader);

        return 0;
    }

    ShaderInterceptor::OnCompileShader(
        shader);

    LOGI(
        "Shader compiled");

    return shader;
}

GLuint ShaderCompiler::CompileVertex(
    const std::string& source)
{
    return Compile(
        GL_VERTEX_SHADER,
        source);
}

GLuint ShaderCompiler::CompileFragment(
    const std::string& source)
{
    return Compile(
        GL_FRAGMENT_SHADER,
        source);
}

std::string ShaderCompiler::GetLastError()
{
    return sLastError;
}

}
