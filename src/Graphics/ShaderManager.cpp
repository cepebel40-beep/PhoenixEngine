#include "Graphics/ShaderManager.hpp"

#include <GLES3/gl3.h>
#include <android/log.h>

#define LOG_TAG "Phoenix64"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace Phoenix
{

bool ShaderManager::Initialize()
{
    LOGI("ShaderManager initialized");
    return true;
}

void ShaderManager::Shutdown()
{
    LOGI("ShaderManager shutdown");
}

}
