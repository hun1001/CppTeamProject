#include "pch.h"
#include "Scene_Title.h"
#include "Object.h"
#include "Turret.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"


Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}
void Scene_Title::Enter()
{
}

void Scene_Title::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Title::Update()
{  
	//Rectangle(Core::GetInst()->GetMainDC(), 0, 0, 800, 600);
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::GAME);
	}
}
