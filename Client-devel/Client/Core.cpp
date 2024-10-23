#include "framework.h"
#include "Core.h"
#include "TitleScene.h"

Core::Core()
{
	Init();
}

Core::~Core()
{
	Destroy();
}

void Core::Init()
{
	window = new RenderWindow(VideoMode(1080, 720), "SFML Window");
	window->setFramerateLimit(120);

	event = new Event;
	clock = new Clock;
	frameClock = new Clock;

	scenes.push(new TitleScene(&scenes, window));

}

void Core::Destroy()
{
	DELETE(clock);
	DELETE(frameClock);
	DELETE(event);
	DELETE(window);

	for (size_t i = 0; i < scenes.size(); ++i)
	{
		scenes.top()->Destroy();
		scenes.top() = nullptr;
		delete scenes.top();
		scenes.pop();
	}

}

void Core::Input()
{
	while (window->pollEvent(*event))
	{
		switch (event->type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::KeyPressed:
		case Event::MouseButtonPressed:
		case Event::MouseWheelMoved:
		{
			if (!scenes.empty())
			{
				scenes.top()->Input(event);
			}
			break;
		}
		default:
			break;
		}
	}
}

void Core::Update()
{
	deltaTime = clock->getElapsedTime().asSeconds();
	clock->restart();

	if (frameClock->getElapsedTime().asSeconds() >= 1.f)
	{
		FPS = frame;
		frame = 0;
		frameClock->restart();
		elapsedTime += deltaTime;

		ostringstream oss;
		oss << "SFML FPS(" << FPS << ")";
		window->setTitle(oss.str());
	}
	++frame;

	mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	if (!scenes.empty())
	{
		if (scenes.top()->GetQuit())
		{
			scenes.top()->Destroy();
			scenes.top() = nullptr;
			delete scenes.top();
			scenes.pop();
		}
		else
		{
			scenes.top()->Update(deltaTime);
			scenes.top()->Update(mousePosition);
		}
	}
	else
	{
		window->close();
	}
}

bool Core::Render()
{
	if (window->isOpen())
	{
		window->clear();

		Input();
		Update();

		if (!scenes.empty())
		{
			scenes.top()->Render();
		}

		window->display();
		return true;
	}
	else
	{
		return false;
	}
}