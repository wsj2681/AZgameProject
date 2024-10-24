#include "framework.h"
#include "SignUpScene.h"

SignUpScene::SignUpScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

void SignUpScene::Init()
{
	window->setKeyRepeatEnabled(false);
	texts["ID Input"] = new TextObject("ID : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 150.f, 150.f });
	texts["ID Input"]->setOrigin(texts["ID Input"]->getOrigin().x * 2.f, texts["ID Input"]->getOrigin().y / 2.f);
	
	texts["Email Input"] = new TextObject("Email : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 150.f, 200.f });
	texts["Email Input"]->setOrigin(texts["Email Input"]->getOrigin().x * 2.f, texts["Email Input"]->getOrigin().y / 2.f);
	
	texts["Password Input"] = new TextObject("PW : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 150.f, 250.f });
	texts["Password Input"]->setOrigin(texts["Password Input"]->getOrigin().x * 2.f, texts["Password Input"]->getOrigin().y / 2.f);

	texts["Password_add Input"] = new TextObject("PW_add : ", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 150.f, 300.f });
	texts["Password_add Input"]->setOrigin(texts["Password_add Input"]->getOrigin().x * 2.f, texts["Password_add Input"]->getOrigin().y / 2.f);

	texts["ID Duplication"] = new TextObject("Duplication Check", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 850.f, 150.f });
	texts["Email Duplication"] = new TextObject("Duplication Check", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 850.f, 200.f });
	texts["Verify"] = new TextObject("Verify", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 720.f, 670.f });
	texts["Cancle"] = new TextObject("Cancle", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 900.f, 670.f });


	texts["Input ID"] = new TextObject("+", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 160.f, 150.f });
	texts["Input Email"] = new TextObject("+", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 160.f, 200.f });
	texts["Input PW"] = new TextObject("+", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 160.f, 250.f });
	texts["Input PW2"] = new TextObject("+", "Font/CookieRunFont_TTF/CookieRun_Bold.ttf", { 160.f, 300.f });
}

void SignUpScene::Distroy()
{
}

void SignUpScene::Input(Event* event)
{
	// TODO LIST : 각 스트링에 해당하는 texts가 선택상태일 때 문자열을 입력할 수 있게하기.
	static String id;
	static String email;
	static String pw;
	static String pw2;

	switch (event->type)
	{
	case Event::TextEntered:
	{
		if (event->text.unicode < 128)
		{
			for (auto& text : texts)
			{
				if (text.second->IsSelected())
				{
					char inputChar = static_cast<int>(event->text.unicode);
					if (inputChar == '\b')
					{
						
					}
				}
			}
			
		}
		break;
	}

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

	for (auto& text : texts)
	{
		if (text.second->getGlobalBounds().contains(mousePosition))
		{
			if (text.first == "ID Duplication" || text.first == "Email Duplication" || text.first == "Verify" || (text.first == "Cancle"))
			{
				text.second->setFillColor(Color::Red);
			}
			// TODO : MousebuttonReleased
			if (text.first == "ID Duplication" && Mouse::isButtonPressed(Mouse::Left))
			{
				
			}
			if (text.first == "Email Duplication" && Mouse::isButtonPressed(Mouse::Left))
			{
				
			}
			if (text.first == "Verify" && Mouse::isButtonPressed(Mouse::Left))
			{
				
			}
			if (text.first == "Cancle" && Mouse::isButtonPressed(Mouse::Left))
			{
				scenes->top()->Destroy();
				scenes->pop();
			}
		}
		else
		{
			text.second->SetSelected(false);
			text.second->setFillColor(Color::White);
		}

		if (text.second->IsSelected())
		{
			cout << text.second->getString().toAnsiString() << endl;
		}

	}

}

void SignUpScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void SignUpScene::Render()
{
	Scene::Render();
}
