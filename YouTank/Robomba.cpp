#include "stdafx.h"
#include "Robomba.h"
#include "Global.h"

Robomba::Robomba():
	Inimigo(1000, 7),
	barraVida(static_cast<Personagem*>(this), 1000.f, 20.f, 250.f, 25.f)
{
	id = ID_ROBOMBA; //j0g4d0r, 2 pois é rectangle shape
	setSize(300.f, 150.f);
	setTexture("Imagens/dragon.png", 1.f);
	setOriginCenter();
	setPosition(1130.f, 250.f);
}

Robomba::~Robomba()
{
}

const bool Robomba::EmFuria() const
{
	if (vida < vida / 2)
		return true;
	else
		return false;
}

void Robomba::tomarDano(int x)
{
	vida -= x;
}

void Robomba::curaVida(int x)
{
	vida += x;
}

const bool Robomba::getVida() const
{
	return vida;
}

void Robomba::renderRobomba()
{
	barraVida.renderBodyBack();
	barraVida.render();
	render();
}
