#include "Memory/MemoryPatch.hpp"

#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

namespace PHX
{
    static bool Protect(void* address, size_t size, int prot)
    {
        long pageSize = sysconf(_SC_PAGESIZE);

        uintptr_t start =
            (uintptr_t)address & ~(pageSize - 1);

        uintptr_t end =
            ((uintptr_t)address + size + pageSize - 1)
            & ~(pageSize - 1);

        return mprotect(
            (void*)start,
            end - start,
            prot
        ) == 0;
    }

    bool MemoryPatch::Write(
        uintptr_t address,
        const void* data,
        size_t size)
    {
        if (!address || !data || !size)
            return false;

        if (!Protect(
                (void*)address,
                size,
                PROT_READ |
                PROT_WRITE |
                PROT_EXEC))
            return false;

        memcpy(
            (void*)address,
            data,
            size);

        __builtin___clear_cache(
            (char*)address,
            (char*)(address + size));

        Protect(
            (void*)address,
            size,
            PROT_READ |
            PROT_EXEC);

        return true;
    }

    bool MemoryPatch::Fill(
        uintptr_t address,
        uint8_t value,
        size_t size)
    {
        if (!address || !size)
            return false;

        if (!Protect(
                (void*)address,
                size,
                PROT_READ |
                PROT_WRITE |
                PROT_EXEC))
            return false;

        memset(
            (void*)address,
            value,
            size);

        __builtin___clear_cache(
            (char*)address,
            (char*)(address + size));

        Protect(
            (void*)address,
            size,
            PROT_READ |
            PROT_EXEC);

        return true;
    }

    bool MemoryPatch::Nop(
        uintptr_t address,
        size_t size)
    {
        const uint32_t nop = 0xD503201F;

        while (size >= 4)
        {
            if (!Write(
                    address,
                    &nop,
                    sizeof(nop)))
                return false;

            address += 4;
            size -= 4;
        }

        return true;
    }
}
