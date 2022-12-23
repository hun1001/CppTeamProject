#pragma once
#include "Object.h"

class Image;

class Building : public Object
{
private:
	const int MAX_HP;
	int m_iHp;

	Vec2 m_vPos;
	Vec2 m_vScale;

	Image* m_pImage;
	
public:
	Building(Vec2 pos, Vec2 scale, int maxHP);
	~Building();

	void Update();
	void Render(HDC _dc);
	
	void Damage(int damage) { m_iHp -= damage; }
	const int& GetHp() const { return m_iHp; }

	CLONE(Building);
};
