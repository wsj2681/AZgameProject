#pragma once
class Object : public Sprite
{
public:
	Object();
	Object(const string& textureFilePath);
	Object(const string& textureFilePath, const Vector2f& position);
	virtual ~Object() = default;

protected:

	bool isActive = true;

private:

	Texture* texture = nullptr;

	// debugBox Vertices
	Vertex* vertices = nullptr;
	Color boxColor = Color::Red;
	bool debugBox = true;

public:

	virtual void Destroy();

	void SetDebugBoxActive(bool isActive);
	void SetActive(bool isActive);
	bool IsActive();

	void SetBoxColor(const Color& color);
	void SetBoxColor(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a);


	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};

