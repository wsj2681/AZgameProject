#include "framework.h"
#include "TitleScene.h"
#include "MainLobbyScene.h"

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void TitleScene::Init()
{
	texts["Game Tilte"] = new TextObject("Game Title", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 250.f });
}

void TitleScene::Distroy()
{
	Scene::Destroy();
}

void TitleScene::Input(Event* event)
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
			EndScene();
			break;
		}
		default:
			break;
		}
		break;
	}

	// 마우스 입력
	case Event::MouseButtonPressed:
	{
		scenes->push(new MainLobbyScene(scenes, window));
		break;
	}
	default:
		break;
	}
}

void TitleScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void TitleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TitleScene::Render()
{
	Scene::Render();
}
