#include "Graphics/OpenGLFunctionTable.hpp"
#include "Memory/SymbolResolver.hpp"

namespace PHX
{

PFNGLUSEPROGRAMPROC    OpenGLFunctionTable::glUseProgramPtr    = nullptr;
PFNGLLINKPROGRAMPROC   OpenGLFunctionTable::glLinkProgramPtr   = nullptr;
PFNGLCOMPILESHADERPROC OpenGLFunctionTable::glCompileShaderPtr = nullptr;
PFNGLCREATESHADERPROC  OpenGLFunctionTable::glCreateShaderPtr  = nullptr;
PFNGLCREATEPROGRAMPROC OpenGLFunctionTable::glCreateProgramPtr = nullptr;
PFNGLSHADERSOURCEPROC  OpenGLFunctionTable::glShaderSourcePtr  = nullptr;

bool OpenGLFunctionTable::Initialize()
{
    glUseProgramPtr =
        reinterpret_cast<PFNGLUSEPROGRAMPROC>(
            SymbolResolver::ResolveOpenGL("glUseProgram"));

    glLinkProgramPtr =
        reinterpret_cast<PFNGLLINKPROGRAMPROC>(
            SymbolResolver::ResolveOpenGL("glLinkProgram"));

    glCompileShaderPtr =
        reinterpret_cast<PFNGLCOMPILESHADERPROC>(
            SymbolResolver::ResolveOpenGL("glCompileShader"));

    glCreateShaderPtr =
        reinterpret_cast<PFNGLCREATESHADERPROC>(
            SymbolResolver::ResolveOpenGL("glCreateShader"));

    glCreateProgramPtr =
        reinterpret_cast<PFNGLCREATEPROGRAMPROC>(
            SymbolResolver::ResolveOpenGL("glCreateProgram"));

    glShaderSourcePtr =
        reinterpret_cast<PFNGLSHADERSOURCEPROC>(
            SymbolResolver::ResolveOpenGL("glShaderSource"));

    return
        glUseProgramPtr &&
        glLinkProgramPtr &&
        glCompileShaderPtr &&
        glCreateShaderPtr &&
        glCreateProgramPtr &&
        glShaderSourcePtr;
}

void OpenGLFunctionTable::Shutdown()
{
    glUseProgramPtr = nullptr;
    glLinkProgramPtr = nullptr;
    glCompileShaderPtr = nullptr;
    glCreateShaderPtr = nullptr;
    glCreateProgramPtr = nullptr;
    glShaderSourcePtr = nullptr;
}

}
