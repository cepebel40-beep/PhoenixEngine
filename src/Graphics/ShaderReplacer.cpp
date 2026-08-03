#include "Graphics/ShaderReplacer.hpp"

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
    return source;
}

}
