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
        LOGI("OpenGL hooks already installed");
        return true;
    }

    LOGI("Installing OpenGL hooks...");

    // Placeholder.
    // Hook eglSwapBuffers, glShaderSource,
    // glUseProgram, dll akan dipasang di sini.

    gHooksInstalled = true;

    LOGI("OpenGL hooks installed");

    return true;
}

void RemoveOpenGLHooks()
{
    if (!gHooksInstalled)
        return;

    LOGI("Removing OpenGL hooks...");

    gHooksInstalled = false;

    LOGI("OpenGL hooks removed");
}

}
