#include "pch.h"
#include "ShotManager.h"
#include"Character.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

ShotManager::ShotManager(Microsoft::WRL::ComPtr<ID3D11Device> Device)
{
	shot = new BaseShot[MaxShotCount];
	for (int i = 0; i <MaxShotCount; i++)
	{
		shot[i] = BaseShot();
	}

	shot[0] = BaseShot( Vector2(500, 500), 100.0f, 1.0, true);
	texture =new Texture(Device, L"Shot.png");
}


ShotManager::~ShotManager()
{
	delete[] shot;
	delete texture;
}

void ShotManager::Update(DX::StepTimer const & timer, Character* player, Character* enemy)
{
	for (int i = 0; i < GetMaxShotCount(); i++)
	{
		if (shot[i].GetIsAlive())
		{
			shot[i].Update(timer);
			switch (shot[i].GetCharacter())
			{
			case ShotCharacter::S_Enemy:
				if (shot[i].GetCollider()->Intersects(player->GetCollider()))
				{
					player->SetIsAlive(false);
				}
				break;
			case ShotCharacter::S_Player:
				if (shot[i].GetCollider()->Intersects(enemy->GetCollider()))
				{
					if (enemy->GetIsAlive())
					{
						enemy->SetLife(enemy->GetLife() - 1);
						if (enemy->GetLife() <= 0)
						{
							enemy->SetIsAlive(false);
						}
						shot[i].SetIsAlive(false);
					}
				}
				break;
			default:
				break;
			}
		}
	}
}

void ShotManager::Render(DirectX::SpriteBatch * spriteBatch)
{
	for (int i = 0; i <MaxShotCount; i++)
	{
		if (shot[i].GetIsAlive())
		{
			//プレイヤーとエネミーで弾の色が同じなので、のちに別の画像に差し替える
			if (shot[i].GetCharacter() == ShotCharacter::S_Enemy)
			{
				shot[i].Render(spriteBatch, texture);
			}
			if (shot[i].GetCharacter() == ShotCharacter::S_Player)
			{
				shot[i].Render(spriteBatch, texture);
			}
		}
	}
}

bool ShotManager::SetShot(BaseShot shot)
{
	{
		for (int i = 0; i < MaxShotCount; i++)
		{
			if (!this->shot[i].GetIsAlive())
			{
				this->shot[i] = shot;
				return true;
			}
		}
		return false;
	}
}
