#include "stdafx.h"
#include "Global.h"
#include "Cogumelo.h"

Cogumelo::Cogumelo():
	Inimigo(100,10)
{
	id = ID_COGUMELO;
	aparece = true;
	setTexture("Imagens/cupido.png", 5.f);
	setSize(300.f, 300.f);
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Cogumelo::~Cogumelo()
{
}
