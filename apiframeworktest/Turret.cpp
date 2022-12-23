#include "pch.h"
#include "Turret.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Missile.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "Image.h"

Turret::Turret()
{
	// collider ����
	/*CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));*/

	// image ���ε�
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Player", L"Image\\Turretc.bmp");
	

	 //animator ���� �� animation ���
	//CreateAnimator();
	//GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	//GetAnimator()->Play(L"Jiwoofront", true);

	 //animation offset ���� �ø���. 
	/*Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for(size_t i=0;i<pAnim->GetMaxFrame();i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);*/
}

Turret::~Turret()
{
	
}

void Turret::Update()
{
	Vec2 vPos = GetPos();
	if(KEY_HOLD(KEY::W))
	{
		vPos.y -= 300.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 300.f * fDT;
	}
	SetPos(vPos);
}

void Turret::Render(HDC _dc)
{
	//Component_Render(_dc);
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	Vec2 vPos = GetPos();
	
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		,Width, Height
	    , m_pImage->GetDC()
	    ,0,0, Width, Height
	    , RGB(255,0,255));

}
