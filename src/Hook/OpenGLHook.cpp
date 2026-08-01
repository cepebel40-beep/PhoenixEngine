#include "Hook/OpenGLHook.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "Phoenix", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "Phoenix", __VA_ARGS__)

namespace PHX
{

static bool gHooksInstalled = false;

bool InstallOpenGLHooks()
{
    if (gHooksInstalled)
    {
        LOGI("OpenGL hooks already installed.");
        return true;
    }

    LOGI("========================================");
    LOGI(" Phoenix Engine");
    LOGI(" Initializing OpenGL Hook System");
    LOGI("========================================");

    /*
        Future hook list:

        eglSwapBuffers()
        glShaderSource()
        glAttachShader()
        glCompileShader()
        glLinkProgram()
        glUseProgram()
    */

    gHooksInstalled = true;

    LOGI("OpenGL hook system initialized.");

    return true;
}

void RemoveOpenGLHooks()
{
    if (!gHooksInstalled)
        return;

    LOGI("Shutting down OpenGL hook system...");

    gHooksInstalled = false;

    LOGI("OpenGL hook system shutdown complete.");
}

bool IsOpenGLHookInstalled()
{
    return gHooksInstalled;
}

}
