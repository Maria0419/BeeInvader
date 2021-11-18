#include "stdafx.h"
#include "Robomba.h"

Robomba::Robomba()
{
	texture.loadFromFile("Imagens/bomberman.png");
	body.setTexture(&texture);
	setSize(220.f,300.f);
	body.setOrigin(body.getSize() / 2.0f);
	setPosition(1150.f, 150.f);
	vida = 1000;
}

Robomba::~Robomba()
{
}

const bool Robomba::EmFuria() const
{
	if (vida < vida / 2)
		return true;
}

void Robomba::tomarDano(int x)
{
	vida -= x;
}

void Robomba::curaVida(float x)
{
	vida += x;
}

const bool Robomba::getVida() const
{
	return vida;
}