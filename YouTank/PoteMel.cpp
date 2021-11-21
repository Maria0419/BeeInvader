#include "stdafx.h"
#include "PoteMel.h"
#include "Global.h"

PoteMel::PoteMel()
{
	id = ID_POTEMEL; //pl4t4f0rm4, 2 pois é um Rectangle shape
	aparece = true;
	setSize(40.f, 40.f);
	setPosition(static_cast<float>(rand()%1000 + 100), static_cast<float>(rand()%550 + 50));
	setTexture("Imagens/honeypot.png");
	setOriginCenter();
}

PoteMel::~PoteMel()
{
}
