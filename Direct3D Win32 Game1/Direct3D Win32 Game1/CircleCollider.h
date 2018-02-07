#pragma once
#include "Collider.h"
class CircleCollider :
	public Collider
{
public:
	CircleCollider();
	CircleCollider(DirectX::SimpleMath::Vector2 pos, float radius);
	~CircleCollider();

	virtual float GetRadius() { return radius; }
	virtual void SetRadius(float radius) { this->radius = radius; }
	bool Intersects(Collider* collider);

private:
	//‰~“¯Žm‚Ì”»’è
	bool CircleIntersects(DirectX::SimpleMath::Vector2 otherPos, float otherRadius);
private:
	float radius;
};

