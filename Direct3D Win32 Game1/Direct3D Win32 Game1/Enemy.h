#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy();
	Enemy(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,
		float speed, float scale,
		const wchar_t * filename, BoxCollider box, bool isAlive);
	~Enemy();
	void Update(DX::StepTimer const& timer, ShotManager* shotmanager);

private:

};

