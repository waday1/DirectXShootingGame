#include "pch.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider()
{
}

BoxCollider::BoxCollider(DirectX::SimpleMath::Vector2 pos, DirectX::SimpleMath::Vector2 size)
{
	SetPosition(pos);
	SetSize(size);
}


BoxCollider::~BoxCollider()
{
}
