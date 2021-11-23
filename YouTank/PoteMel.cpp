#include "stdafx.h"
#include "PoteMel.h"
#include "Global.h"

PoteMel::PoteMel():
	Entidade(ID_POTEMEL)
{
	setSize(40.f, 40.f);
	setPosition(static_cast<float>(rand()%1000 + 100), static_cast<float>(rand()%500 + 50));
	setTexture("Imagens/honeypot.png");
	setOriginCenter();
}

PoteMel::~PoteMel()
{
}
