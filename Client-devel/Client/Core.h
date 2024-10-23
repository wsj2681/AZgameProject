#pragma once
#include "Scene.h"
class Core final
{
public:
	Core();
	Core(const Core&) = delete;
	Core& operator=(const Core&) = delete;
	~Core();

private:
	RenderWindow* window = nullptr;
	stack<Scene*> scenes;

	Event* event = nullptr;
	Vector2f mousePosition{ 0.f, 0.f };

	Clock* clock = nullptr;
	float deltaTime = 0.f;
	float elapsedTime = 0.f;

	Clock* frameClock = nullptr;
	unsigned int frame = 0;
	unsigned int FPS = 0;

private:

	void Init();
	void Destroy();
	void Input();
	void Update();

public:

	bool Render();
};

