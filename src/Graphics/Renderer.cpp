#include "Graphics/Renderer.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Core/Logger.hpp"
namespace PHX {
bool InitializeRenderer() {
    ShaderManager sm;
    sm.Initialize();
    Logger::Info("Renderer ready");
    return true;
}
}
