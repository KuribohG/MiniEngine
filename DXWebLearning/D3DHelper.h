#pragma once

#include "stdafx.h"

extern ID3D12Device* g_Device;

bool InitD3D(HWND hwnd, int Width, int Height, bool FullScreen);
void Update();
void UpdatePipeline();
void Render();
void Cleanup();
void WaitForPreviousFrame();
