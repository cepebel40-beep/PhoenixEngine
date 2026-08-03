#pragma once

#include <GLES3/gl3.h>

namespace PHX
{

class TextureManager
{
public:

    static bool Initialize();

    static void Shutdown();

    static void Bind(GLuint texture);

    static GLuint Current();

private:

    static GLuint sTexture;
};

}
