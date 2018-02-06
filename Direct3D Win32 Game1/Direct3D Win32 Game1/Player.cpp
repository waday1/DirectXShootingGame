#include "pch.h"
#include "Player.h"
#include"InputManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
{
}

Player::Player(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed, const wchar_t * filename, bool isAlive)
{
	Microsoft::WRL::ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(Device.Get(), filename,
			resource.GetAddressOf(),
			texture.ReleaseAndGetAddressOf()));

	Microsoft::WRL::ComPtr<ID3D11Texture2D> cat;
	DX::ThrowIfFailed(resource.As(&cat));

	CD3D11_TEXTURE2D_DESC catDesc;
	cat->GetDesc(&catDesc);

	origin.x = float(catDesc.Width / 2);
	origin.y = float(catDesc.Height / 2);

	position = pos;

	this->speed = speed;
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
		vec.y = -speed;
	}
	if (InputManager::IsKeyDown(Keyboard::Down))
	{
		vec.y = speed;
	}
	if (InputManager::IsKeyDown(Keyboard::Left))
	{
		vec.x = -speed;
	}
	if (InputManager::IsKeyDown(Keyboard::Right))
	{
		vec.x = speed;
	}
	position += vec*fps;
}

void Player::Render(DirectX::SpriteBatch *m_spriteBatch)
{
	m_spriteBatch->Draw(texture.Get(), position, nullptr, Colors::White, 0.f, origin);
}
