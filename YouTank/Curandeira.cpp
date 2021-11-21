#include "stdafx.h"
#include "Curandeira.h"
#include "Global.h"

Curandeira::Curandeira():
	pOrbeCura(NULL),
	Personagem(100,0)
{
	cura = 5;
	id = ID_CURANDEIRA;
	rapidez = 15.f;
	olhaEsquerda = false;
	cooldownAtaqueMax = 100.f;
	cooldownAtaque = cooldownAtaqueMax;
	setSize(50.f, 50.f);
	setTexture("Imagens/fada_blue.png", 1.f);
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Curandeira::~Curandeira()
{
}

void Curandeira::setOlhaEsquerda(bool x)
{
	olhaEsquerda = x;
}


const bool Curandeira::olhandoEsquerda() const
{
	return olhaEsquerda;
}

void Curandeira::update()
{
	updateAnimacao();
}

void Curandeira::curar(float dir_x, float dir_y, float pos_x, float pos_y)
{
	OrbeCura* pP = new OrbeCura(dir_x, dir_y, pos_x, pos_y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}

const int Curandeira::getCura() const
{
	return cura;
}

void Curandeira::updateAnimacao()
{
	if (olhaEsquerda == false)
	{
		body.setScale(-1.f, 1.f);
	}
	//caso esteja andando para a esquerda, vira a imagem
	if (olhaEsquerda == true)
	{
		body.setScale(1.f, 1.f);
	}
}