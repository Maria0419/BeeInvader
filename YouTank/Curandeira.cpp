#include "stdafx.h"
#include "Curandeira.h"
#include "Global.h"

Curandeira::Curandeira():
	pOrbeCura(NULL),
	Personagem(100,100)
{
	id = ID_CURANDEIRA;
	rapidez = 25.f;
	cooldownAtaqueMax = 30.f;
	cooldownAtaque = cooldownAtaqueMax;
	setSize(50.f, 50.f);
	setTexture("Imagens/fada_blue.png", 1.f);
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Curandeira::~Curandeira()
{
}

void Curandeira::cura(float dir_x, float dir_y)
{
	OrbeCura* pP = new OrbeCura(dir_x, dir_y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}
