#pragma once
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
private:
	//�����蔻��̒��S
	DirectX::SimpleMath::Vector2 position;
};

