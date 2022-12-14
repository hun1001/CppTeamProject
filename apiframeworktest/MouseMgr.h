#pragma once

class MouseMgr 
{
public:
	SINGLE(MouseMgr);

private:
	MouseMgr();
	~MouseMgr();

public:
	void Init();
	void Update();
	
public:
	const Vec2 GetMousePos();
	const bool GetMouseLBtnDown();

private:
	Vec2 m_mousePos;
	bool m_bLBtnDown;
};
