#pragma once
#include"ShotManager.h"
#include"StepTimer.h"
//�e�̐����p�^�[���̊��N���X
class ShotGenerater
{
public:
	ShotGenerater();
	//Nway�V���b�g�p
	ShotGenerater(int totalNunber, float angle, float speed, float size, float interbalTime, int LoopCount, ShotCharacter character);
	~ShotGenerater();
	virtual bool Update(DX::StepTimer const& timer,ShotManager * shotmanager, DirectX::SimpleMath::Vector2 currentPos, DirectX::SimpleMath::Vector2 target);

	virtual void InitializeTime();
};

