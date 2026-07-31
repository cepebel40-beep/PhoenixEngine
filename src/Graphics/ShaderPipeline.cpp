#include "Graphics/ShaderPipeline.hpp"
#include "Graphics/ShaderManager.hpp"

namespace PHX
{

bool ShaderPipeline::Initialize()
{
    ShaderManager manager;
    return manager.Initialize();
}

void ShaderPipeline::Shutdown()
{
    // Belum digunakan.
    // Akan diimplementasikan saat ShaderManager memiliki fungsi Shutdown().
}

}
