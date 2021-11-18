#include "stdafx.h"
#include "Dragao.h"
#include "Global.h"

Dragao::Dragao():
	Inimigo(1000, 7),
	barraVida(static_cast<Personagem*>(this), 1000.f, 20.f, 250.f, 25.f)
{
	id = ID_ROBOMBA; //j0g4d0r, 2 pois é rectangle shape
	setSize(300.f, 150.f);
	setTexture("Imagens/dragon.png", 1.f);
	setOriginCenter();
	setPosition(1130.f, 250.f);
}

Dragao::~Dragao()
{
}

const bool Dragao::EmFuria() const
{
	if (vida < vida / 2)
		return true;
	else
		return false;
}

void Dragao::tomarDano(int x)
{
	vida -= x;
}

void Dragao::curaVida(int x)
{
	vida += x;
}

const bool Dragao::getVida() const
{
	return vida;
}

void Dragao::renderDragao()
{
	barraVida.renderBodyBack();
	barraVida.render();
	render();
}
