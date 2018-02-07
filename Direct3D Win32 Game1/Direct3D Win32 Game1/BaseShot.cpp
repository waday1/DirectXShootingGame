#include "pch.h"
#include "BaseShot.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;



BaseShot::BaseShot(DirectX::SimpleMath::Vector2 pos, float speed, float scale, float angle, bool isAlive, ShotCharacter character )
{

	SetPosition(pos);

	SetSpeed(speed);
	SetScale(scale);
	SetAngle(angle / 180 * PI);
	SetIsAlive(isAlive);
	SetCharacter(character);
	SetCollider(new CircleCollider(pos, 12));
}


BaseShot::~BaseShot()
{
}

void BaseShot::Update(DX::StepTimer const & timer)
{
	Vector2 vec;
	vec.x = speed*sin(angle);
	vec.y = speed*cos(angle);

	MoveUpdate(vec*timer.GetElapsedSeconds());

	if (position.y > 800 || position.y < -100)
	{
		isAlive = false;
	}
	GetCollider()->SetPosition(GetPosition());
}


void BaseShot::MoveUpdate(DirectX::SimpleMath::Vector2 vec)
{
	position += vec;
}

void BaseShot::Render(DirectX::SpriteBatch *spriteBatch, Texture* texture)
{
	spriteBatch->Draw(texture->texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f, texture->GetOrigin(), GetScale());
}
