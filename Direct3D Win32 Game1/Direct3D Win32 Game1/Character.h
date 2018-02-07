#pragma once
#include "pch.h"
#include "StepTimer.h"
#include"Texture.h"
#include"ShotManager.h"
#include"Collider.h"
#include"BoxCollider.h"
#include"CircleCollider.h"
#include"NWay.h"
///<summry>
///プレイヤーと敵の基底クラス
///</summary>
class Character
{
public:
	Character();
	//Player用
	Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed,float scale, const wchar_t * filename,BoxCollider box,bool isAlive);
	//Enemy用
	Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,
		float speed, float scale, int life,
		const wchar_t * filename, BoxCollider box, bool isAlive, int stageNum);
	Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos, float speed, float scale, const wchar_t * filename, bool isAlive);
	~Character();
	virtual void Update(DX::StepTimer const& timer,ShotManager* shotmanager) ;
	//エネミー用
	virtual void Update(DX::StepTimer const& timer, ShotManager* shotmanager, DirectX::SimpleMath::Vector2 playerPos);
	virtual void Render(DirectX::SpriteBatch*) ;
	void MoveUpdate(DirectX::SimpleMath::Vector2 vec);

	DirectX::SimpleMath::Vector2 GetPosition() { return position; }
	void SetPosition(DirectX::SimpleMath::Vector2 position) { this->position = position; }

	DirectX::SimpleMath::Vector2 GetOrigin() { return origin; }
	void SetOrigin(DirectX::SimpleMath::Vector2 origin) { this->origin = origin; }

	float GetScale() { return scale; }
	void SetScale(float scale) {  this->scale=scale; }

	float GetSpeed() { return speed; }
	void SetSpeed(float speed) { this->speed = speed; }

	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }

	Collider* GetCollider() { return collider; }
	void SetCollider(Collider *collider ) { this->collider = collider; }

	ShotGenerater* GetCurrentGenerater() { return currentGenerater; }
	void SetCurrentGenerater(ShotGenerater *currentGenerater) { this->currentGenerater = currentGenerater; }

	//敵の体力用
	virtual int GetLife() { return 0; }
	virtual void SetLife(int life) {  }

	Texture* texture;
private:
	DirectX::SimpleMath::Vector2 position;
	DirectX::SimpleMath::Vector2 origin;
	float scale;
	float speed;
	bool isAlive;
	Collider*collider;
	ShotGenerater* currentGenerater;
};

