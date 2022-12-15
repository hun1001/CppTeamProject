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
	Vec2 GetWindowMousePos();
	Vec2 GetScreenMousePos();

private:
	Vec2 m_windowMousePos;
	Vec2 m_screenMousePos;
};

