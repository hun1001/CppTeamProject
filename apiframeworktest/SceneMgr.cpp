#include "pch.h"
#include "SceneMgr.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "EventMgr.h"
SceneMgr::SceneMgr()
	: m_pCurScene(nullptr)
	, m_arrScene{}
{
}

SceneMgr::~SceneMgr()
{
	// ?? ???? ????
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}

void SceneMgr::Init()
{
	// Scene ????
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new Scene_Title;
	m_arrScene[(UINT)SCENE_TYPE::TITLE]->SetName(L"Title Scene");
	m_arrScene[(UINT)SCENE_TYPE::GAME] = new Scene_Game;
	m_arrScene[(UINT)SCENE_TYPE::GAME]->SetName(L"Game Scene");

	// ???? ?? ????
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TITLE];
	m_pCurScene->Enter();
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{ 
	m_pCurScene->Render(_dc);
}
