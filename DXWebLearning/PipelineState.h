#pragma once

#include "stdafx.h"
#include "RootSignature.h"
#include "Shader.h"

class PSO
{
public:
	~PSO();
	void SetRootSignature(RootSignature* RootSignature);
	void SetVertexShader(Shader* VertexShader);
	void SetPixelShader(Shader* PixelShader);
	void SetDomainShader(Shader* DomainShader);
	void SetHullShader(Shader* HullShader);
	void SetGeometryShader(Shader* GeometryShader);
	void SetInputLayout(UINT Size, D3D12_INPUT_ELEMENT_DESC* InputElementDescs);
	void SetPrimitiveTopologyType(D3D12_PRIMITIVE_TOPOLOGY_TYPE PrimitiveTopologyType);
	void SetRenderTargets(UINT Num, DXGI_FORMAT* RTVFormats, DXGI_FORMAT DSVFormat, const DXGI_SAMPLE_DESC& SampleDesc);
	void SetBlendState(const D3D12_BLEND_DESC& BlendDesc);
	void SetRasterizerState(const D3D12_RASTERIZER_DESC& RasterizerDesc);
	void SetSampleMask(UINT SampleMask);
	void Finalize();
private:
	D3D12_GRAPHICS_PIPELINE_STATE_DESC m_GraphicsPipelineStateDesc;
	ID3D12PipelineState* m_PipelineState;
};