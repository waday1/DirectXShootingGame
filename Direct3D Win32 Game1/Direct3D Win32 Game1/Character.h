#pragma once
#include "pch.h"
#include "StepTimer.h"
class Character
{
public:
	Character();
	Character(Microsoft::WRL::ComPtr<ID3D11Device> Device, DirectX::SimpleMath::Vector2 pos,float speed, const wchar_t * filename,bool isAlive);
	~Character();
	virtual void Update(DX::StepTimer const& timer) ;
	virtual void Render(DirectX::SpriteBatch*) ;

public:
	DirectX::SimpleMath::Vector2 position;
	DirectX::SimpleMath::Vector2 origin;
	float speed;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
	bool isAlive;
	
};

