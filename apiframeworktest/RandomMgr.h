#pragma once
class RandomMgr
{
public:
	SINGLE(RandomMgr);
	
private:
	RandomMgr();
	~RandomMgr();

public:
	void Init();

public:
	int GetRandom(int _iMin, int _iMax);
	float GetRandom(float _fMin, float _fMax);
};

