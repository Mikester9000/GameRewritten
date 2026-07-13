// ============================================================
// FILE: src/rendering/d3d11/D3D11ShaderCompiler.hpp
// SYSTEM: Rendering
// ROLE: HLSL shader compilation and D3D11 input layout helpers.
//       Extracted from D3D11Renderer to keep shader management separate.
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: D3D11ShaderCompiler module behavior and local implementation details.
// ============================================================

#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

namespace D3D11ShaderCompiler
{
    // Compile an HLSL source file from disk.
    // On success, *outBlob is filled and S_OK is returned.
    // On failure, *outBlob is nullptr and an error is logged.
    HRESULT CompileFromFile(const wchar_t* path,
                            const char*    entryPoint,
                            const char*    target,
                            ID3DBlob**     outBlob);

    // Create the input layout that matches TerrainVertex
    // (POSITION float3 | NORMAL float3 | COLOR float4).
    // The vertex shader bytecode is needed for signature validation.
    HRESULT CreateTerrainInputLayout(ID3D11Device*       device,
                                     const void*         shaderBytecode,
                                     SIZE_T              bytecodeLength,
                                     ID3D11InputLayout** outLayout);
}
