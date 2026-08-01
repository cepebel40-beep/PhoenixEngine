#include "Game/LibraryFinder.hpp"

#include <cstdio>
#include <cstring>

namespace PHX
{
    uintptr_t LibraryFinder::Find(const char* libraryName)
    {
        if (!libraryName)
            return 0;

        FILE* maps = fopen("/proc/self/maps", "r");

        if (!maps)
            return 0;

        char line[512];

        while (fgets(line, sizeof(line), maps))
        {
            if (strstr(line, libraryName))
            {
                uintptr_t base = 0;
                sscanf(line, "%lx-", &base);
                fclose(maps);
                return base;
            }
        }

        fclose(maps);
        return 0;
    }
}
