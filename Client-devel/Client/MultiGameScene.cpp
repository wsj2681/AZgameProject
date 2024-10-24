#include "framework.h"
#include "MultiGameScene.h"

MultiGameScene::MultiGameScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void MultiGameScene::Init()
{
	texts["Here is MultiGame Scene"] = new TextObject("Here is MultiGame Scene", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 360.f, 150.f });
}

void MultiGameScene::Destroy()
{
	Scene::Destroy();
}

void MultiGameScene::Input(Event* event)
{
	switch (event->type)
	{
		// Ű���� �Է�
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

	// ���콺 �Է�
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
