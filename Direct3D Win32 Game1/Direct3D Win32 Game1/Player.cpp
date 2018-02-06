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
	texture = new Texture(Device, filename);

	SetPosition(pos);

	SetScale(scale);
	SetSpeed(speed);
}


Player::~Player()
{
	delete texture;
}

void Player::Update(DX::StepTimer const& timer)
{
	//StepTimerÇ≈1ÉtÉåÅ[ÉÄÇ†ÇΩÇËÇÃéûä‘ÇÇ∆ÇÈ
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
