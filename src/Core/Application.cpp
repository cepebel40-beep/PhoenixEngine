#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include "Core/Logger.hpp"
namespace PHX{
bool Application::Start(){
    Logger::Info("Application starting");
    return InitializeEngine();
}}
