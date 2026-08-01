#pragma once

namespace PHX
{

class SymbolResolver
{
public:

    static bool Initialize();

    static void Shutdown();

    static void* ResolveOpenGL(const char* symbol);

    static void* ResolveEGL(const char* symbol);
};

}
