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

void Player::Update(DX::StepTimer const& timer, ShotManager* shotmanager)
{
	//StepTimer‚Å1ƒtƒŒ[ƒ€‚ ‚½‚è‚ÌŽžŠÔ‚ð‚Æ‚é
	Move(timer.GetElapsedSeconds());
	Shot(shotmanager);
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

void Player::Shot(ShotManager * shotmanager)
{
	if (InputManager::IsKeyDown(Keyboard::Z))
	{
		shotmanager->SetShot(BaseShot(GetPosition(), 200, 1.0f,180, true));
		shotmanager->SetShot(BaseShot(GetPosition(), 200, 1.0f, 200, true));
		shotmanager->SetShot(BaseShot(GetPosition(), 200, 1.0f, 160, true));
	}
}
