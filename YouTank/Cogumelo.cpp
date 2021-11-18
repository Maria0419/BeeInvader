#include "stdafx.h"
#include "Cogumelo.h"

Cogumelo::Cogumelo():
	Inimigo(100,10)
{
	id = 32;
	texture.loadFromFile("Imagens/cogumelo.png");
	body.setTexture(&texture);
	setSize(30.f, 30.f);
	setOriginCenter();
	setPosition(600.f, 20.f);
}

Cogumelo::~Cogumelo()
{
}
