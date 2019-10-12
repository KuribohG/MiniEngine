#pragma once

class RootSignature
{
public:
	RootSignature(int NumParameters,
		const D3D12_ROOT_PARAMETER* pParameters,
		int NumStaticSamplers,
		const D3D12_STATIC_SAMPLER_DESC* pStaticSamplers,
		D3D12_ROOT_SIGNATURE_FLAGS Flags);
	~RootSignature();
	void Finalize();
	ID3D12RootSignature* GetRootSignature() const;
private:
	CD3DX12_ROOT_SIGNATURE_DESC m_RootSignatureDesc;
	ID3D12RootSignature* m_RootSignature;
};
