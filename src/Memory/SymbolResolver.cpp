#include "Memory/SymbolResolver.hpp"

#include <dlfcn.h>

namespace PHX
{

static void* gOpenGLHandle = nullptr;
static void* gEGLHandle = nullptr;

bool SymbolResolver::Initialize()
{
    if (!gOpenGLHandle)
        gOpenGLHandle = dlopen("libGLESv3.so", RTLD_NOW);

    if (!gEGLHandle)
        gEGLHandle = dlopen("libEGL.so", RTLD_NOW);

    return (gOpenGLHandle && gEGLHandle);
}

void SymbolResolver::Shutdown()
{
    if (gOpenGLHandle)
    {
        dlclose(gOpenGLHandle);
        gOpenGLHandle = nullptr;
    }

    if (gEGLHandle)
    {
        dlclose(gEGLHandle);
        gEGLHandle = nullptr;
    }
}

void* SymbolResolver::ResolveOpenGL(const char* symbol)
{
    if (!gOpenGLHandle || !symbol)
        return nullptr;

    return dlsym(gOpenGLHandle, symbol);
}

void* SymbolResolver::ResolveEGL(const char* symbol)
{
    if (!gEGLHandle || !symbol)
        return nullptr;

    return dlsym(gEGLHandle, symbol);
}

}
