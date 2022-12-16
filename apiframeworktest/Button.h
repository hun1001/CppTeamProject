#pragma once
#include "Object.h"

class Button : public Object
{
public:
	Button(Vec2 pos, Vec2 scale, std::wstring text);
	virtual ~Button();
	
public:
	void Update() override;
	void Render(HDC _dc) override;

	CLONE(Button);
	
public:
	void SetOnButtonClicked(std::function<void()> onButtonClicked) { m_onButtonClicked = onButtonClicked; }
	
private:
	Vec2 m_vPos;
	Vec2 m_vScale;
	std::wstring m_text;

	function<void()> m_onButtonClicked;
};

