#include "Hook/RenderHook.hpp"
#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

static bool gRendererInstalled = false;

bool InstallRenderHooks()
{
    if (gRendererInstalled)
    {
        Logger::Info("Render hooks already installed");
        return true;
    }

    Logger::Info("Installing Render hooks");

    glDisable(GL_DITHER);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glFrontFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    gRendererInstalled = true;

    Logger::Info("Render hooks installed");

    return true;
}

}
