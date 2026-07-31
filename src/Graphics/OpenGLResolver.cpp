#include "Graphics/OpenGLResolver.hpp"

#include <android/log.h>
#include <dlfcn.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "Phoenix", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "Phoenix", __VA_ARGS__)

namespace PHX
{

static void* gGLESHandle = nullptr;

bool OpenGLResolver::Initialize()
{
    if (gGLESHandle)
        return true;

    gGLESHandle = dlopen("libGLESv2.so", RTLD_NOW);

    if (!gGLESHandle)
    {
        LOGE("Failed to load libGLESv2.so");
        return false;
    }

    LOGI("libGLESv2.so loaded");

    return true;
}

void* OpenGLResolver::GetProcAddress(const char* name)
{
    if (!gGLESHandle)
        return nullptr;

    return dlsym(gGLESHandle, name);
}

}
