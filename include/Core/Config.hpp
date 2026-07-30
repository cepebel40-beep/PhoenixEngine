#pragma once
namespace PHX {
struct Config {
    bool bloom=true;
    float brightness=1.0f;
};
bool LoadPhoenixConfig(const char* path, Config& cfg);
}
