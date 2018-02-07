#pragma once
#include"StepTimer.h"
class Scene
{
public:
	Scene();
	Scene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight);
	Scene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight, int stageNum);
	Scene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight, bool isCrear);
	~Scene();
	virtual void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	virtual void CreateResources(UINT backBufferWidth, UINT backBufferHeight);
	virtual void CreateResources(UINT backBufferWidth, UINT backBufferHeight, int stageNum);
	virtual Scene* Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const& timer);
	virtual void Render();

public:

};

