#pragma once

#include <cstdint>

namespace PHX
{
    class LibraryFinder
    {
    public:

        static bool Initialize();

        static uintptr_t Find(const char* libraryName);

        static bool IsLoaded(const char* libraryName);
    };
}
