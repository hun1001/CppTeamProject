#pragma once
#include "Object.h"

class Image;
class Turret :
    public Object
{
private:
    Image* m_pImage;

public:
    Turret();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Turret();

//    Player* Clone{ return new Player(*this); }
    CLONE(Turret);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

