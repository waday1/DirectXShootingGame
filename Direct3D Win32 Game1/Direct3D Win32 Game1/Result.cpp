#include "pch.h"
#include"InputManager.h"
#include "Result.h"
#include"Title.h"


using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

Result::Result()
{
}


Result::Result(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight, bool isClear)
{
	this->isClear = isClear;
	CreateDevice(m_d3dDevice, m_d3dContext);
	CreateResources(backBufferWidth, backBufferHeight);
}

Result::~Result()
{
	m_font.reset();
	m_spriteBatch.reset();
}

void Result::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
}

void Result::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
}

Scene * Result::Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const & timer)
{
	if (InputManager::IsJustKeyDown(Keyboard::Enter) || InputManager::IsJustKeyDown(Keyboard::Space) || InputManager::IsJustKeyDown(Keyboard::Z))
	{
		return new Title(m_d3dDevice, m_d3dContext, backBufferWidth, backBufferHeight);
	}
	return this;
}

void Result::Render()
{
	m_spriteBatch->Begin();

	if (isClear)
	{
		Vector2 origin = m_font->MeasureString(L"Clear") / 2.f;

		m_font->DrawString(m_spriteBatch.get(), L"Clear", m_fontPos, Colors::White, 0.f, origin);

	}
	else
	{
		Vector2 origin = m_font->MeasureString(L"GameOver") / 2.f;

		m_font->DrawString(m_spriteBatch.get(), L"GameOver", m_fontPos, Colors::White, 0.f, origin);
	}
	m_spriteBatch->End();
}
