#pragma once

#include <cstdint>

namespace PHX
{
    class GameModule
    {
    public:
        static bool Locate();
        static uintptr_t GetBase();

    private:
        static uintptr_t mBase;
    };
}
