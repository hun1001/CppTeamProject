#include "pch.h"
#include "Enemy.h"
#include "TimeMgr.h"
#include "Missile.h"
#include "Core.h"
#include "RandomMgr.h"

Missile* Enemy::MissileFire()
{
	m_cooltime = m_delay;
	srand((unsigned int)time(NULL));
	
	Vec2 missilePos = Vec2(Core::GetInst()->GetResolution().x, (long)GetRandom(0, Core::GetInst()->GetResolution().y));
	
	Missile* pMissile = new Missile(missilePos, Vec2(-1.f, 0.f), 3.f, { L"PLAYER_MISSILE", L"Building" }, L"ENEMY_MISSILE");
	
	return pMissile;
}

void Enemy::Update()
{
	m_bFire = m_cooltime <= 0.f;
	m_cooltime -= TimeMgr::GetInst()->GetfDT();
}

Enemy::Enemy() : m_bFire(false), m_cooltime(1.5f), m_delay(2.5f)
{
}

Enemy::~Enemy()
{
}
