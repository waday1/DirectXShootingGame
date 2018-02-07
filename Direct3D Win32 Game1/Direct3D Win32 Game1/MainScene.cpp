#include "pch.h"
#include "MainScene.h"
#include"InputManager.h"
#include<iostream>
#include"Player.h"
#include "Enemy.h"
#include < wchar.h > 
#include"BoxCollider.h"
#include"Title.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;


MainScene::MainScene()
{
}

MainScene::MainScene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
	UINT backBufferWidth, UINT backBufferHeight, int stageNum)
{
	CreateResources(backBufferWidth, backBufferHeight, stageNum);
	CreateDevice( m_d3dDevice,  m_d3dContext);
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

	player = new Player(m_d3dDevice.Get(), Vector2(400, 400), 200.0f, 1.0f, L"Player1.png", true);
	enemy = new  Enemy(m_d3dDevice.Get(), Vector2(400, 100), 200.0f, 1.0f,100, L"Enemy1.png", BoxCollider(), true,stageNum);
	shotManager = new ShotManager(m_d3dDevice.Get());
}

void MainScene::CreateResources(UINT backBufferWidth, UINT backBufferHeight, int stageNum)
{
	m_fontPos.x = backBufferWidth / 2.f;
	m_fontPos.y = backBufferHeight / 2.f;
	m_screenPos.x = backBufferWidth / 2.f;
	m_screenPos.y = backBufferHeight / 2.f;

	this->stageNum = stageNum;
}

Scene* MainScene::Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
	UINT backBufferWidth, UINT backBufferHeight,
	DX::StepTimer const& timer)
{
	player->Update(timer,shotManager);
	enemy->Update(timer, shotManager, player->GetPosition());
	shotManager->Update(timer,player,enemy);
	if (!player->GetIsAlive() || !enemy->GetIsAlive())
	{
		return new Title(m_d3dDevice, m_d3dContext, backBufferWidth, backBufferHeight);
	}
	return this;
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


	wchar_t wStr[12];//�ϊ���̕�����
	_itow_s(enemy->GetLife(), wStr, 10);//�ϊ��p�֐�
	m_font->DrawString(m_spriteBatch.get(), wStr, Vector2(0,200), Colors::White, 0.f, Vector2::Zero);


	if (player->GetIsAlive())
	player->Render(m_spriteBatch.get());

	if(enemy->GetIsAlive())
	enemy->Render(m_spriteBatch.get());

	

	shotManager->Render(m_spriteBatch.get());

	m_spriteBatch->End();
}
