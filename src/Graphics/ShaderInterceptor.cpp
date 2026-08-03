#include "Graphics/ShaderInterceptor.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

std::unordered_map<
    GLuint,
    ShaderInterceptor::ShaderInfo>
ShaderInterceptor::sShaders;

bool ShaderInterceptor::Initialize()
{
    sShaders.clear();

    Logger::Info(
        "ShaderInterceptor initialized");

    return true;
}

void ShaderInterceptor::Shutdown()
{
    Logger::Info(
        "Tracked shaders: %zu",
        sShaders.size());

    sShaders.clear();

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
        "CreateShader id=%u type=%u",
        shader,
        type);
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
        "ShaderSource id=%u size=%zu",
        shader,
        source.size());
}

void ShaderInterceptor::OnCompileShader(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return;

    it->second.compiled = true;

    Logger::Info(
        "CompileShader id=%u",
        shader);
}

void ShaderInterceptor::OnAttachShader(
    GLuint program,
    GLuint shader)
{
    Logger::Info(
        "AttachShader program=%u shader=%u",
        program,
        shader);
}

void ShaderInterceptor::OnLinkProgram(
    GLuint program)
{
    Logger::Info(
        "LinkProgram %u",
        program);
}

bool ShaderInterceptor::HasSource(
    GLuint shader)
{
    auto it = sShaders.find(shader);

    if (it == sShaders.end())
        return false;

    return !it->second.source.empty();
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
