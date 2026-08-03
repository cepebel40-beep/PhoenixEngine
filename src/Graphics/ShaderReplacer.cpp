#include "Graphics/ShaderReplacer.hpp"
#include "Graphics/ShaderInterceptor.hpp"

#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderReplacer::Initialize()
{
    Logger::Info(
        "ShaderReplacer initialized");

    return true;
}

void ShaderReplacer::Shutdown()
{
    Logger::Info(
        "ShaderReplacer shutdown");
}

std::string ShaderReplacer::Replace(
    const std::string& source)
{
    if (source.empty())
    {
        return source;
    }

    return source;
}

std::string ShaderReplacer::ReplaceShader(
    GLuint shader)
{
    if (!ShaderInterceptor::HasSource(shader))
    {
        return "";
    }

    std::string source =
        ShaderInterceptor::GetSource(shader);

    return Replace(source);
}

}
