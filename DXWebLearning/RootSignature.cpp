#include "stdafx.h"
#include "D3DHelper.h"
#include "Utility.h"
#include "RootSignature.h"

RootSignature::RootSignature(int NumParameters,
	const D3D12_ROOT_PARAMETER* pParameters,
	int NumStaticSamplers,
	const D3D12_STATIC_SAMPLER_DESC* pStaticSamplers,
	D3D12_ROOT_SIGNATURE_FLAGS Flags)
{
	m_RootSignatureDesc.Init(NumParameters, pParameters,
		NumStaticSamplers, pStaticSamplers, Flags);
}

RootSignature::~RootSignature()
{
	SAFE_RELEASE(m_RootSignature);
}

void RootSignature::Finalize()
{
	HRESULT hr;
	ID3DBlob* signature = nullptr;
	ID3DBlob* error = nullptr;

	hr = D3D12SerializeRootSignature(&m_RootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);
	ASSERT_SUCCEEDED(hr, "Root signature finalize serialize failed.\n %s\n", (LPCSTR)error->GetBufferPointer());

	hr = g_Device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_RootSignature));
	ASSERT_SUCCEEDED(hr, "Root signature finalize create failed.\n");
}

ID3D12RootSignature* RootSignature::GetRootSignature() const
{
	return m_RootSignature;
}