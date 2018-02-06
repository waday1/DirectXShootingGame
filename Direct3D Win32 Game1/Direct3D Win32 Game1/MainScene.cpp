#include "pch.h"
#include "MainScene.h"
#include"InputManager.h"
#include<iostream>
#include"Player.h"
#include "Enemy.h"
#include < wchar.h > 

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
	delete player;
	delete enemy;
	delete shotManager;
}

void MainScene::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
	m_font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_spriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());

	player = new Player(m_d3dDevice.Get(), Vector2(100, 100), 100.0f, 1.0f, L"Player1.png", true);
	enemy = new  Enemy(m_d3dDevice.Get(), Vector2(600, 100), 100.0f, 1.0f, L"Enemy1.png", true);
	shotManager = new ShotManager(m_d3dDevice.Get());
}

void MainScene::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
	m_screenPos.x = backBufferWidth / 2.f;
	m_screenPos.y = backBufferHeight / 2.f;
}

void MainScene::Update(DX::StepTimer const& timer)
{
	player->Update(timer,shotManager);
	shotManager->Update(timer);
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


	wchar_t wStr[12];//変換後の文字列
	_itow_s(shotManager->GetShot(1).GetPosition().x, wStr, 10);//変換用関数
	m_font->DrawString(m_spriteBatch.get(), wStr, Vector2(200,100), Colors::White, 0.f, origin);

	_itow_s(shotManager->GetShot(1).GetPosition().y, wStr, 10);//変換用関数
	m_font->DrawString(m_spriteBatch.get(), wStr, Vector2(400, 100), Colors::White, 0.f, origin);

	enemy->Render(m_spriteBatch.get());

	player->Render(m_spriteBatch.get());

	shotManager->Render(m_spriteBatch.get());

	m_spriteBatch->End();
}
