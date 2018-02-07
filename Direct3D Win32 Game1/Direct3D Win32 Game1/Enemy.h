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

	//ステージごとの動きの設定
	void SetPattern(int stageNum);

	int GetLife() { return life; }
	void SetLife(int life) { this->life = life; }

private:
	int life;
	///本当は基底クラスのcurrentGeneraterをlistにしてやりたかったが時間がないので断念。今後修正予定
	ShotGenerater* currentGenerater;
};

