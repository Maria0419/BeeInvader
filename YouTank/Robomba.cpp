#include "stdafx.h"
#include "Robomba.h"

Robomba::Robomba()
{
	texture.loadFromFile("Imagens/bomberman.png");
	body.setTexture(&texture);
	setSize(220.f,300.f);
	body.setOrigin(body.getSize() / 2.0f);
	setPosition(1150.f, 150.f);
}

Robomba::~Robomba()
{
}
