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
	void Shot(DX::StepTimer const& timer, ShotManager* shotmanager);
	void Render(DirectX::SpriteBatch*);

	//�X�N���[���̊O�ɏo���ۂ̏����i�X�N���[���T�C�Y�𒼐ړ���Ă��邽�ߗv�C���j
	void PositionModification();

	Texture* collisionTexture;
};

