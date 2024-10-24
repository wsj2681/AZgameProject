#include "framework.h"
#include "SignInScene.h"

SignInScene::SignInScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void SignInScene::Init()
{
	texts["Here is SignIn Scene"] = new TextObject("Here is SignIn Scene", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 360.f, 150.f });
}

void SignInScene::Distroy()
{
	for (auto& text : texts)
	{
		delete text.second;
	}
}

void SignInScene::Input(Event* event)
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

void SignInScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
}

void SignInScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void SignInScene::Render()
{
	Scene::Render();
}
