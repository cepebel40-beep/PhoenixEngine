#include "Core/Engine.hpp"
#include "Core/Logger.hpp"
#include "Graphics/ShaderManager.hpp"
#include "Graphics/Renderer.hpp"
#include "Hook/OpenGLHook.hpp"
namespace PHX{bool InitializeEngine(){ShaderManager sm; sm.Initialize(); InitializeRenderer(); InstallOpenGLHooks(); Logger::Info("Engine initialized"); return true;}}
