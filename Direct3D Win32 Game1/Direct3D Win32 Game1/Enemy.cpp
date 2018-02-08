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

	SetIsAlive(isAlive);

	SetCollider(new CircleCollider(pos,texture->origin.x));

	SetPattern(stageNum);
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
	currentGenerater->Update(timer, shotmanager, GetPosition(), playerPos);
}

void Enemy::SetPattern(int stageNum)
{
	currentGenerater=new NWay(0, 10, 100, 1, 0.1f, 0, ShotCharacter::S_Enemy);
	switch (stageNum)
	{
	case 1:
		SetCurrentGenerater(new NWay(3, 30, 130, 1, 0.8f, 0, ShotCharacter::S_Enemy));
		break;
	case 2:
		SetCurrentGenerater(new NWay(5, 20, 100, 1, 0.5f, 0, ShotCharacter::S_Enemy));
		break;
	case 3:
		SetCurrentGenerater(new NWay(5, 30, 150, 1, 1, 0, ShotCharacter::S_Enemy));
		currentGenerater=new NWay(4, 13, 200, 1, 0.1f, 0, ShotCharacter::S_Enemy);
		break;
	case 4:
		SetCurrentGenerater(new NWay(45, 10, 100, 1, 0.8f, 0, ShotCharacter::S_Enemy));
		break;
	default:
		break;
	}
}

