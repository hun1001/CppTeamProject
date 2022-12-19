#include "pch.h"
#include "Scene_Title.h"
#include "Object.h"
#include "Turret.h"
#include "Enemy.h"
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
#pragma region StartButton
	Button* startButton = new Button(Vec2(200, 100), Vec2(300, 100), L"Start");
	startButton->SetOnButtonClicked([]() { ChangeScene(SCENE_TYPE::GAME); });
	AddObject(startButton, GROUP_TYPE::UI);
#pragma endregion

#pragma region ExitButton
	Button* exitButton = new Button(Vec2(200, 300), Vec2(300, 100), L"Exit");
	exitButton->SetOnButtonClicked([]() { PostQuitMessage(0); });
	AddObject(exitButton, GROUP_TYPE::UI);
#pragma endregion
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
