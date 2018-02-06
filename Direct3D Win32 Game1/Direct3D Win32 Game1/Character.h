#pragma once
#include "pch.h"
#include "StepTimer.h"
#include"Texture.h"
///<summry>
///プレイヤーと敵の基底クラス
///</summary>
class Character
{
public:
	Character();
	Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed,float scale, const wchar_t * filename,bool isAlive);
	~Character();
	virtual void Update(DX::StepTimer const& timer) ;
	void Render(DirectX::SpriteBatch*) ;
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
	void SetIsAlive() { this->isAlive = isAlive; }

	Texture* texture;
private:
	DirectX::SimpleMath::Vector2 position;
	DirectX::SimpleMath::Vector2 origin;
	float scale;
	float speed;
	bool isAlive;
	
};

