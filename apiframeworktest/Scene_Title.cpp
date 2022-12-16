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
#include "Button.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::Enter()
{
	Button* startButton = new Button(Vec2(100, 100), Vec2(100, 100), L"Start");
	startButton->SetOnButtonClicked([startButton]() { exit(0); });
	
	AddObject(startButton, GROUP_TYPE::UI);
}

void Scene_Title::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Title::Update()
{  
	Scene::Update();
}

void Scene_Title::Render(HDC _dc)
{
	Scene::Render(_dc);
}
