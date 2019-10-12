#include "PipelineState.h"
#include "D3DHelper.h"
#include "Utility.h"

PSO::~PSO()
{
	SAFE_RELEASE(m_PipelineState);
}

void PSO::SetRootSignature(RootSignature* RootSignature)
{
	m_GraphicsPipelineStateDesc.pRootSignature = RootSignature->GetRootSignature();
}

void PSO::SetVertexShader(Shader* VertexShader)
{
	m_GraphicsPipelineStateDesc.VS = VertexShader->GetShaderBytecode();
}

void PSO::SetPixelShader(Shader* PixelShader)
{
	m_GraphicsPipelineStateDesc.PS = PixelShader->GetShaderBytecode();
}

void PSO::SetDomainShader(Shader* DomainShader)
{
	m_GraphicsPipelineStateDesc.DS = DomainShader->GetShaderBytecode();
}

void PSO::SetHullShader(Shader* HullShader)
{
	m_GraphicsPipelineStateDesc.HS = HullShader->GetShaderBytecode();
}

void PSO::SetGeometryShader(Shader* GeometryShader)
{
	m_GraphicsPipelineStateDesc.GS = GeometryShader->GetShaderBytecode();
}

void PSO::SetInputLayout(UINT Size, D3D12_INPUT_ELEMENT_DESC* InputElementDescs)
{
	D3D12_INPUT_LAYOUT_DESC InputLayoutDesc;
	InputLayoutDesc.NumElements = Size;
	InputLayoutDesc.pInputElementDescs = InputElementDescs;
	m_GraphicsPipelineStateDesc.InputLayout = InputLayoutDesc;
}

void PSO::SetPrimitiveTopologyType(D3D12_PRIMITIVE_TOPOLOGY_TYPE PrimitiveTopologyType)
{
	m_GraphicsPipelineStateDesc.PrimitiveTopologyType = PrimitiveTopologyType;
}

void PSO::SetRenderTargets(UINT Num, DXGI_FORMAT* RTVFormats, DXGI_FORMAT DSVFormat, const DXGI_SAMPLE_DESC& SampleDesc)
{
	ASSERT(Num <= 8);
	m_GraphicsPipelineStateDesc.NumRenderTargets = Num;
	for (int i = 0; i < Num; i++)
	{
		m_GraphicsPipelineStateDesc.RTVFormats[i] = RTVFormats[i];
	}
	m_GraphicsPipelineStateDesc.DSVFormat = DSVFormat;
	m_GraphicsPipelineStateDesc.SampleDesc = SampleDesc;
}

void PSO::SetBlendState(const D3D12_BLEND_DESC& BlendDesc)
{
	m_GraphicsPipelineStateDesc.BlendState = BlendDesc;
}

void PSO::SetRasterizerState(const D3D12_RASTERIZER_DESC& RasterizerDesc)
{
	m_GraphicsPipelineStateDesc.RasterizerState = RasterizerDesc;
}

void PSO::SetSampleMask(UINT SampleMask)
{
	m_GraphicsPipelineStateDesc.SampleMask = SampleMask;
}

void PSO::Finalize()
{
	HRESULT hr;
	
	hr = g_Device->CreateGraphicsPipelineState(&m_GraphicsPipelineStateDesc, IID_PPV_ARGS(&m_PipelineState));
	ASSERT_SUCCEEDED(hr, "Pipeline state failed.\n");
}