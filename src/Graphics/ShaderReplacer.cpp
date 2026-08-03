#include "Graphics/ShaderReplacer.hpp"

#include "Graphics/ShaderInterceptor.hpp"

#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

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

    GLenum type =
        ShaderInterceptor::GetType(shader);

    switch (type)
    {
        case GL_VERTEX_SHADER:
        {
            Logger::Info(
                "Vertex shader detected");

            break;
        }

        case GL_FRAGMENT_SHADER:
        {
            Logger::Info(
                "Fragment shader detected");

            break;
        }

        default:
        {
            Logger::Info(
                "Unknown shader type");

            break;
        }
    }

    return Replace(source);
}

}
