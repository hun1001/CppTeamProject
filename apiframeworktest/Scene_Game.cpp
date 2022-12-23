#include "pch.h"
#include "Scene_Game.h"
#include "KeyMgr.h"
#include "Object.h"
#include "Turret.h"
#include "Core.h"
#include "MouseMgr.h"
#include "Missile.h"
#include "Enemy.h"
#include "TimeMgr.h"
#include "Building.h"

Scene_Game::Scene_Game()
{
}

Scene_Game::~Scene_Game()
{
}

void Scene_Game::Enter()
{
#pragma region Building
	Building* pBuilding = new Building({ 100l, Core::GetInst()->GetInst()->GetResolution().y / 2 }, { 500l, Core::GetInst()->GetInst()->GetResolution().y }, 100);
	AddObject(pBuilding, GROUP_TYPE::PLAYER);
#pragma endregion

#pragma region Enemy
	Enemy* pEnemy = new Enemy();
	AddObject(pEnemy, GROUP_TYPE::DEFAULT);
#pragma endregion

	Object* pObj = new Turret;
	pObj->SetPos(Vec2(200l, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);
}

void Scene_Game::Exit()
{
}

void Scene_Game::Update()
{
	Scene::Update();
	static float cooltime = 1.f;
	if (MouseMgr::GetInst()->GetMouseLBtnDown() && cooltime <= 0.f)
	{		
		
		Vec2 targetPos = MouseMgr::GetInst()->GetMousePos();
		Vec2 turretPos = GetGroupObject(GROUP_TYPE::PLAYER)[0]->GetPos();
		
		Vec2 dir = targetPos - turretPos;

		Missile* pMissile = new Missile(turretPos, dir, 1.f, L"ENEMY_MISSILE");

		AddObject(pMissile, GROUP_TYPE::MISSILE_PLAYER);
		cooltime = 1.f;
	}

	Enemy* pEnemy = (Enemy*)GetGroupObject(GROUP_TYPE::DEFAULT)[0];

	if (pEnemy->GetFire())
	{
		AddObject(pEnemy->MissileFire(), GROUP_TYPE::MISSILE_ENEMY);
	}

	cooltime -= TimeMgr::GetInst()->GetfDT();
}
