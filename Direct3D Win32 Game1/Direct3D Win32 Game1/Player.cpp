#include "pch.h"
#include "Player.h"
#include"InputManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
{
}

Player::Player(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed,float scale, const wchar_t * filename, bool isAlive)
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


Player::~Player()
{
	texture.Reset();
}

void Player::Update(DX::StepTimer const& timer)
{
	//StepTimer‚Å1ƒtƒŒ[ƒ€‚ ‚½‚è‚ÌŽžŠÔ‚ð‚Æ‚é
	Move(timer.GetElapsedSeconds());
}


void Player::Move(float fps)
{
	Vector2 vec;
	if (InputManager::IsKeyDown(Keyboard::Up))
	{
		vec.y = -GetSpeed();
	}
	if (InputManager::IsKeyDown(Keyboard::Down))
	{
		vec.y = GetSpeed();
	}
	if (InputManager::IsKeyDown(Keyboard::Left))
	{
		vec.x = -GetSpeed();
	}
	if (InputManager::IsKeyDown(Keyboard::Right))
	{
		vec.x = GetSpeed();
	}

	MoveUpdate(vec*fps);
}

void Player::Render(DirectX::SpriteBatch *spriteBatch)
{
	spriteBatch->Draw(texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f, GetOrigin(),GetScale());
}
