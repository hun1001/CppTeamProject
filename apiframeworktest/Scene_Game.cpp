#include "pch.h"
#include "Scene_Game.h"
#include "KeyMgr.h"
#include "Object.h"
#include "Turret.h"
#include "Core.h"
#include "MouseMgr.h"
#include "Missile.h"
#include "TimeMgr.h"

Scene_Game::Scene_Game()
{
}

Scene_Game::~Scene_Game()
{
}

void Scene_Game::Enter()
{
	Object* pObj = new Turret;
	pObj->SetPos(Vec2(100l, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);
#pragma region Enemy_Missile_Launcher

#pragma endregion
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

	cooltime -= TimeMgr::GetInst()->GetfDT();
}
