#include "Graphics/OpenGLFunctionTable.hpp"

namespace PHX
{

PFNGLUSEPROGRAMPROC OpenGLFunctionTable::glUseProgramPtr = nullptr;
PFNGLLINKPROGRAMPROC OpenGLFunctionTable::glLinkProgramPtr = nullptr;
PFNGLCOMPILESHADERPROC OpenGLFunctionTable::glCompileShaderPtr = nullptr;

bool OpenGLFunctionTable::Initialize()
{
    return true;
}

void OpenGLFunctionTable::Shutdown()
{
    glUseProgramPtr = nullptr;
    glLinkProgramPtr = nullptr;
    glCompileShaderPtr = nullptr;
}

}
