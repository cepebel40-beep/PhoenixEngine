#include "Graphics/TextureManager.hpp"

#include "Core/Logger.hpp"

#include <GLES3/gl3.h>

namespace PHX
{

GLuint TextureManager::sTexture = 0;

bool TextureManager::Initialize()
{
    sTexture = 0;

    Logger::Info("TextureManager initialized");

    return true;
}

void TextureManager::Shutdown()
{
    sTexture = 0;

    Logger::Info("TextureManager shutdown");
}

void TextureManager::Bind(GLuint texture)
{
    sTexture = texture;

    glBindTexture(GL_TEXTURE_2D, texture);
}

GLuint TextureManager::Current()
{
    return sTexture;
}

}
