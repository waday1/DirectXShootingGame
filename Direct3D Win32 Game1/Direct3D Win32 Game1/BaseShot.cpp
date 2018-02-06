#include "pch.h"
#include "BaseShot.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;



BaseShot::BaseShot(DirectX::SimpleMath::Vector2 pos, float speed, float scale, bool isAlive)
{

	SetPosition(pos);

	SetScale(scale);
	SetSpeed(speed);
	SetIsAlive(isAlive);
}


BaseShot::~BaseShot()
{
}

void BaseShot::Update(DX::StepTimer const & timer)
{
		MoveUpdate(Vector2(0, speed)*timer.GetElapsedSeconds());

		if (position.y > 800)
		{
			isAlive = false;
		}
}


void BaseShot::MoveUpdate(DirectX::SimpleMath::Vector2 vec)
{
	position += vec;
}

void BaseShot::Render(DirectX::SpriteBatch *spriteBatch, Texture* texture)
{
	spriteBatch->Draw(texture->texture.Get(), GetPosition(), nullptr, Colors::White, 0.0f,texture->GetOrigin(), GetScale());
}
