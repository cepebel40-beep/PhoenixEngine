#include "Graphics/ShaderInterceptor.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

std::unordered_map<
    GLuint,
    ShaderInterceptor::ShaderInfo>
ShaderInterceptor::sShaders;

std::unordered_map<
    GLuint,
    GLuint>
ShaderInterceptor::sAttachedShaders;

bool ShaderInterceptor::Initialize()
{
    sShaders.clear();
    sAttachedShaders.clear();

    Logger::Info(
        "ShaderInterceptor initialized");

    return true;
}

void ShaderInterceptor::Shutdown()
{
    Logger::Info(
        "ShaderInterceptor shutting down");

    sShaders.clear();
    sAttachedShaders.clear();

    Logger::Info(
        "ShaderInterceptor shutdown");
}

void ShaderInterceptor::OnCreateShader(
    GLuint shader,
    GLenum type)
{
    ShaderInfo info;

    info.type = type;
    info.compiled = false;

    sShaders[shader] = info;

    Logger::Info(
        "CreateShader intercepted");
}

void ShaderInterceptor::OnShaderSource(
    GLuint shader,
    const std::string& source)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return;

    it->second.source = source;

    Logger::Info(
        "ShaderSource intercepted");
}

void ShaderInterceptor::OnCompileShader(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return;

    it->second.compiled = true;

    Logger::Info(
        "CompileShader intercepted");
}

void ShaderInterceptor::OnAttachShader(
    GLuint program,
    GLuint shader)
{
    sAttachedShaders[program] = shader;

    Logger::Info(
        "AttachShader intercepted");
}

void ShaderInterceptor::OnLinkProgram(
    GLuint)
{
    Logger::Info(
        "LinkProgram intercepted");
}

bool ShaderInterceptor::HasSource(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return false;

    return !it->second.source.empty();
}

bool ShaderInterceptor::IsCompiled(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return false;

    return it->second.compiled;
}

bool ShaderInterceptor::HasAttachedShader(
    GLuint program)
{
    return sAttachedShaders.find(program)
        != sAttachedShaders.end();
}

GLuint ShaderInterceptor::GetAttachedShader(
    GLuint program)
{
    auto it = sAttachedShaders.find(program);

    if (it == sAttachedShaders.end())
        return 0;

    return it->second;
}

std::string ShaderInterceptor::GetSource(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return "";

    return it->second.source;
}

GLenum ShaderInterceptor::GetType(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return 0;

    return it->second.type;
}

}
