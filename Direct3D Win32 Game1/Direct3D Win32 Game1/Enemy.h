#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy();
	Enemy(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,
		float speed, float scale,int life,
		const wchar_t * filename, BoxCollider box, bool isAlive, int stageNum);
	~Enemy();
	void Update(DX::StepTimer const& timer, ShotManager* shotmanager,DirectX::SimpleMath::Vector2 playerPos);

	void Shot(DX::StepTimer const& timer, ShotManager* shotmanager, DirectX::SimpleMath::Vector2 playerPos);


	int GetLife() { return life; }
	void SetLife(int life) { this->life = life; }

private:
	int life;

};

