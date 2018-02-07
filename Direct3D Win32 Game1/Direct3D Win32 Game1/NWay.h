#pragma once
#include "ShotGenerater.h"
///��E�����̐���
class NWay :
	public ShotGenerater
{
public:
	NWay();
	NWay(int totalNunber, float angle, float speed, float size, float interbalTime,int LoopCount, ShotCharacter character);
	~NWay();
	bool Update(DX::StepTimer const& timer, ShotManager * shotmanager,DirectX::SimpleMath::Vector2 currentPos, DirectX::SimpleMath::Vector2 target);

	void InitializeTime();
private:
	//��x�ɏo���e�̗�
	int totalNunber;
	//�e�̈ړ������̊p�x
	float angle;
	float speed;
	float size;
	float interbalTime;
	float currentlTime;
	//���񃋁[�v���邩�B�����Ƀ��[�v����Ȃ�O
	int LoopCount;
	ShotCharacter character;
};

