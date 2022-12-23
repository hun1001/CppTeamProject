#include "pch.h"
#include "func.h"
#include "EventMgr.h"
#include <random>

void CreateObject(Object* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;
	
	EventMgr::GetInst()->AddEvent(evn);
}

void DeleteObject(Object* _pObj)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	EventMgr::GetInst()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	EventMgr::GetInst()->AddEvent(evn);
}

int GetRandom(int _iMin, int _iMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_iMin, _iMax);

	return dis(gen);
}

float GetRandom(float _fMin, float _fMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(_fMin, _fMax);

	return dis(gen);
}
