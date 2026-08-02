#include "Graphics/OpenGLFunctionTable.hpp"

#include "Memory/SymbolResolver.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

PFNGLUSEPROGRAMPROC OpenGLFunctionTable::glUseProgramPtr = nullptr;
PFNGLCOMPILESHADERPROC OpenGLFunctionTable::glCompileShaderPtr = nullptr;
PFNGLLINKPROGRAMPROC OpenGLFunctionTable::glLinkProgramPtr = nullptr;

bool OpenGLFunctionTable::Initialize()
{
    Logger::Info("Initializing OpenGLFunctionTable");

    glUseProgramPtr =
        reinterpret_cast<PFNGLUSEPROGRAMPROC>(
            SymbolResolver::ResolveOpenGL("glUseProgram"));

    glCompileShaderPtr =
        reinterpret_cast<PFNGLCOMPILESHADERPROC>(
            SymbolResolver::ResolveOpenGL("glCompileShader"));

    glLinkProgramPtr =
        reinterpret_cast<PFNGLLINKPROGRAMPROC>(
            SymbolResolver::ResolveOpenGL("glLinkProgram"));

    if (!glUseProgramPtr)
    {
        Logger::Error("Failed to resolve glUseProgram");
        return false;
    }

    if (!glCompileShaderPtr)
    {
        Logger::Error("Failed to resolve glCompileShader");
        return false;
    }

    if (!glLinkProgramPtr)
    {
        Logger::Error("Failed to resolve glLinkProgram");
        return false;
    }

    Logger::Info("OpenGLFunctionTable initialized");

    return true;
}

void OpenGLFunctionTable::Shutdown()
{
    glUseProgramPtr = nullptr;
    glCompileShaderPtr = nullptr;
    glLinkProgramPtr = nullptr;

    Logger::Info("OpenGLFunctionTable shutdown");
}

}
