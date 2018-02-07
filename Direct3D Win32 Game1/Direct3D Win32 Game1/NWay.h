#pragma once
#include "ShotGenerater.h"
///奇数・偶数の生成
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
	//一度に出す弾の量
	int totalNunber;
	//弾の移動方向の角度
	float angle;
	float speed;
	float size;
	float interbalTime;
	float currentlTime;
	//何回ループするか。無限にループするなら０
	int LoopCount;
	ShotCharacter character;
};

