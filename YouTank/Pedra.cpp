#include "stdafx.h"
#include "Pedra.h"
#include "Global.h"

Pedra::Pedra(float pos_x, float pos_y):
	Obstaculo(ID_PEDRA, 40.f, 40.f)
{
	setSize(tamX, tamY);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/stone.png");
	setOriginCenter();
}

Pedra::~Pedra()
{
}
