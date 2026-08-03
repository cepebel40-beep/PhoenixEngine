#include "Hook/RenderHook.hpp"

#include "Core/Logger.hpp"
#include "Graphics/Renderer.hpp"

namespace PHX
{

static bool sInstalled = false;

bool InstallRenderHooks()
{
    if (sInstalled)
        return true;

    Logger::Info("Installing Render hooks");

    /*
        Tahap berikutnya:

        eglSwapBuffers
              │
              ▼
        Phoenix Hook
              │
              ▼
        Renderer::RenderFrame()

        Untuk saat ini kita hanya menyiapkan pondasinya
        agar build tetap hijau.
    */

    sInstalled = true;

    Logger::Info("Render hooks installed");

    return true;
}

bool RemoveRenderHooks()
{
    if (!sInstalled)
        return true;

    sInstalled = false;

    Logger::Info("Render hooks removed");

    return true;
}

}
