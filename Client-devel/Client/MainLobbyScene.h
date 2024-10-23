#pragma once
#include "Scene.h"
class MainLobbyScene : public Scene
{
public:
	MainLobbyScene() = delete;
	MainLobbyScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~MainLobbyScene() = default;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Input(Event* event);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};

