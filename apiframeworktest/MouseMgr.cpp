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
}

const Vec2 MouseMgr::GetMousePos()
{
	return m_mousePos;
}
