#include "pch.h"
#include "RandomMgr.h"
#include <random>

RandomMgr::~RandomMgr()
{
}

void RandomMgr::Init()
{
	
}

int RandomMgr::GetRandom(int _iMin, int _iMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_iMin, _iMax);

	return dis(gen);
}

float RandomMgr::GetRandom(float _fMin, float _fMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(_fMin, _fMax);

	return dis(gen);
}
