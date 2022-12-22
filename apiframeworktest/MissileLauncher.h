#pragma once
#include "Object.h"

class MissileLauncher : public Object
{
private:
	vector<class Missile*> m_vMissiles;
	
public:
	MissileLauncher();
	virtual ~MissileLauncher();

	virtual void Update() override;

	CLONE(MissileLauncher);
};
