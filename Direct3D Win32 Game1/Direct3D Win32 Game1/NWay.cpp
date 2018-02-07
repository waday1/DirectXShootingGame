#include "pch.h"
#include "NWay.h"


NWay::NWay()
{
}

NWay::NWay(int totalNunber, float angle, float speed, float size, float interbalTime, int LoopCount, ShotCharacter character)
{
	this->totalNunber = totalNunber;
	this->angle = angle;
	this->speed = speed;
	this->size = size;
	this->interbalTime = interbalTime;
	currentlTime = interbalTime;
	this->character = character;
}


NWay::~NWay()
{
}

bool NWay::Update(DX::StepTimer const& timer, ShotManager * shotmanager, DirectX::SimpleMath::Vector2 currentPos, DirectX::SimpleMath::Vector2 target)
{
	currentlTime += timer.GetElapsedSeconds();
	if (currentlTime > interbalTime)
	{
		//ˆÚ“®•ûŒü‚Ìƒx[ƒX‚Æ‚È‚éŠp“x
		float baseAngle = atan2(target.x - currentPos.x, target.y - currentPos.y )*180/PI;
		//‹ô”’e‚Ìê‡
		if (totalNunber % 2 == 0)
		{
			for (int i = 0; i < totalNunber; i++)
			{
				if (i % 2 == 0)
				{
					shotmanager->SetShot(BaseShot(currentPos, speed, size, baseAngle + angle*((i + 2) / 2 ), true, character));
				}
				else
				{
					shotmanager->SetShot(BaseShot(currentPos, speed, size, baseAngle - angle*((i + 2) / 2 ), true, character));
				}
			}
			
		}
		//Šï”’e‚Ìê‡
		else
		{
			for (int i = 0; i < totalNunber; i++)
			{
				if (i == 0)
				{
					shotmanager->SetShot(BaseShot(currentPos, speed, size, baseAngle, true, character));
				}
				else if (i % 2 == 0)
				{
					shotmanager->SetShot(BaseShot(currentPos, speed, size, baseAngle + angle*((i + 1) / 2 ), true, character));
				}
				else
				{
					shotmanager->SetShot(BaseShot(currentPos, speed, size, baseAngle - angle*((i + 1) / 2 ), true, character));
				}
			}
		}
		currentlTime = 0;
	}
	return false;
}

void NWay::InitializeTime()
{
	currentlTime = interbalTime;
}
