#include "pch.h"
#include "Enemy.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
Enemy::Enemy()
{
}

Enemy::Enemy(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos, float speed, float scale, const wchar_t * filename, bool isAlive)
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

	SetPosition(pos);

	SetScale(scale);
	SetSpeed(speed);
}


Enemy::~Enemy()
{
	texture.Reset();
}

void Enemy::Update(DX::StepTimer const & timer)
{
}

void Enemy::Render(DirectX::SpriteBatch *spriteBatch)
{
	spriteBatch->Draw(texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f, GetOrigin(), GetScale());
}
