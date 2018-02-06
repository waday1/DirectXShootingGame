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
	void Update(DX::StepTimer const& timer);
	void Render(DirectX::SpriteBatch *spriteBatch);

	BaseShot GetShot(int index) { return shot[index]; }
	bool SetShot(BaseShot shot) {
		for (int i = 0; i < MaxShotCount; i++)
		{
			if (!this->shot[i].GetIsAlive())
			{
				this->shot[i] = shot;
				return true;
			}
		}
		return false;
	}
	const int GetMaxShotCount() { return MaxShotCount; }
	BaseShot* shot;
private:
	const int MaxShotCount = 100;
	Texture* texture;
};

