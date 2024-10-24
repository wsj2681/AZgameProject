#pragma once
#include "Scene.h"
class SignUpScene : public Scene
{
public:

	SignUpScene() = delete;
	SignUpScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~SignUpScene() = default;

private:
	virtual void Init();

public:
	virtual void Distroy();
	virtual void Input(Event* event);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();

};

