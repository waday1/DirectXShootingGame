#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	Player(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,
		float speed,float scale,
		const wchar_t * filename, bool isAlive);
	~Player( );

	void Update(DX::StepTimer const& timer, ShotManager* shotmanager);
	void Move(float fps);
	void Shot(ShotManager* shotmanager);
};

