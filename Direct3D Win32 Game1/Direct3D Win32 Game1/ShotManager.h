#pragma once
#include"BaseShot.h"

///<summary>
///弾を管理するクラス
///</summary>
class ShotManager
{
public:
	ShotManager(Microsoft::WRL::ComPtr<ID3D11Device> Device);
	~ShotManager();
	void Render(DirectX::SpriteBatch *spriteBatch);
private:
	BaseShot* shot;
	const int MaxShotCount = 100;
	Texture* texture;
};

