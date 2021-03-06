#pragma once
class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Render();
	virtual void CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext);
	virtual void CreateResources(UINT backBufferWidth, UINT backBufferHeight);

public:
	std::unique_ptr<DirectX::SpriteFont> m_font;
	DirectX::SimpleMath::Vector2 m_fontPos;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	DirectX::SimpleMath::Vector2 m_screenPos;
	DirectX::SimpleMath::Vector2 m_origin;
};

