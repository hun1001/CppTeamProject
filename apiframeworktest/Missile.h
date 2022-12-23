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
	vector<wstring> m_targetTag;

    bool m_bIsMove;

private:
    void DefualtSetting();
    
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
	Missile(Vec2 _vPos, Vec2 _vDir, float _fSpeed, vector<wstring> _targetTag, wstring _name);
    
    ~Missile();
};

