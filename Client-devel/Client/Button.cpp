#include "framework.h"
#include "Button.h"

Button::Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	idleTexture = new Texture;
	idleTexture->loadFromFile(idleTexturePath);

	activeTexture = new Texture;
	activeTexture->loadFromFile(activeTexturePath);

	setTexture(*idleTexture);
	setOrigin(getGlobalBounds().width / 2.f, getGlobalBounds().height / 2.f);
	setPosition(position);
}

void Button::Destroy()
{
	DELETE(idleTexture);
	DELETE(activeTexture);
}

bool Button::IsPressed()
{
	return isPress;
}

void Button::Update(const Vector2f& mousePosition)
{
	isPress = false;

	if (getGlobalBounds().contains(mousePosition))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			isPress = true;
		}
	}

	if (isPress)
	{
		//setTexture(*activeTexture);
		setScale({ 0.8f, 0.8f });
	}
	else
	{
		setScale({ 1.f, 1.f });
		//setTexture(*idleTexture);
	}
}

void Button::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(*this);
	}
}
