#include "stdafx.h"
#include "Plataforma.h"
#include "Global.h"


Plataforma::Plataforma(float tam_x, float tam_y, float pos_x, float pos_y, float angulo):
	Obstaculo()
{
	id = ID_PLATAFORMA; //pl4t4f0rm4, 2 pois é um Rectangle shape
	aparece = true;
	setSize(tam_x, tam_y);
	setPosition(pos_x, pos_y);
	setCor(124, 124, 124, 200);
	setOriginCenter();
	rotate(angulo);
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
	setSize(1400.f, 100.f);
	aparece = true;
	body.setOrigin(body.getSize() / 2.0f);
	setPosition(700.f, 700.f);
	setCor(124,124,124,200);
	
}


void Plataforma::setShowing(bool x)
{
	aparece = x;
}

const bool Plataforma::getShowing() const
{
	return aparece;
}