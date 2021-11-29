#include "stdafx.h"
#include "Global.h"
#include "Curandeira.h"
using namespace Jogadores;


Curandeira::Curandeira() :
Jogador(100, 0, ID_CURANDEIRA, 65.f, 2, "./Carregamentos/Curandeira.txt"),
pOrbeCura(NULL)
{
	cura = 5;
	rapidez = 15.f;
	alturaPulo = 200.f;
	colisaoBot = false;
	cooldownAtaqueMax = 100.f;
	cooldownAtaque = cooldownAtaqueMax;
	setSize(50.f, 50.f);
	setTexture("Imagens/fada_blue.png");
	setOriginCenter();
	setPosition(60.f, 500.f);
}

Curandeira::~Curandeira()
{
}



void Curandeira::curar(float dir_x, float dir_y, float pos_x, float pos_y)
{
	OrbeCura* pP = new OrbeCura(dir_x, dir_y, pos_x, pos_y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}

void Jogadores::Curandeira::update()
{
	updateAnimacao();
	updateTaVivo();
	barraVida.update();
}


const int Curandeira::getCura() const
{
	return cura;
}

