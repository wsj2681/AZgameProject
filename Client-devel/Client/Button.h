#pragma once
class Button : public Sprite
{
	Button() = default;
	Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);
	Button(const Button&) = delete;
	Button& operator=(const Button&) = delete;
	virtual ~Button() = default;

private:
	Texture* idleTexture = nullptr;
	Texture* activeTexture = nullptr;

	bool isPress = false;

public:

	void Destroy();
	bool IsPressed();
	void Update(const Vector2f& mousePosition);
	void Render(RenderTarget* target);
};

