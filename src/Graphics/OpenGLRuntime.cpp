#include "Graphics/OpenGLRuntime.hpp"

#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "Phoenix", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "Phoenix", __VA_ARGS__)

namespace PHX
{

bool OpenGLRuntime::Initialize()
{
    const GLubyte* version = glGetString(GL_VERSION);

    if (version == nullptr)
    {
        LOGE("OpenGL ES context not ready");
        return false;
    }

    LOGI("OpenGL Version: %s", version);

    return true;
}

void OpenGLRuntime::Shutdown()
{
    LOGI("OpenGLRuntime shutdown");
}

GLuint OpenGLRuntime::CurrentProgram()
{
    GLint program = 0;

    glGetIntegerv(GL_CURRENT_PROGRAM, &program);

    return static_cast<GLuint>(program);
}

}
