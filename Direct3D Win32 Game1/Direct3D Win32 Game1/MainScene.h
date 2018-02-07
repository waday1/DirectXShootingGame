#pragma once
#include "Scene.h"
#include "Character.h"
#include"ShotManager.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	MainScene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight,int stageNum);
	~MainScene();
	void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	void CreateResources(UINT backBufferWidth, UINT backBufferHeight, int stageNum);
	Scene* Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight,
		DX::StepTimer const& timer);
	void Render();

public:
	Character* player;
	Character* enemy;
	ShotManager* shotManager;
	std::unique_ptr<DirectX::SpriteFont> m_font;
	DirectX::SimpleMath::Vector2 m_fontPos;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	DirectX::SimpleMath::Vector2 m_screenPos;
	int stageNum;
};

