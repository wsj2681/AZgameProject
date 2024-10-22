#include "framework.h"
#include "Object.h"

Object::Object()
{
	vertices = new Vertex[5];
}

Object::Object(const string& textureFilePath)
{
	this->texture = new Texture;

	if (this->texture->loadFromFile(textureFilePath))
	{
		setTexture(*this->texture);

		// GlobalBoundBox
		auto gbb = this->getGlobalBounds();

		setOrigin(gbb.width / 2.f, gbb.height / 2.f);

		vertices = new Vertex[5];
		vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
		vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
		vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
		vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
		vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	}
}


Object::Object(const string& textureFilePath, const Vector2f& position)
	:Object(textureFilePath)
{
	setPosition(position);
}

void Object::Destroy()
{
	DELETE(texture);
	DELETE(vertices);
}

void Object::SetDebugBoxActive(bool isActive)
{
	this->debugBox = isActive;
}

void Object::SetActive(bool isActive)
{
	this->isActive = isActive;
}

bool Object::IsActive()
{
	return isActive;
}

void Object::SetBoxColor(const Color& color)
{
	this->boxColor = color;
}

void Object::SetBoxColor(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a)
{
	SetBoxColor(Color(r, g, b, a));
}

void Object::Update(const float& deltaTime)
{
	auto gbb = this->getGlobalBounds();
	vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
	vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
	vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
	vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
}

void Object::Update(const Vector2f& mousePosition)
{
	auto gbb = this->getGlobalBounds();
	vertices[0] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
	vertices[1] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top), boxColor));
	vertices[2] = (Vertex(Vector2f(gbb.left + gbb.width, gbb.top + gbb.height), boxColor));
	vertices[3] = (Vertex(Vector2f(gbb.left, gbb.top + gbb.height), boxColor));
	vertices[4] = (Vertex(Vector2f(gbb.left, gbb.top), boxColor));
}

void Object::Render(RenderTarget* target)
{
	if (target && isActive)
	{
		target->draw(*this);

		if (vertices && debugBox)
		{
			target->draw(this->vertices, 5, LinesStrip);
		}
	}
}
