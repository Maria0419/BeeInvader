#include "stdafx.h"
#include "FavoMel.h"
#include "Global.h"

FavoMel::FavoMel(float pos_x, float pos_y):
	Obstaculo(ID_FAVOMEL, 100.f, 20.f)
{
	setSize(tamX, tamY);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/favo.png");
	setOriginCenter();
	setOutline(2.f);
	rapidez = 1.f;
	velocidade.y = static_cast<float>(rand() % 2 + 1.f);

}

FavoMel::~FavoMel()
{
}

void FavoMel::movePlataforma()
{
	move(velocidade.x * rapidez, velocidade.y * rapidez);
}