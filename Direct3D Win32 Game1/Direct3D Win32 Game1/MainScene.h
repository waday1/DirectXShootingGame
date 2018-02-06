#pragma once
#include "Scene.h"
#include "Character.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

public:
	void Update(DX::StepTimer const& timer);
	void Render();
	void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	void CreateResources(UINT backBufferWidth, UINT backBufferHeight);

public:
	Character* player;
};

