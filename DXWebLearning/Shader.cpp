#include "Shader.h"
#include "Utility.h"

void Shader::CompileFromFile(LPCWSTR FileName)
{
	HRESULT hr;
	ID3DBlob* error;

	hr = D3DCompileFromFile(FileName,
		nullptr,
		nullptr,
		"main",
		"vs_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
		0,
		&m_ShaderCodeBuffer,
		&error);
	ASSERT_SUCCEEDED(hr, "Shader compile from file fail.\n");

	m_ShaderBytecode.BytecodeLength = m_ShaderCodeBuffer->GetBufferSize();
	m_ShaderBytecode.pShaderBytecode = m_ShaderCodeBuffer->GetBufferPointer();
}

D3D12_SHADER_BYTECODE Shader::GetShaderBytecode() const
{
	return m_ShaderBytecode;
}