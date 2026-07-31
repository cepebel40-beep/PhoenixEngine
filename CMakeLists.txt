cmake_minimum_required(VERSION 3.22)

project(Phoenix)

add_library(Phoenix64 SHARED
    src/main.cpp

    src/Core/Logger.cpp
    src/Core/Config.cpp
    src/Core/Memory.cpp
    src/Core/BuildInfo.cpp
    src/Core/Engine.cpp
    src/Core/Application.cpp

    src/Graphics/Renderer.cpp
    src/Graphics/ShaderManager.cpp
    src/Graphics/ShaderLoader.cpp
    src/Graphics/ShaderCompiler.cpp
    src/Graphics/ShaderCache.cpp
    src/Graphics/UniformManager.cpp
    src/Graphics/RenderState.cpp
    src/Graphics/ShaderPipeline.cpp
    src/Graphics/OpenGLRuntime.cpp
    src/Graphics/OpenGLFunctionTable.cpp

    src/Hook/RenderHook.cpp
    src/Hook/OpenGLHook.cpp
)

find_library(log-lib log)
find_library(gles-lib GLESv3)

target_include_directories(Phoenix64 PRIVATE include)

target_link_libraries(
    Phoenix64
    ${log-lib}
    ${gles-lib}
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_compile_features(Phoenix64 PRIVATE cxx_std_17)
