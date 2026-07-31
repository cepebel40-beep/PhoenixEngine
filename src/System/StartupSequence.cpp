#include "System/StartupSequence.hpp"

#include "Core/Engine.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool StartupSequence::Run()
{
    Logger::Info("Starting Phoenix...");

    if (!InitializeEngine())
    {
        Logger::Error("Engine startup failed.");
        return false;
    }

    Logger::Info("Phoenix started.");

    return true;
}

}
