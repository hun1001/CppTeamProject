#pragma once
#include "Object.h"
class Image;
class Explosion :
    public Object
{
private:
    
    Image* m_pImage;
  



    CLONE(Explosion);
public:

    void Render(HDC _dc) override;
    void Update() override;
    Explosion(Vec2 pos);
    ~Explosion();



};



