#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include "Core/Logger.hpp"

#include <jni.h>

extern "C"
jint JNI_OnLoad(JavaVM*, void*)
{
    PHX::Logger::Info("Phoenix bootstrap");

    PHX::InitializeEngine();

    PHX::Application app;
    app.Start();

    return JNI_VERSION_1_6;
}
