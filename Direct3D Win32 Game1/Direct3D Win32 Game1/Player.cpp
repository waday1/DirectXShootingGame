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
	collisionTexture = new Texture(Device, L"Collision.png");

	SetPosition(pos);

	SetScale(scale);
	SetSpeed(speed);
	SetCollider(new CircleCollider(pos, collisionTexture->GetOrigin().x));

	SetCurrentGenerater(new NWay(3, 20, 200, 1, 0.2f,0, ShotCharacter::S_Player));
}


Player::~Player()
{
	delete texture;
	delete collisionTexture;
}

void Player::Update(DX::StepTimer const& timer, ShotManager* shotmanager)
{
	//StepTimer‚Å1ƒtƒŒ[ƒ€‚ ‚½‚è‚ÌŽžŠÔ‚ð‚Æ‚é
	Move(timer.GetElapsedSeconds());
	Shot(timer,shotmanager);
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
	GetCollider()->SetPosition(GetPosition());
}

void Player::Shot(DX::StepTimer const& timer, ShotManager * shotmanager)
{
	if (InputManager::IsKeyDown(Keyboard::Z))
	{
		GetCurrentGenerater()->Update(timer,shotmanager,GetPosition(),Vector2(GetPosition().x,GetPosition().y-100));
	}
}

void Player::Render(DirectX::SpriteBatch *spriteBatch)
{
	spriteBatch->Draw(texture->texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f, texture->GetOrigin(), GetScale());
	spriteBatch->Draw(collisionTexture->texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f, collisionTexture->GetOrigin(), GetScale());
}
