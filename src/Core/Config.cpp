#include "Core/Config.hpp"
#include <fstream>
namespace PHX{
bool LoadPhoenixConfig(const char* path, Config& cfg){
 std::ifstream f(path);
 if(!f.good()) return false;
 // TODO: parse Phoenix.ini
 cfg.bloom=true;
 cfg.brightness=1.0f;
 return true;
}}
