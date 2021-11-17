#include "stdafx.h"
#include "Plataforma.h"



Plataforma::Plataforma(float tam_x, float tam_y, float pos_x, float pos_y, float angulo):
	Obstaculo()
{
	id = 44042; //pl4t4f0rm4, 2 pois é um Rectangle shape
	setSize(tam_x, tam_y);
	setPosition(pos_x, pos_y);
	setCor(124, 124, 124, 200);
	body.setOrigin(body.getSize() / 2.0f);
	body.rotate(angulo);
}

Plataforma::Plataforma():
	Obstaculo()
{
	id = 44042; //pl4t4f0rm4, 2 pois é um Rectangle shape
	initShape();
}

Plataforma::~Plataforma()
{
}

void Plataforma::initShape()
{
	setSize(1400.f, 50.f);
	setPosition(700.f, 600.f);
	setCor(124,124,124,200);
	body.setOrigin(body.getSize() /2.0f);
}