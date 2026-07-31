#include "Game/LibraryFinder.hpp"

namespace PHX
{
    bool LibraryFinder::Initialize()
    {
        return true;
    }

    uintptr_t LibraryFinder::Find(const char*)
    {
        return 0;
    }

    bool LibraryFinder::IsLoaded(const char*)
    {
        return false;
    }
}
