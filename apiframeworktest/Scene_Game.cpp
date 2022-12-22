#include "pch.h"
#include "Scene_Game.h"
#include "KeyMgr.h"
#include "Missile.h"
#include "Turret.h"
#include "Core.h"

Scene_Game::Scene_Game()
{
}

Scene_Game::~Scene_Game()
{
}

void Scene_Game::Enter()
{
#pragma region Enemy_Missile_Launcher
		
#pragma endregion
	Object* pObj = new Turret;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2,
		Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

}

void Scene_Game::Exit()
{
}

void Scene_Game::Update()
{
	Scene::Update();
}
