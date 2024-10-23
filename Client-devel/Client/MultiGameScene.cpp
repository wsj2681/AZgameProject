#include "framework.h"
#include "MultiGameScene.h"

MultiGameScene::MultiGameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void MultiGameScene::Init()
{


	//buttons["Game Setting"] = new ButtonObject("Game Setting")
}

void MultiGameScene::Destroy()
{
	Scene::Destroy();
}

void MultiGameScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		break;
	}
	default:
		break;
	}
}

void MultiGameScene::Update(const Vector2f& mousePosition)
{
}

void MultiGameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void MultiGameScene::Render()
{
	Scene::Render();
}
