#pragma once
#include "Scene.h"
class Scene_Title :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    
    virtual void Update() override;
	virtual void Render(HDC _dc) override;
public:
    Scene_Title();
    virtual ~Scene_Title();
};

