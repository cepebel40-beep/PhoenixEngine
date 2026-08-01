#pragma once

#include <cstdint>

namespace PHX
{
    class LibraryFinder
    {
    public:
        static uintptr_t Find(const char* libraryName);
    };
}
