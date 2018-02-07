#pragma once
class CircleCollider
{
public:
	CircleCollider();
	CircleCollider(DirectX::SimpleMath::Vector2 pos, float radius);
	~CircleCollider();

	virtual float GetRadius() { return radius; }
	virtual void SetRadius(float radius) { this->radius = radius; }
private:
	float radius;
};

