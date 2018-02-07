#pragma once
#include"ShotManager.h"
#include"StepTimer.h"
//弾の生成パターンの基底クラス
class ShotGenerater
{
public:
	ShotGenerater();
	//Nwayショット用
	ShotGenerater(int totalNunber, float angle, float speed, float size, float interbalTime, int LoopCount, ShotCharacter character);
	~ShotGenerater();
	virtual bool Update(DX::StepTimer const& timer,ShotManager * shotmanager, DirectX::SimpleMath::Vector2 currentPos, DirectX::SimpleMath::Vector2 target);

	virtual void InitializeTime();
};

