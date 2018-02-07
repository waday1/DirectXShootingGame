#include "pch.h"
#include "Enemy.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;
Enemy::Enemy()
{
}

Enemy::Enemy(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,
	float speed, float scale, int life, 
	const wchar_t * filename, BoxCollider box, bool isAlive,int stageNum)
{
	texture = new Texture(Device, filename);

	SetPosition(pos);

	SetScale(scale);

	SetSpeed(speed);

	SetLife(life);

	SetCollider(new CircleCollider(pos,texture->origin.x));

	SetCurrentGenerater(new NWay(3, 20, 100, 1, 0.5f, 0, ShotCharacter::S_Enemy));
}


Enemy::~Enemy()
{
	delete texture;
}

void Enemy::Update(DX::StepTimer const & timer, ShotManager* shotmanager, DirectX::SimpleMath::Vector2 playerPos)
{
	if (GetIsAlive())
	{
		Shot(timer, shotmanager, playerPos);
	}
}

void Enemy::Shot(DX::StepTimer const & timer, ShotManager * shotmanager, DirectX::SimpleMath::Vector2 playerPos)
{
	GetCurrentGenerater()->Update(timer, shotmanager, GetPosition(), playerPos);
}

