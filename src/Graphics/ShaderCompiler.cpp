#include "Graphics/ShaderCompiler.hpp"

#include <android/log.h>
#include <algorithm>
#include <cctype>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

namespace PHX
{

std::string ShaderCompiler::sLastError;

static bool IsSourceEmpty(const std::string& source)
{
    return std::all_of(
        source.begin(),
        source.end(),
        [](unsigned char c)
        {
            return std::isspace(c);
        });
}

GLuint ShaderCompiler::Compile(
    GLenum type,
    const std::string& source)
{
    sLastError.clear();

    if (source.empty() || IsSourceEmpty(source))
    {
        sLastError = "Shader source is empty";

        LOGE("%s", sLastError.c_str());

        return 0;
    }

    GLuint shader = glCreateShader(type);

    if (shader == 0)
    {
        sLastError = "glCreateShader failed";

        LOGE("%s", sLastError.c_str());

        return 0;
    }

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

    if (!success)
    {
        char log[2048]{};

        glGetShaderInfoLog(
            shader,
            sizeof(log),
            nullptr,
            log);

        sLastError = log;

        LOGE("%s", log);

        glDeleteShader(shader);

        return 0;
    }

    LOGI(
        "Shader compiled successfully");

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
