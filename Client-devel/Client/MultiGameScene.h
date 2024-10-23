#pragma once
#include "Scene.h"
class MultiGameScene : public Scene
{
public:
	MultiGameScene() = delete;
	MultiGameScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~MultiGameScene() = default;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};

