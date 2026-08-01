#include "Graphics/ShaderPipeline.hpp"
#include "Graphics/ShaderCompiler.hpp"
#include "Graphics/ShaderCache.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Phoenix",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Phoenix",__VA_ARGS__)

namespace PHX
{

GLuint ShaderPipeline::Create(const std::string& name,
                              const std::string& vertexSource,
                              const std::string& fragmentSource)
{
    if (ShaderCache::Has(name))
        return ShaderCache::Get(name);

    GLuint vs = ShaderCompiler::CompileVertex(vertexSource);

    if (!vs)
        return 0;

    GLuint fs = ShaderCompiler::CompileFragment(fragmentSource);

    if (!fs)
    {
        glDeleteShader(vs);
        return 0;
    }

    GLuint program = glCreateProgram();

    glAttachShader(program,vs);
    glAttachShader(program,fs);

    glLinkProgram(program);

    GLint success = GL_FALSE;

    glGetProgramiv(program,
                   GL_LINK_STATUS,
                   &success);

    glDeleteShader(vs);
    glDeleteShader(fs);

    if (!success)
    {
        char log[1024]{};

        glGetProgramInfoLog(program,
                            sizeof(log),
                            nullptr,
                            log);

        LOGE("%s",log);

        glDeleteProgram(program);

        return 0;
    }

    ShaderCache::Store(name,program);

    LOGI("Shader pipeline created");

    return program;
}

void ShaderPipeline::Use(GLuint program)
{
    if(program!=0)
        glUseProgram(program);
}

void ShaderPipeline::Destroy(GLuint program)
{
    if(program!=0)
        glDeleteProgram(program);
}

}
