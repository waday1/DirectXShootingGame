#pragma once
class Texture
{
public:
	Texture(Microsoft::WRL::ComPtr<ID3D11Device> Device, const wchar_t * filename);
	~Texture();

	DirectX::SimpleMath::Vector2 GetOrigin() { return origin; }
	void SetOrigin(DirectX::SimpleMath::Vector2 origin) { this->origin = origin; }

public:
	DirectX::SimpleMath::Vector2 origin;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
};

