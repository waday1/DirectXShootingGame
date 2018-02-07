#pragma once
#include"BaseShot.h"

class Character;
///<summary>
///’e‚ğŠÇ—‚·‚éƒNƒ‰ƒX
///</summary>
class ShotManager
{
public:
	ShotManager(Microsoft::WRL::ComPtr<ID3D11Device> Device);
	~ShotManager();
	void Update(DX::StepTimer const& timer, Character* player, Character* enemy);
	void Render(DirectX::SpriteBatch *spriteBatch);

	BaseShot GetShot(int index) { return shot[index]; }
	bool SetShot(BaseShot shot);
	const int GetMaxShotCount() { return MaxShotCount; }
	BaseShot* shot;
private:
	const int MaxShotCount = 1000;
	Texture* texture;
};

