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

	bool Intersects(Collider* collider);
private:
	//lŠp“¯m‚Ì”»’è
	bool BoxIntersects(DirectX::SimpleMath::Vector2 otherPos, DirectX::SimpleMath::Vector2 otherSize);
private:
	//’†S‚©‚ç‚Ì‹——£
	DirectX::SimpleMath::Vector2 size;


};

