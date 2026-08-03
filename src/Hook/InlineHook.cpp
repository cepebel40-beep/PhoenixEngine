#include "Hook/InlineHook.hpp"

#include "Hook/Relocator.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool InlineHook::Install(uintptr_t target,
                         uintptr_t detour,
                         uintptr_t* trampoline)
{
    if (target == 0)
    {
        Logger::Error("InlineHook: invalid target");
        return false;
    }

    if (detour == 0)
    {
        Logger::Error("InlineHook: invalid detour");
        return false;
    }

    if (trampoline == nullptr)
    {
        Logger::Error("InlineHook: invalid trampoline");
        return false;
    }

    Relocator relocator;

    constexpr size_t kInstructionCount = 4;

    if (!relocator.Prepare(target,
                           detour,
                           kInstructionCount))
    {
        Logger::Error("InlineHook: Prepare failed");
        return false;
    }

    if (!relocator.Relocate())
    {
        Logger::Error("InlineHook: Relocate failed");
        return false;
    }

    *trampoline = relocator.GetDestination();

    Logger::Info("InlineHook Stage 1 ready");

    return true;
}

bool InlineHook::Remove(uintptr_t target)
{
    if (target == 0)
        return false;

    Logger::Info("InlineHook Remove placeholder");

    return true;
}

}
