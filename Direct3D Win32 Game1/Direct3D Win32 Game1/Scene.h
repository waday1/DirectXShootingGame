#pragma once
#include"StepTimer.h"
class Scene
{
public:
	Scene();
	~Scene();
	virtual void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	virtual void CreateResources(UINT backBufferWidth, UINT backBufferHeight);
	virtual void Update(DX::StepTimer const& timer);
	virtual void Render();

public:

};

