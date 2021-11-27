#include "stdafx.h"
#include "Espinhos.h"
#include "Global.h"

Espinhos::Espinhos(float pos_x, float pos_y):
	Obstaculo(ID_ESPINHOS, 57.f, 83.f)
{
	setSize(tamX, tamY);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/thorn.png");
	setOriginCenter();
}

Espinhos::~Espinhos()
{
}
