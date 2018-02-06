#include "pch.h"
#include "InputManager.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;

std::unique_ptr<DirectX::Keyboard> InputManager::keyboard;
Keyboard::State InputManager::currentKeyboardState;
Keyboard::State InputManager::oldKeyboardState;

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Initialize()
{
	keyboard = std::make_unique<Keyboard>();
	currentKeyboardState = keyboard->GetState();
	oldKeyboardState = currentKeyboardState;
}

void InputManager::Update()
{
	oldKeyboardState = currentKeyboardState;
	currentKeyboardState = keyboard->GetState();
}

bool InputManager::IsJustKeyDown(DirectX::Keyboard::Keys key)
{
	bool down = false;

	if (keyboard)
	{
		if (oldKeyboardState.IsKeyUp(key) && currentKeyboardState.IsKeyDown(key))
		{
			down = true;
		}
	}

	return down;
}

bool InputManager::IsKeyDown(DirectX::Keyboard::Keys key)
{
	bool isDown = false;

	if (keyboard)
	{
		if (currentKeyboardState.IsKeyDown(key))
		{
			isDown = true;
		}
	}

	return isDown;
}
