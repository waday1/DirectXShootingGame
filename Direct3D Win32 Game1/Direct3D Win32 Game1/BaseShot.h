#pragma once
#include"StepTimer.h"
#include"Texture.h"
#include"CircleCollider.h"

//’N‚ªŒ‚‚Á‚½’e‚©

enum ShotCharacter
{
	S_Player, S_Enemy
};
///<summry>
///’e‚ÌŠî’êƒNƒ‰ƒX
///</summary>
class BaseShot
{
public:
	BaseShot(DirectX::SimpleMath::Vector2 pos= DirectX::SimpleMath::Vector2::Zero,
		float speed = 0, float scale = 0,float angle=0, bool isAlive = false,
		ShotCharacter character=ShotCharacter::S_Enemy);
	~BaseShot();
	virtual void Update(DX::StepTimer const& timer);
	virtual void Render(DirectX::SpriteBatch*, Texture* texture);
	void MoveUpdate(DirectX::SimpleMath::Vector2 vec);

	DirectX::SimpleMath::Vector2 GetPosition() { return position; }
	void SetPosition(DirectX::SimpleMath::Vector2 position) { this->position = position; }

	float GetScale() { return scale; }
	void SetScale(float scale) { this->scale = scale; }

	float GetSpeed() { return speed; }
	void SetSpeed(float speed) { this->speed = speed; }

	float GetAngle() { return angle; }
	void SetAngle(float angle) { this->angle = angle; }

	float GetCollisionRadius() { return collisionRadius; }
	void SetCollisionRadius(float collisionRadius) { this->collisionRadius = collisionRadius; }

	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }

	ShotCharacter GetCharacter() { return character; }
	void SetCharacter(ShotCharacter character) { this->character = character; }

	Collider* GetCollider() { return collider; }
	void SetCollider(Collider *collider) { this->collider = collider; }

private:
	DirectX::SimpleMath::Vector2 position;
	float scale;
	float speed;
	float angle;
	//“–‚½‚è”»’è‚Ì”¼Œa
	float collisionRadius;
	bool isAlive;
	ShotCharacter character;
	Collider*collider;
};
