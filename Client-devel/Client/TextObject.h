#pragma once
class TextObject final : public Text
{
public:

	TextObject(const string& text, const string& fontFilePath, const Vector2f& position);
	~TextObject();

private:

	bool isActive = true;

	bool isSelected = false;

	Font* font = nullptr;

public:

	void Destroy();

	bool IsActive() const;
	bool IsSelected() const;

	void SetActive(bool active);
	void SetSelected(bool selected);

	void Update();

	void Render(RenderTarget* target);
};

