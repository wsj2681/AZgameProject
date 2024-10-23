#include "framework.h"
#include "TextObject.h"

TextObject::TextObject(const string& text, const string& fontFilePath, const Vector2f& position)
{
	font = new Font;
	font->loadFromFile(fontFilePath);
	this->setFont(*font);
	this->setString(text);
	this->setFillColor(Color::White);
	this->setOrigin(getLocalBounds().width / 2.f, getLocalBounds().height / 2.f);
	this->setPosition(position);
}

TextObject::~TextObject()
{
}

void TextObject::Destroy()
{
	DELETE(font);
}

bool TextObject::IsActive() const
{
	return isActive;
}

void TextObject::SetActive(bool active)
{
	this->isActive = active;
}

void TextObject::Update()
{

}

void TextObject::Render(RenderTarget* target)
{
	if (target && isActive)
	{
		target->draw(*this);
	}

}
