#pragma once

namespace PHX
{

class LibraryLoader
{
public:
    static bool Initialize();

    static void Shutdown();

    static void* GetGLESHandle();

    static void* GetEGLHandle();

private:
    static void* sGLESHandle;
    static void* sEGLHandle;
};

}
