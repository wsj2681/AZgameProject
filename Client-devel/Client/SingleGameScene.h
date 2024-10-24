#pragma once
#include "Scene.h"
class SingleGameScene : public Scene
{
public:

	SingleGameScene() = delete;
	SingleGameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~SingleGameScene() = default;

private:
	virtual void Init();

public:
	virtual void Distroy();
	virtual void Input(Event* event);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

