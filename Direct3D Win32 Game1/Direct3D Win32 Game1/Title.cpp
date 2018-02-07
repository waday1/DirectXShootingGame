#include "pch.h"
#include "Title.h"
#include"InputManager.h"
#include"StageSelect.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

Title::Title()
{
}

Title::Title(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight)
{
	CreateDevice(m_d3dDevice, m_d3dContext);
	CreateResources(backBufferWidth, backBufferHeight);
}


Title::~Title()
{
	m_font.reset();
	m_spriteBatch.reset();
}

void Title::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
}

void Title::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
}

Scene* Title::Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
	UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const & timer)
{
	if (InputManager::IsJustKeyDown(Keyboard::Enter) || InputManager::IsJustKeyDown(Keyboard::Space) || InputManager::IsJustKeyDown(Keyboard::Z))
	{
		return new StageSelect(m_d3dDevice, m_d3dContext, backBufferWidth, backBufferHeight);
	}
	return this;
}

void Title::Render()
{
	m_spriteBatch->Begin();

	Vector2 origin = m_font->MeasureString(L"ShootingGame" ) / 2.f;

	m_font->DrawString(m_spriteBatch.get(), L"ShootingGame", m_fontPos, Colors::White, 0.f, origin);
	
	m_spriteBatch->End();
}
