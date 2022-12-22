#pragma once
#include "Object.h"

class MissileLauncher : public Object
{
public:
	MissileLauncher();
	virtual ~MissileLauncher();

	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	virtual void EnterCollision(Collider* _pOther) override;

	CLONE(MissileLauncher);
};
