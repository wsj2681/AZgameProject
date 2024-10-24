#include "framework.h"
#include "SignUpScene.h"

SignUpScene::SignUpScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void SignUpScene::Init()
{
	texts["Here is SignUp Scene"] = new TextObject("Here is SignUp Scene", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 360.f, 150.f });
}

void SignUpScene::Distroy()
{
}

void SignUpScene::Input(Event* event)
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

void SignUpScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void SignUpScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void SignUpScene::Render()
{
	Scene::Render();
}
