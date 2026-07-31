#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"

namespace PHX
{

bool ShaderManager::Initialize()
{
    Logger::Info("ShaderManager initializing...");

    // Pipeline shader akan ditambahkan pada tahap berikutnya.
    // Untuk saat ini cukup memastikan sistem siap.

    Logger::Info("ShaderManager ready.");

    return true;
}

}
