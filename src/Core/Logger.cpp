#include "Core/Logger.hpp"
#include <android/log.h>
namespace PHX {
void Logger::Info(const char* m){__android_log_print(ANDROID_LOG_INFO,"PHOENIX","%s",m);}
void Logger::Warn(const char* m){__android_log_print(ANDROID_LOG_WARN,"PHOENIX","%s",m);}
void Logger::Error(const char* m){__android_log_print(ANDROID_LOG_ERROR,"PHOENIX","%s",m);}
}
