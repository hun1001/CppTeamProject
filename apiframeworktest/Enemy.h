#pragma once
#include "Object.h"

class Missile;

class Enemy :
    public Object
{
private:
	float m_cooltime = 1.f;
    float m_delay = 5.f;
	bool m_bFire = false;

public:
	void SetDelay(float _fDelay) { m_delay = _fDelay; }
	void SetCooltime(float _fCooltime) { m_cooltime = _fCooltime; }
    
	float GetDelay() { return m_delay; }
	float GetCooltime() { return m_cooltime; }
    
public:
    Missile* MissileFire();
	bool GetFire() { return m_bFire; }
   
public:
    virtual void Update() override;
    
    CLONE(Enemy);
public:
    Enemy();
    ~Enemy();
};
