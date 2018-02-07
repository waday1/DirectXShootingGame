#pragma once
#include "Scene.h"
class Title :
	public Scene
{
public:
	Title();
	Title(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight);
	~Title();
	void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	void CreateResources(UINT backBufferWidth, UINT backBufferHeight);
	Scene* Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
		UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const& timer);
	void Render();

	std::unique_ptr<DirectX::SpriteFont> m_font;
	DirectX::SimpleMath::Vector2 m_fontPos;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
};

