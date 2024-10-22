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
}

void Scene::Update(const float& deltaTime)
{
}

void Scene::Render()
{
}
