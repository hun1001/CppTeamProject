#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animation.h"
#include "Animator.h"
#include "SoundMgr.h"
#include "Explosion.h"
#include "Scene.h"


Missile::Missile(Vec2 _vPos, Vec2 _vDir, float _fSpeed, vector<wstring> _targetTag, wstring _name) : m_vDir(_vDir), m_pImage(nullptr), m_fSpeed(_fSpeed), m_bIsMove(true)
{
	DefualtSetting();

	m_targetTag = _targetTag;
	
	SetPos(_vPos);
	SetName(_name);
}

Missile::~Missile()
{
	
}

void Missile::BombMissile()
{
	 m_bIsMove = false;	
	
	
	
	Vec2 currentPos = this->GetPos();
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_EFFECT);
	SoundMgr::GetInst()->Play(L"MissileExplosion");
	Explosion* pExplosion = new Explosion(currentPos);
	DeleteObject(this);
}

void Missile::DefualtSetting()
{
	if (m_vDir.x >= 0)
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Right", L"Image\\Missile_Right.bmp");
	else
		m_pImage = ResMgr::GetInst()->ImgLoad(L"MissileImg_Left", L"Image\\Missile_Left.bmp");

	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2(150.f, 50.f));

	SoundMgr::GetInst()->LoadSound(L"MissileMove", false, L"Sound\\Missile.wav");
	SoundMgr::GetInst()->Play(L"MissileMove");

	SoundMgr::GetInst()->LoadSound(L"MissileExplosion", false, L"Sound\\Bomb.mp3");
}

void Missile::Update()
{
	if (m_bIsMove)
	{
		Vec2 vPos = GetPos();
		vPos += m_vDir * m_fSpeed;
		SetPos(vPos);
	}
}

void Missile::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	
	if (m_bIsMove)
	{
		TransparentBlt(_dc, vPos.x - Width / 2.f, vPos.y - Height / 2.f, Width, Height, m_pImage->GetDC(), 0, 0, Width, Height, RGB(255, 0, 255));
	}
	
	
	Component_Render(_dc);
}


void Missile::EnterCollision(Collider* _pOther)
{	
	Object* pOtherObj = _pOther->GetObj();
	wstring name = pOtherObj->GetName();
	for (int i = 0; i < m_targetTag.size(); i++)
	{
		if (name == m_targetTag[i].c_str())
		{
			BombMissile();
			

			break;
		}
	}
}
