#include "stdafx.h"
#include "InimigoTerrestre.h"

InimigoTerrestre::InimigoTerrestre()
{
	initShape();
	id = 11102; // 1n1m1g0
}

InimigoTerrestre::~InimigoTerrestre()
{
}

void InimigoTerrestre::initShape()
{
	setSize(25.f, 25.f);
	setCor(rand() % 128 + 40, rand() % 128 + 40, rand() % 128 + 40, 255);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(static_cast<float> (rand() % 700+25), static_cast<float>(rand() % 500+25));

}
