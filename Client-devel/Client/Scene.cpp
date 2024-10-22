#include "framework.h"
#include "Scene.h"

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window)
	:scenes(scenes), window(window)
{
	Init();
}

void Scene::Init()
{

}

void Scene::EndScene()
{
	Quit = true;
}

bool Scene::GetQuit()
{
	return Quit;
}

void Scene::Destroy()
{
	// delete objects
}

void Scene::Input(Event* event)
{
	switch (event->type)
	{
	// Ű���� �Է�
	case Event::KeyPressed:
	{
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

void Scene::Update(const Vector2f& mousePosition)
{
	for (auto& obj : objects)
	{
		obj->Update(mousePosition);
	}

	// button behavior

}

void Scene::Update(const float& deltaTime)
{
	for (auto& obj : objects)
	{
		obj->Update(deltaTime)
	}
}

void Scene::Render()
{
	if (backGround)
	{
		backGround->Render(window);
	}

	for (auto& obj : objects)
	{
		obj->Render(window);
	}
}
