#pragma once
class PlayerMgr
{
private:
	const int MAX_HP;
	int hp;
	
public:
	PlayerMgr(int max_hp);
	~PlayerMgr();

public:
	void GameSetting();

	void AddHP(int _hp);
	const int& GetHP() const;
};

