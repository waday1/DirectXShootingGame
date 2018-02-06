#include "pch.h"
#include "Texture.h"


Texture::Texture(Microsoft::WRL::ComPtr<ID3D11Device> Device, const wchar_t * filename)
{
	Microsoft::WRL::ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(Device.Get(), filename,
			resource.GetAddressOf(),
			texture.ReleaseAndGetAddressOf()));

	Microsoft::WRL::ComPtr<ID3D11Texture2D> tex;
	DX::ThrowIfFailed(resource.As(&tex));

	CD3D11_TEXTURE2D_DESC texDesc;
	tex->GetDesc(&texDesc);

	SetOrigin(DirectX::SimpleMath::Vector2(float(texDesc.Width / 2), float(texDesc.Height / 2)));

}

Texture::~Texture()
{
	texture.Reset();
}
