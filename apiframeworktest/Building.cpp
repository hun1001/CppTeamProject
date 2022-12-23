#include "pch.h"
#include "Building.h"
#include "ResMgr.h"
#include "Image.h"

Building::Building(Vec2 pos, Vec2 scale, int maxHP) : MAX_HP(maxHP), m_iHp(maxHP)
{
	m_vPos = pos;
	m_vScale = scale;
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Building", L"Image\\Building.bmp");
}

Building::~Building()
{
}

void Building::Update()
{
}

void Building::Render(HDC _dc)
{
	TransparentBlt(_dc, m_vPos.x - m_vScale.x / 2.f, m_vPos.y - m_vScale.y / 2.f, m_vScale.x, m_vScale.y, m_pImage->GetDC(), 0, 0, m_pImage->GetWidth(), m_pImage->GetHeight(), RGB(255, 0, 255));
}
