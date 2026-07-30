#include "Core/Application.hpp"
#include "Core/Engine.hpp"
#include <jni.h>
#include "Core/Logger.hpp"
extern "C" jint JNI_OnLoad(JavaVM*, void*) {
    PHX::Logger::Info("Phoenix bootstrap");
    PHX::Application app;
    app.Start();
    return JNI_VERSION_1_6;
}
