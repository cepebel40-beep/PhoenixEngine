#pragma once
namespace PHX {
class Logger{
public:
 static void Info(const char*);
 static void Warn(const char*);
 static void Error(const char*);
};
}
