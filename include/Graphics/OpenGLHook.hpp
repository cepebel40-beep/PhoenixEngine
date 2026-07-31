#pragma once

namespace PHX
{

class OpenGLHook
{
public:
    static bool Install();

    static void Remove();

    static bool IsInstalled();

private:
    static bool sInstalled;
};

}
