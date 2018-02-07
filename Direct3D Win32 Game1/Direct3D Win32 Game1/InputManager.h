#pragma once
#include"pch.h"
class InputManager
{
public:
	InputManager();
	~InputManager();

	static void Initialize();
	static void Update();

	static bool IsJustKeyDown(DirectX::Keyboard::Keys);
	static bool IsKeyDown(DirectX::Keyboard::Keys);
	static bool IsJustKeyUp(DirectX::Keyboard::Keys);
	static bool IsKeyUp(DirectX::Keyboard::Keys);

private:
	static std::unique_ptr<DirectX::Keyboard> keyboard;
	static DirectX::Keyboard::State currentKeyboardState;
	static DirectX::Keyboard::State oldKeyboardState;
};

