#include "pch.h"
#include "Enemy.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
Enemy::Enemy()
{
}

Enemy::Enemy(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos, float speed, float scale, const wchar_t * filename, bool isAlive)
{
	texture = new Texture(Device, filename);

	SetPosition(pos);

	SetScale(scale);
	SetSpeed(speed);
}


Enemy::~Enemy()
{
	delete texture;
}

void Enemy::Update(DX::StepTimer const & timer)
{
}
