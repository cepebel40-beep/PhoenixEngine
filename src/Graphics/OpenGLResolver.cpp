#include "Graphics/OpenGLResolver.hpp"

#include <dlfcn.h>

namespace PHX
{
    static void* gGLESHandle = nullptr;

    bool OpenGLResolver::Initialize()
    {
        if (gGLESHandle)
            return true;

        gGLESHandle = dlopen("libGLESv2.so", RTLD_NOW);

        return gGLESHandle != nullptr;
    }

    void* OpenGLResolver::GetProcAddress(const char* name)
    {
        if (!gGLESHandle)
            return nullptr;

        return dlsym(gGLESHandle, name);
    }
}
