#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"

Missile::Missile() : m_fTheta(3.f * M_PI/2.f), m_vDir(Vec2(1.f,1.f))
{

	//enter key spade create Missile 
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Missile", L"Image\\Missile.bmp");
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

Missile::~Missile()
{
}


void Missile::Update()
{
 	
}

void Missile::Render(HDC _dc)
{
	//Vec2 vPos = GetPos();
	//Vec2 vScale = GetScale();
	//Ellipse(_dc,
	//	  (int)(vPos.x - vScale.x / 2.f)
	//	, (int)(vPos.y - vScale.y / 2.f)
	//	, (int)(vPos.x + vScale.y / 2.f)
	//	, (int)(vPos.y + vScale.y / 2.f));
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(255, 0, 255));
	Component_Render(_dc);
}

void Missile::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"ENEMY")
	{
		DeleteObject(this);
	}
}
