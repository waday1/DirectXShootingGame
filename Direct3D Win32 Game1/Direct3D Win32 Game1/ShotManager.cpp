#include "pch.h"
#include "ShotManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

ShotManager::ShotManager(Microsoft::WRL::ComPtr<ID3D11Device> Device)
{
	shot = new BaseShot[100];
	for (int i = 0; i <MaxShotCount; i++)
	{
		shot[i] = BaseShot();
	}

	shot[0] = BaseShot( Vector2(500, 500), 100.0f, 1.0, true);
	texture =new Texture(Device, L"Player1.png");
}


ShotManager::~ShotManager()
{
	delete[] shot;
	delete texture;
}

void ShotManager::Update(DX::StepTimer const & timer)
{
	for (int i = 0; i < GetMaxShotCount(); i++)
	{
		if (shot[i].GetIsAlive())
		{
			shot[i].Update(timer);
		}
	}
}

void ShotManager::Render(DirectX::SpriteBatch * spriteBatch)
{
	for (int i = 0; i <MaxShotCount; i++)
	{
		if (shot[i].GetIsAlive())
		{
			shot[i].Render(spriteBatch,texture);
		}
	}
}
