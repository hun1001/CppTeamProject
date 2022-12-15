#pragma once
#include "Object.h"

class Button : public Object
{
public:
	Button(Vec2 pos, Vec2 scale, std::string name);
	virtual ~Button();
	
public:
	void Update() override;
	void Render(HDC _dc) override;
	
private:
	Vec2 m_vPos;
	Vec2 m_vScale;
	std::string m_strName;

	function<void()> m_onButtonClicked;
};

