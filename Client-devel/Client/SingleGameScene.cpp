#include "framework.h"
#include "SingleGameScene.h"

SingleGameScene::SingleGameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void SingleGameScene::Init()
{
	texts["Here is SingleGame Scene"] = new TextObject("Here is SingleGame Scene", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 360.f, 150.f });
}

void SingleGameScene::Distroy()
{
}

void SingleGameScene::Input(Event* event)
{
	switch (event->type)
	{
		// 키보드 입력
	case Event::KeyPressed:
	{
		switch (event->key.code)
		{
		case Keyboard::Escape:
		{
			scenes->top()->Destroy();
			scenes->pop();
		}
		default:
			break;
		}
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

void SingleGameScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void SingleGameScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void SingleGameScene::Render()
{
	Scene::Render();
}
