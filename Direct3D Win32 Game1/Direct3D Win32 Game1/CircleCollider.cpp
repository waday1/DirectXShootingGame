#include "pch.h"
#include "CircleCollider.h"


CircleCollider::CircleCollider()
{
}

CircleCollider::CircleCollider(DirectX::SimpleMath::Vector2 pos, float radius)
{
	SetCollisionType(CollisionType::Circle);
	SetPosition(pos);
	SetRadius(radius);
}


CircleCollider::~CircleCollider()
{
}

bool CircleCollider::Intersects(Collider * collider)
{
	switch (collider->GetCollisionType())
	{
	case CollisionType::Circle:
		return CircleIntersects(collider->GetPosition(), collider->GetRadius());
		break;
	default:
		break;
	}
	return false;
}

bool CircleCollider::CircleIntersects(DirectX::SimpleMath::Vector2 otherPos, float otherRadius)
{
	float x, y, r;
	x = (GetPosition().x - otherPos.x);
	y = (GetPosition().y - otherPos.y);
	r = radius + otherRadius;
	if (r*r < x*x + y*y)
	{
		return true;
	}
	return false;
}
