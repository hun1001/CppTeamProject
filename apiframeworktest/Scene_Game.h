#pragma once
#include "Scene.h"
class Scene_Game :
    public Scene
{
private:
public:
    Scene_Game();
    virtual ~Scene_Game();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

