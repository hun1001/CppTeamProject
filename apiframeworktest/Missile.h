#pragma once
#include "Object.h"
class Image;
class Missile :
    public Object
{
private:
    Vec2    m_vDir;
    Image* m_pImage;
	float  m_fSpeed;
	wstring m_targetTag;
    
public:
    
    void SetDir(Vec2 _vDir) 
    {
        m_vDir = _vDir; 
        m_vDir.Normalize();
    }
    
public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    virtual void BombMissile();
    CLONE(Missile);
public:
    Missile();
	Missile(Vec2 _vPos, Vec2 _vDir);
	Missile(Vec2 _vPos, Vec2 _vDir, float _fSpeed, wstring _targetTag);
    
    ~Missile();
};

