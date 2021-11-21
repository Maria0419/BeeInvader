#include "stdafx.h"
#include "Plataforma.h"
#include "Global.h"


Plataforma::Plataforma(float tam_x, float tam_y, float pos_x, float pos_y):
	Obstaculo()
{
	id = ID_PLATAFORMA; //pl4t4f0rm4, 2 pois é um Rectangle shape
	aparece = true;
	setSize(tam_x, tam_y);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/grass.png");
	setOriginCenter();
	setOutline(2.f);
	rapidez = 1.f;
	velocidade.y = static_cast<float>(rand()%3 + 1.f);
}

Plataforma::Plataforma():
	Obstaculo()
{
	id = ID_PLATAFORMA; //pl4t4f0rm4, 2 pois é um Rectangle shape
	initShape();
}

Plataforma::~Plataforma()
{
}

void Plataforma::movePlataforma()
{
	move(velocidade.x * rapidez, velocidade.y * rapidez);
}

void Plataforma::initShape()
{
	setSize(1400.f, 100.f);
	aparece = true;
	setOriginCenter();
	setPosition(700.f, 700.f);
	setTexture("Imagens/grass_main.png");
	setOutline(2.f);
}