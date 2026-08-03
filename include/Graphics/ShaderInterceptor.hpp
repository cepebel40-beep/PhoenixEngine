#pragma once

#include <string>
#include <unordered_map>

#include <GLES3/gl3.h>

namespace PHX
{

class ShaderInterceptor
{
public:

    static bool Initialize();

    static void Shutdown();

    static void OnCreateShader(
        GLuint shader,
        GLenum type);

    static void OnShaderSource(
        GLuint shader,
        const std::string& source);

    static void OnCompileShader(
        GLuint shader);

    static void OnAttachShader(
        GLuint program,
        GLuint shader);

    static void OnLinkProgram(
        GLuint program);

    static bool HasSource(
        GLuint shader);

    static bool IsCompiled(
        GLuint shader);

    static bool HasAttachedShader(
        GLuint program);

    static GLuint GetAttachedShader(
        GLuint program);

    static bool IsProgramLinked(
        GLuint program);

    static std::string GetSource(
        GLuint shader);

    static GLenum GetType(
        GLuint shader);

private:

    struct ShaderInfo
    {
        GLenum type;

        std::string source;

        bool compiled;
    };

    static std::unordered_map<
        GLuint,
        ShaderInfo> sShaders;

    static std::unordered_map<
        GLuint,
        GLuint> sAttachedShaders;

    static std::unordered_map<
        GLuint,
        bool> sLinkedPrograms;
};

}
