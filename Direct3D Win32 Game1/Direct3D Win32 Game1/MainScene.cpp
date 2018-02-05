#include "pch.h"
#include "MainScene.h"
#include<iostream>

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

void MainScene::Update()
{
	cout << "MainScene";
}

void MainScene::Render()
{
	m_spriteBatch->Begin();

	const wchar_t* output = L"Hello World";

	Vector2 origin = m_font->MeasureString(output) / 2.f;

	m_font->DrawString(m_spriteBatch.get(), output,m_fontPos, Colors::White, 0.f, origin);
	m_font->DrawString(m_spriteBatch.get(), L"Main", Vector2::Zero, Colors::Red, 0.f, Vector2::Zero);

	m_spriteBatch->End();
}

void MainScene::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
}

void MainScene::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
}
