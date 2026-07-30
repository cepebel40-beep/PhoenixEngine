#include "Graphics/ShaderLoader.hpp"
#include "Core/Logger.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace PHX
{

static bool ReadTextFile(const char* path, std::string& output)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        Logger::Error(path);
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    output = buffer.str();

    return true;
}

bool ShaderLoader::Load(const char* vertexPath, const char* fragmentPath)
{
    Logger::Info("================================");
    Logger::Info("Phoenix ShaderLoader");
    Logger::Info("Initializing...");
    Logger::Info("================================");

    if (vertexPath == nullptr)
    {
        Logger::Error("Vertex shader path is null.");
        return false;
    }

    if (fragmentPath == nullptr)
    {
        Logger::Error("Fragment shader path is null.");
        return false;
    }

    std::string vertexSource;
    std::string fragmentSource;

    if (!ReadTextFile(vertexPath, vertexSource))
    {
        Logger::Error("Failed to read vertex shader.");
        return false;
    }

    if (!ReadTextFile(fragmentPath, fragmentSource))
    {
        Logger::Error("Failed to read fragment shader.");
        return false;
    }

    Logger::Info("Vertex shader loaded.");
    Logger::Info("Fragment shader loaded.");
    Logger::Info("ShaderLoader ready.");

    return true;
}

}
