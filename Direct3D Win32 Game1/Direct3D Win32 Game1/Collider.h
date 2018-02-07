#pragma once

enum CollisionType
{
	None, Box, Circle
};
class Collider
{
public:
	Collider();
	Collider(DirectX::SimpleMath::Vector2 pos, DirectX::SimpleMath::Vector2 size);
	~Collider();

	void Render(DirectX::SpriteBatch* spriteBatch);

	DirectX::SimpleMath::Vector2 GetPosition() { return position; }
	void SetPosition(DirectX::SimpleMath::Vector2 pos) { position=pos; }

	//�����蔻��̍����ƕ��̔����iBoxCollider�p�j
	virtual DirectX::SimpleMath::Vector2 GetSize() { return DirectX::SimpleMath::Vector2::Zero; }
	virtual void SetSize(DirectX::SimpleMath::Vector2 size) { }
	//�����蔻��̔��a�iCircleCollider�p�j
	virtual float GetRadius() { return 0; }
	virtual void SetRadius(float radius) { }

	CollisionType GetCollisionType() { return type; }
	void SetCollisionType(CollisionType type) { this->type = type; }

	virtual bool Intersects(Collider* collider);
private:
	//�����蔻��̒��S
	DirectX::SimpleMath::Vector2 position;
	CollisionType type;
};

