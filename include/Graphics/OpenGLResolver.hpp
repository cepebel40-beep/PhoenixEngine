#pragma once

namespace PHX
{
    class OpenGLResolver
    {
    public:
        static bool Initialize();

        static void* GetProcAddress(const char* name);
    };
}
