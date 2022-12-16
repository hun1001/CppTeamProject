#include "pch.h"
#include "Button.h"
#include "MouseMgr.h"

Button::Button(Vec2 pos, Vec2 scale, std::wstring text) : m_vPos(pos), m_vScale(scale), m_text(text)
{
}

Button::~Button()
{
}

void Button::Update()
{
	if (MouseMgr::GetInst()->GetMouseLBtnDown())
	{
		Vec2 mousePos = MouseMgr::GetInst()->GetMousePos();
		if (mousePos.x > m_vPos.x - m_vScale.x / 2 && mousePos.x < m_vPos.x + m_vScale.x / 2 &&
			mousePos.y > m_vPos.y - m_vScale.y / 2 && mousePos.y < m_vPos.y + m_vScale.y / 2)
		{
			m_onButtonClicked();
		}
	}
}

void Button::Render(HDC _dc)
{
	Rectangle(_dc, m_vPos.x - m_vScale.x / 2.f, m_vPos.y - m_vScale.y / 2.f, m_vPos.x + m_vScale.x / 2.f, m_vPos.y + m_vScale.y / 2.f);
	TextOut(_dc, m_vPos.x - m_vScale.x / 2.f, m_vPos.y - m_vScale.y / 2.f, m_text.c_str(), m_text.size());
}
