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

	//当たり判定の高さと幅の半分（BoxCollider用）
	virtual DirectX::SimpleMath::Vector2 GetSize() { return DirectX::SimpleMath::Vector2::Zero; }
	virtual void SetSize(DirectX::SimpleMath::Vector2 size) { }
	//当たり判定の半径（CircleCollider用）
	virtual float GetRadius() { return 0; }
	virtual void SetRadius(float radius) { }

	CollisionType GetCollisionType() { return type; }
	void SetCollisionType(CollisionType type) { this->type = type; }

	virtual bool Intersects(Collider* collider);
private:
	//当たり判定の中心
	DirectX::SimpleMath::Vector2 position;
	CollisionType type;
};

