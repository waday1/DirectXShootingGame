#include "pch.h"
#include "MainScene.h"
#include"InputManager.h"
#include<iostream>
#include"Player.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
	m_font.reset();
	m_spriteBatch.reset();
}

void MainScene::Update(DX::StepTimer const& timer)
{
	player->Update(timer);
}

void MainScene::Render()
{
	m_spriteBatch->Begin();

	if (InputManager::IsKeyDown(Keyboard::A))
	{
		m_font->DrawString(m_spriteBatch.get(), L"Main", Vector2::Zero, Colors::Red, 0.f, Vector2::Zero);
	}
	else
	{
		m_font->DrawString(m_spriteBatch.get(), L"Main", Vector2::Zero, Colors::Blue, 0.f, Vector2::Zero);
	}

	const wchar_t* output = L"Hello World";

	Vector2 origin = m_font->MeasureString(output) / 2.f;

	m_font->DrawString(m_spriteBatch.get(), output,m_fontPos, Colors::White, 0.f, origin);

	player->Render(m_spriteBatch.get());

	m_spriteBatch->End();
}

void MainScene::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());

	player =new Player(m_d3dDevice.Get(), Vector2(100, 100),100, L"Player1.png", true);
}

void MainScene::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f; 
	m_screenPos.x = backBufferWidth / 2.f;
	m_screenPos.y = backBufferHeight / 2.f;
}
