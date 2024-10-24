#pragma once
#include "Scene.h"
class SignInScene : public Scene
{
public:

	SignInScene() = delete;
	SignInScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~SignInScene() = default;

private:
	virtual void Init();

public:
	virtual void Distroy();
	virtual void Input(Event* event);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

