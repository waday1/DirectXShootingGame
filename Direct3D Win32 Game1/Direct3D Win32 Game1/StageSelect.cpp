#include "pch.h"
#include "StageSelect.h"
#include"MainScene.h"
#include"InputManager.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

StageSelect::StageSelect()
{
}

StageSelect::StageSelect(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight)
{
	CreateDevice(m_d3dDevice, m_d3dContext);
	CreateResources(backBufferWidth, backBufferHeight);
}


StageSelect::~StageSelect()
{
	m_font.reset();
	m_spriteBatch.reset();
}

void StageSelect::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
}

void StageSelect::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	stageNum = 1;
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
}

Scene * StageSelect::Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const & timer)
{
	StageMove();
	if (InputManager::IsJustKeyDown(Keyboard::Enter) || InputManager::IsJustKeyDown(Keyboard::Space) || InputManager::IsJustKeyDown(Keyboard::Z))
	{
		return new MainScene(m_d3dDevice, m_d3dContext, backBufferWidth, backBufferHeight,stageNum);
	}
	return this;
}

void StageSelect::StageMove()
{
	if (InputManager::IsJustKeyDown(Keyboard::Up))
	{
		stageNum++;
		if (stageNum > stageNumMax)
		{
			stageNum = 1;
		}
	}if (InputManager::IsJustKeyDown(Keyboard::Down))
	{
		stageNum--;
		if (stageNum <=0)
		{
			stageNum = stageNumMax;
		}
	}
}

void StageSelect::Render()
{
	m_spriteBatch->Begin();

	wchar_t wStr[12];//•ÏŠ·Œã‚Ì•¶Žš—ñ
	_itow_s(stageNum, wStr, 10);//•ÏŠ·—pŠÖ”

	Vector2 origin = m_font->MeasureString(L"Stage") / 2.f;

	m_font->DrawString(m_spriteBatch.get(), L"Stage", m_fontPos, Colors::White, 0.f, origin);
	m_font->DrawString(m_spriteBatch.get(), wStr,Vector2( m_fontPos.x+origin.x,m_fontPos.y), Colors::White, 0.f, Vector2(0,origin.y));

	m_spriteBatch->End();
}
