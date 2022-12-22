#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"

Missile::Missile() : m_vDir({ 1, 0 }), m_pImage(nullptr), m_fSpeed(10), m_targetTag(L"Enemy")
{
	if(m_vDir.x >= 0)
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Right", L"Image\\Missile_Right.bmp");
	else
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Left", L"Image\\Missile_Left.bmp");
	
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
}

Missile::Missile(Vec2 _vPos, Vec2 _vDir) : m_vDir(_vDir), m_pImage(nullptr), m_fSpeed(10), m_targetTag(L"Enemy")
{
	if (m_vDir.x >= 0)
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Right", L"Image\\Missile_Right.bmp");
	else
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Left", L"Image\\Missile_Left.bmp");
	
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 15.f));
	Object::SetPos(_vPos);
}

Missile::Missile(Vec2 _vPos, Vec2 _vDir, float _fSpeed, wstring _targetTag) : m_vDir(_vDir), m_pImage(nullptr), m_fSpeed(_fSpeed), m_targetTag(_targetTag)
{
	if (m_vDir.x >= 0)
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Right", L"Image\\Missile_Right.bmp");
	else
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Left", L"Image\\Missile_Left.bmp");
	
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(150.f, 50.f));
	SetPos(_vPos);
}

Missile::~Missile()
{
}

void Missile::Update()
{
	Vec2 vPos = GetPos();
	vPos += m_vDir * m_fSpeed;
	SetPos(vPos);
}

void Missile::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	
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
	if (pOtherObj->GetName() == m_targetTag.c_str())
	{
		DeleteObject(this);
	}
}
