#include "pch.h"
#include "Object.h"
//#include "KeyMgr.h"
//#include "TimeMgr.h"
#include "Collider.h"
#include "Animator.h"
//void Object::Update()
//{
//
//}

Object::Object()
	: m_vPos{}
	, m_vScale{}
	, m_pCollider(nullptr)
	, m_pAnimator(nullptr)
	, m_bAlive(true)
{
}

Object::Object(const Object& _origin)
	: m_strName(_origin.m_strName)
	, m_vPos(_origin.m_vPos)
	, m_vScale(_origin.m_vScale)
	, m_pCollider(nullptr)
	, m_pAnimator(nullptr)
	, m_bAlive(true)
{
	if (_origin.m_pCollider)
	{
		m_pCollider = new Collider(*_origin.m_pCollider);
		m_pCollider->m_pOwner = this;
	}
	if (_origin.m_pAnimator)
	{
		m_pAnimator = new Animator(*_origin.m_pAnimator);
		m_pAnimator->m_pOwner = this;
	}
}

Object::~Object()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
}

void Object::FinalUpdate()
{
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}

void Object::Render(HDC _dc)
{
	HDC hMemDC = CreateCompatibleDC(_dc);
	
	Rectangle(hMemDC,
		 (int)(m_vPos.x - m_vScale.x / 2.f)
		,(int)(m_vPos.y - m_vScale.y / 2.f)
		,(int)(m_vPos.x + m_vScale.y / 2.f)
		,(int)(m_vPos.y + m_vScale.y / 2.f));

	POINT pt[3];
	pt[0].x = (int)(m_vPos.x - m_vScale.x / 2.f);
	pt[0].y = (int)(m_vPos.y - m_vScale.y / 2.f);
	
	pt[1].x = (int)(m_vPos.x + m_vScale.y / 2.f);
	pt[1].y = (int)(m_vPos.y - m_vScale.y / 2.f);
	
	pt[2].x = (int)(m_vPos.x + m_vScale.y / 2.f);
	pt[2].y = (int)(m_vPos.y + m_vScale.y / 2.f);

	float radian = m_vRotation * PI / 180.f;

	float sin = sinf(radian);
	float cos = cosf(radian);

	for (int i = 0; i < 3; ++i)
	{
		float x = pt[i].x - m_vPos.x;
		float y = pt[i].y - m_vPos.y;

		pt[i].x = (int)(x * cos - y * sin + m_vPos.x);
		pt[i].y = (int)(x * sin + y * cos + m_vPos.y);
	}
	
	PlgBlt(_dc, pt, hMemDC, 0, 0, (int)m_vScale.x, (int)m_vScale.y, NULL, 0, 0);
	
	Component_Render(_dc);
}

void Object::Component_Render(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->Render(_dc);
	}
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);
}

