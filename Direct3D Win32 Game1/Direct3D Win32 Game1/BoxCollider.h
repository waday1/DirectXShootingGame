#pragma once
#include "Collider.h"
class BoxCollider :
	public Collider
{
public:
	BoxCollider();
	BoxCollider(DirectX::SimpleMath::Vector2 pos, DirectX::SimpleMath::Vector2 size);
	~BoxCollider();
	DirectX::SimpleMath::Vector2 GetSize() { return size; }
	void SetSize(DirectX::SimpleMath::Vector2 size) { this->size=size; }

private:
	//���S����̋���
	DirectX::SimpleMath::Vector2 size;
};

