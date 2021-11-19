#include "stdafx.h"
#include "Global.h"
#include "Cogumelo.h"

Cogumelo::Cogumelo():
	Inimigo(100,10)
{
	id = ID_COGUMELO;
	setTexture("Imagens/fungi.png", 5.f);
	setSize(100.f, 120.f);
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Cogumelo::~Cogumelo()
{
}
