#include "stdafx.h"
#include "Plataforma.h"
#include "Global.h"


Plataforma::Plataforma(float tam_x, float tam_y, float pos_x, float pos_y):
	Obstaculo(ID_PLATAFORMA, tam_x, tam_y)
{
	setSize(tamX, tamY);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/grass.png");
	setOriginCenter();
	setOutline(2.f);
	rapidez = 1.f;
	velocidade.y = static_cast<float>(rand()%2 + 1.f);
}

Plataforma::Plataforma():
	Obstaculo(ID_PLATAFORMA, 1400.f, 100.f)
{
	initShape();
}

Plataforma::~Plataforma()
{
}

void Plataforma::initShape()
{
	setSize(tamX, tamY);
	aparece = true;
	setOriginCenter();
	setPosition(700.f, 700.f);
	setTexture("Imagens/grass.png");
	setOutline(2.f);
}

void Plataforma::movePlataforma()
{
	move(velocidade.x * rapidez, velocidade.y * rapidez);
}
