#pragma once

#include "stdafx.h"

enum class ShaderType
{
	VERTEX_SHADER,
	PIXEL_SHADER,
	DOMAIN_SHADER,
	HULL_SHADER,
	GEOMETRY_SHADER
};

class Shader
{
public:
	void CompileFromFile(LPCWSTR FileName);
	D3D12_SHADER_BYTECODE GetShaderBytecode() const;
private:
	ShaderType m_Type;
	ID3DBlob* m_ShaderCodeBuffer;
	D3D12_SHADER_BYTECODE m_ShaderBytecode;
};