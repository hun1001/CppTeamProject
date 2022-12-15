#include "pch.h"
#include "Button.h"

Button::Button(Vec2 pos, Vec2 scale, std::string name)
{
}

Button::~Button()
{
}

void Button::Update()
{
}

void Button::Render(HDC _dc)
{
	Rectangle(_dc, m_vPos.x - m_vScale.x / 2.f, m_vPos.y - m_vScale.y / 2.f, m_vPos.x + m_vScale.x / 2.f, m_vPos.y + m_vScale.y / 2.f);
}
