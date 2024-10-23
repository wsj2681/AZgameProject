#include "framework.h"
#include "ButtonObject.h"

ButtonObject::ButtonObject(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	idleTexture = new Texture;
	idleTexture->loadFromFile(idleTexturePath);

	activeTexture = new Texture;
	activeTexture->loadFromFile(activeTexturePath);

	setTexture(*idleTexture);
	setOrigin(idleTexture->getSize().x / 2.f, idleTexture->getSize().y / 2.f);
	setPosition(position);
}

void ButtonObject::Destroy()
{
	DELETE(idleTexture);
	DELETE(activeTexture);
	Object::Destroy();
}

bool ButtonObject::IsPressed()
{
	return isPressed;
}

void ButtonObject::Update(const Vector2f& mousePosition)
{
	isPressed = false;

	if (getGlobalBounds().contains(mousePosition))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isPressed = true;
		}
	}

	if (isPressed)
	{
		setTexture(*activeTexture);
	}
	else
	{
		setTexture(*idleTexture);
	}

	Object::Update(mousePosition);
}
