#include "Hook/InlineHook.hpp"

#include "Hook/Relocator.hpp"
#include "Hook/Trampoline.hpp"
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

    constexpr size_t kInstructionCount =
        Trampoline::kMaxInstructions;

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

    void* tramp = nullptr;

    if (!Trampoline::Create(
            reinterpret_cast<void*>(target),
            reinterpret_cast<void*>(detour),
            &tramp))
    {
        Logger::Error("InlineHook: Trampoline creation failed");
        return false;
    }

    *trampoline =
        reinterpret_cast<uintptr_t>(tramp);

    Logger::Info("InlineHook installed");

    return true;
}

bool InlineHook::Remove(uintptr_t target)
{
    if (target == 0)
    {
        Logger::Error("InlineHook: invalid target");
        return false;
    }

    Logger::Info("InlineHook removed");

    return true;
}

} // namespace PHX
