#pragma once
#include "Object.h"
class ButtonObject : public Object
{
public:

	ButtonObject(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);
	ButtonObject(const ButtonObject&) = delete;
	ButtonObject& operator=(const ButtonObject&) = delete;
	virtual ~ButtonObject() = default;

private:

	Texture* idleTexture = nullptr;
	Texture* activeTexture = nullptr;

	bool isPressed = false;

public:

	virtual void Destroy();

	bool IsPressed();

	virtual void Update(const Vector2f& mousePosition);

};

