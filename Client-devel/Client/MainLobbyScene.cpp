#include "framework.h"
#include "MainLobbyScene.h"
#include "SignInScene.h"
#include "SignUpScene.h"
#include "SingleGameScene.h"
#include "MultiGameScene.h"

MainLobbyScene::MainLobbyScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void MainLobbyScene::Init()
{
	texts["Game Title"] = new TextObject("Game Tilte", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 360.f, 150.f });

	texts["Game Setting"] = new TextObject("Setting", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 980.f, 25.f });
	texts["Sign In"] = new TextObject("Sign In", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 980.f, 75.f });
	texts["Sign Up"] = new TextObject("Sign Up", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 980.f, 125.f });
	texts["Single Game"] = new TextObject("Single Game", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 500.f });
	texts["Multi Game"] = new TextObject("Multi Game", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 650.f, 500.f });
	texts["Ranking"] = new TextObject("Ranking", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 250.f, 600.f });
	texts["In additional"] = new TextObject("additional", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 650.f, 600.f });
}

void MainLobbyScene::Destroy()
{
	Scene::Destroy();
}

void MainLobbyScene::Input(Event* event)
{
	switch (event->type)
	{
	case Event::KeyPressed:
	{
		break;
	}
	case Event::MouseButtonPressed:
	{
		cout << "x:" << Mouse::getPosition(*window).x << "/ y:" << Mouse::getPosition(*window).y << endl;
		break;
	}
	default:
		break;
	}
}

void MainLobbyScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);

	for (auto& text : texts)
	{
		if (text.second->getGlobalBounds().contains(mousePosition))
		{
			text.second->setFillColor(Color::Red);

			if (text.first == "Sign In" && Mouse::isButtonPressed(Mouse::Left))
			{
				scenes->push(new SignInScene(scenes, window));
			}
			else if (text.first == "Sign Up" && Mouse::isButtonPressed(Mouse::Left))
			{
				scenes->push(new SignUpScene(scenes, window));
			}
			else if (text.first == "Single Game" && Mouse::isButtonPressed(Mouse::Left))
			{
				scenes->push(new SingleGameScene(scenes, window));
			}
			else if (text.first == "Multi Game" && Mouse::isButtonPressed(Mouse::Left))
			{
				scenes->push(new MultiGameScene(scenes, window));
			}
		}
		else
		{
			text.second->setFillColor(Color::White);
		}
	}
}

void MainLobbyScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void MainLobbyScene::Render()
{
	Scene::Render();
}
