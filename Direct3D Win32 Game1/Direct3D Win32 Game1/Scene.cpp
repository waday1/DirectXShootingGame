#include "pch.h"
#include "Scene.h"
#include<iostream>
#include<stdio.h>

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

Scene::Scene()
{
}


Scene::Scene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight)
{
}

Scene::Scene(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext, UINT backBufferWidth, UINT backBufferHeight, int stageNum)
{
}

Scene::~Scene()
{
}

void Scene::CreateDevice(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext)
{
}

void Scene::CreateResources(UINT backBufferWidth, UINT backBufferHeight)
{
}

void Scene::CreateResources(UINT backBufferWidth, UINT backBufferHeight, int stageNum)
{
}

Scene* Scene::Update(Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext,
	UINT backBufferWidth, UINT backBufferHeight, DX::StepTimer const& timer)
{
	cout << "Scene";
	printf("Scene");
	return this;
}

void Scene::Render()
{
	//m_spriteBatch->Begin();

	//const wchar_t* output = L"Hello World";

	//Vector2 origin = m_font->MeasureString(output) / 2.f;

	//m_font->DrawString(m_spriteBatch.get(), output, m_fontPos, Colors::White, 0.f, origin);
	//m_font->DrawString(m_spriteBatch.get(), L"Main", Vector2::Zero, Colors::Red, 0.f, Vector2::Zero);

	//m_spriteBatch->End();
}

