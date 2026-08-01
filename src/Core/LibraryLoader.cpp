#include "Core/LibraryLoader.hpp"
#include "Core/Logger.hpp"

#include <dlfcn.h>

namespace PHX
{

void* LibraryLoader::sGLESHandle = nullptr;
void* LibraryLoader::sEGLHandle = nullptr;

bool LibraryLoader::Initialize()
{
    sGLESHandle = dlopen("libGLESv2.so", RTLD_NOW);

    if (!sGLESHandle)
    {
        Logger::Error("Failed to open libGLESv2.so");
        return false;
    }

    sEGLHandle = dlopen("libEGL.so", RTLD_NOW);

    if (!sEGLHandle)
    {
        Logger::Error("Failed to open libEGL.so");
        return false;
    }

    Logger::Info("LibraryLoader initialized");

    return true;
}

void LibraryLoader::Shutdown()
{
    if (sGLESHandle)
    {
        dlclose(sGLESHandle);
        sGLESHandle = nullptr;
    }

    if (sEGLHandle)
    {
        dlclose(sEGLHandle);
        sEGLHandle = nullptr;
    }

    Logger::Info("LibraryLoader shutdown");
}

void* LibraryLoader::GetGLESHandle()
{
    return sGLESHandle;
}

void* LibraryLoader::GetEGLHandle()
{
    return sEGLHandle;
}

}
