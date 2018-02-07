#include "pch.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider()
{
}

BoxCollider::BoxCollider(DirectX::SimpleMath::Vector2 pos, DirectX::SimpleMath::Vector2 size)
{
	SetCollisionType(CollisionType::Box);
	SetPosition(pos);
	SetSize(size);
}


BoxCollider::~BoxCollider()
{
}

bool BoxCollider::Intersects(Collider * collider)
{
	switch (collider->GetCollisionType())
	{
	case CollisionType::Box:
		return BoxIntersects(collider->GetPosition(), collider->GetSize());
		break;
	default:
		break;
	}
	return false;
}

bool BoxCollider::BoxIntersects(DirectX::SimpleMath::Vector2 otherPos, DirectX::SimpleMath::Vector2 otherSize)
{
	float x, y;
	x=abs(GetPosition().x - otherPos.x);
	y = abs(GetPosition().y - otherPos.y);
	if (x <= GetSize().x + otherSize.x&&y <= GetSize().y + otherSize.y)
	{
		return true;
	}

	return false;
}
