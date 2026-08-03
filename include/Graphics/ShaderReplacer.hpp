#pragma once

#include <string>

namespace PHX
{

class ShaderReplacer
{
public:

    static bool Initialize();

    static void Shutdown();

    static std::string Replace(
        const std::string& source);
};

}
