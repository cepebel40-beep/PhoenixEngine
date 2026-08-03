cmake_minimum_required(VERSION 3.22)

project(PhoenixEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Phoenix64 SHARED

    src/main.cpp

    # =====================================================
    # Core
    # =====================================================
    src/Core/Application.cpp
    src/Core/BuildInfo.cpp
    src/Core/Config.cpp
    src/Core/Engine.cpp
    src/Core/LibraryLoader.cpp
    src/Core/Logger.cpp
    src/Core/Memory.cpp

    # =====================================================
    # Game
    # =====================================================
    src/Game/GameModule.cpp
    src/Game/GameProcess.cpp
    src/Game/GameVersion.cpp
    src/Game/LibraryFinder.cpp
    src/Game/MemoryMap.cpp
    src/Game/ModuleScanner.cpp
    src/Game/ProcMapsReader.cpp

    # =====================================================
    # Graphics
    # =====================================================
    src/Graphics/OpenGLFunctionTable.cpp
    src/Graphics/OpenGLResolver.cpp
    src/Graphics/OpenGLRuntime.cpp
    src/Graphics/RenderContext.cpp
    src/Graphics/RenderState.cpp
    src/Graphics/Renderer.cpp
    src/Graphics/ShaderCache.cpp
    src/Graphics/ShaderCompiler.cpp
    src/Graphics/ShaderLoader.cpp
    src/Graphics/ShaderManager.cpp
    src/Graphics/ShaderPipeline.cpp
    src/Graphics/TextureManager.cpp
    src/Graphics/UniformManager.cpp

    # =====================================================
    # Hook
    # =====================================================
    src/Hook/DrawHook.cpp
    src/Hook/HookManager.cpp
    src/Hook/InlineHook.cpp
    src/Hook/InstructionDecoder.cpp
    src/Hook/OpenGLHook.cpp
    src/Hook/Relocator.cpp
    src/Hook/RenderHook.cpp
    src/Hook/Trampoline.cpp

    # =====================================================
    # Memory
    # =====================================================
    src/Memory/AddressResolver.cpp
    src/Memory/MemoryPatch.cpp
    src/Memory/SymbolResolver.cpp

    # =====================================================
    # System
    # =====================================================
    src/System/EngineState.cpp
    src/System/RuntimeMonitor.cpp
    src/System/StartupSequence.cpp
)

target_include_directories(
    Phoenix64
    PRIVATE
    include
)

find_library(log-lib log REQUIRED)
find_library(gles-lib GLESv3 REQUIRED)

target_link_libraries(
    Phoenix64
    PRIVATE
    ${log-lib}
    ${gles-lib}
)
