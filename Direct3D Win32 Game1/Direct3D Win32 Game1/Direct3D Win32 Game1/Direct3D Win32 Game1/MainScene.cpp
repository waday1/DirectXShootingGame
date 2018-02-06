#include "pch.h"
#include "MainScene.h"
#include"InputManager.h"
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
	m_texture.Reset();
}

void MainScene::Update()
{
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
	m_spriteBatch->Draw(m_texture.Get(), m_screenPos, nullptr, Colors::White,
		0.f, m_origin);
	m_spriteBatch->End();
}

void MainScene::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(m_d3dDevice.Get(), L"cat.png", nullptr,
			m_texture.ReleaseAndGetAddressOf())); m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());

	Microsoft::WRL::ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(m_d3dDevice.Get(), L"cat.png",
			resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	Microsoft::WRL::ComPtr<ID3D11Texture2D> cat;
	DX::ThrowIfFailed(resource.As(&cat));

	CD3D11_TEXTURE2D_DESC catDesc;
	cat->GetDesc(&catDesc);

	m_origin.x = float(catDesc.Width / 2);
	m_origin.y = float(catDesc.Height / 2);
}

void MainScene::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f; 
	m_screenPos.x = backBufferWidth / 2.f;
	m_screenPos.y = backBufferHeight / 2.f;
}
