#include "stdafx.h"
#include "FavoMel.h"
#include "Global.h"

FavoMel::FavoMel()
{
}

FavoMel::FavoMel(float tam_x, float tam_y, float pos_x, float pos_y):
	Obstaculo()
{
	id = ID_FAVOMEL; 
	aparece = true;
	setSize(tam_x, tam_y);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/grass.png");
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