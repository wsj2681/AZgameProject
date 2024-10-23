#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:

	TitleScene() = delete;
	TitleScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~TitleScene() = default;

private:
	virtual void Init();

public:
	virtual void Distroy();
	virtual void Input(Event* event);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

