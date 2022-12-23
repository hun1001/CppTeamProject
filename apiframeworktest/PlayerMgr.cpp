#include "pch.h"
#include "PlayerMgr.h"

PlayerMgr::PlayerMgr(int max_hp) : MAX_HP(max_hp)
{
	hp = MAX_HP;
}

PlayerMgr::~PlayerMgr()
{
}

void PlayerMgr::GameSetting()
{
	hp = MAX_HP;
}

void PlayerMgr::AddHP(int _hp)
{
	hp += _hp;
}

const int& PlayerMgr::GetHP() const
{
	return hp;
}
