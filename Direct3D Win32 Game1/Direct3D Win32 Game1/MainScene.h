#pragma once
#include "Scene.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

public:
	void Update();
	void Render();
};

