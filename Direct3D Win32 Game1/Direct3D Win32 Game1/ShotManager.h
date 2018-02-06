#pragma once
#include"BaseShot.h"

///<summary>
///’e‚ğŠÇ—‚·‚éƒNƒ‰ƒX
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

