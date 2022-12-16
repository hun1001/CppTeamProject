#include "pch.h"
#include "MouseMgr.h"
#include "Core.h"

MouseMgr::MouseMgr() : m_mousePos()
{
}

MouseMgr::~MouseMgr()
{
}

void MouseMgr::Init()
{
}

void MouseMgr::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(Core::GetInst()->GetWndHandle(), &pt);
	m_mousePos = pt;

	m_bLBtnDown = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
}

const Vec2 MouseMgr::GetMousePos()
{
	return m_mousePos;
}

const bool MouseMgr::GetMouseLBtnDown()
{
	return m_bLBtnDown;
}
