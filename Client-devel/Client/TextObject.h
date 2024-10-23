#pragma once
class TextObject final : public Text
{
public:

	TextObject(const string& text, const string& fontFilePath, const Vector2f& position);
	~TextObject();

private:

	bool isActive = true;

	Font* font = nullptr;

public:

	void Destroy();

	bool IsActive() const;
	void SetActive(bool active);

	void Update();

	void Render(RenderTarget* target);
};

