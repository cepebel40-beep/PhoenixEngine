#include "Hook/OpenGLHook.hpp"

#include "Graphics/OpenGLRuntime.hpp"
#include "Graphics/OpenGLFunctionTable.hpp"

namespace PHX
{

bool InstallOpenGLHooks()
{
    if (!InitializeOpenGLRuntime())
        return false;

    if (!LoadOpenGLFunctionTable())
        return false;

    return true;
}

void RemoveOpenGLHooks()
{
    // Tahap berikutnya akan menghapus hook asli di sini.
}

}
