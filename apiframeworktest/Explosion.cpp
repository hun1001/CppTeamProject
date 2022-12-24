#include "pch.h"
#include "Explosion.h"
#include "Image.h"
#include "ResMgr.h"
Explosion::Explosion(Vec2 pos)
{
	Vec2 vScale = { 5,5 };
	m_pImage = ResMgr::GetInst()->ImgLoad(L"BombImg", L"Image\\explosion_Animation.bmp");
	SetName(L"Explosion");

	SetPos(pos);
	SetScale(vScale);
}
Explosion::~Explosion()
{

}
void Explosion::Update()
{
	Vec2 vPos = GetPos();

	SetPos(vPos);
}
void Explosion::Render(HDC _dc)
{
	Component_Render(_dc);
}