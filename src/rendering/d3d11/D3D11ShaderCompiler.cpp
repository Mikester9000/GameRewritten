// ============================================================
// FILE: src/rendering/d3d11/D3D11ShaderCompiler.cpp
// SYSTEM: Rendering
// ROLE: HLSL shader compilation and D3D11 input layout helpers.
// ============================================================

#include "D3D11ShaderCompiler.hpp"
#include "../../logger/Logger.hpp"
#include <string>

#pragma comment(lib, "d3dcompiler.lib")

namespace D3D11ShaderCompiler
{
    HRESULT CompileFromFile(const wchar_t* path,
                            const char*    entryPoint,
                            const char*    target,
                            ID3DBlob**     outBlob)
    {
        *outBlob = nullptr;
        ID3DBlob* errorBlob = nullptr;

        HRESULT hr = D3DCompileFromFile(
            path,
            nullptr,
            D3D_COMPILE_STANDARD_FILE_INCLUDE,
            entryPoint,
            target,
            D3DCOMPILE_ENABLE_STRICTNESS,
            0,
            outBlob,
            &errorBlob);

        if (FAILED(hr))
        {
            if (errorBlob)
            {
                LOG_ERROR("Shader compile error: " +
                    std::string(static_cast<const char*>(errorBlob->GetBufferPointer())));
                errorBlob->Release();
            }
            else
            {
                LOG_ERROR("Shader compile failed (no error message available).");
            }
        }
        else if (errorBlob)
        {
            // Warnings (compilation succeeded but warnings were emitted)
            LOG_WARN("Shader compile warning: " +
                std::string(static_cast<const char*>(errorBlob->GetBufferPointer())));
            errorBlob->Release();
        }

        return hr;
    }

    HRESULT CreateTerrainInputLayout(ID3D11Device*       device,
                                     const void*         shaderBytecode,
                                     SIZE_T              bytecodeLength,
                                     ID3D11InputLayout** outLayout)
    {
        // Matches TerrainVertex: float3 pos (0) | float3 normal (12) | float4 color (24)
        static const D3D11_INPUT_ELEMENT_DESC layout[] =
        {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        return device->CreateInputLayout(
            layout,
            static_cast<UINT>(std::size(layout)),
            shaderBytecode,
            bytecodeLength,
            outLayout);
    }
}
