#include "stdafx.h"
#include "Abelha.h"
#include "Global.h"

Abelha::Abelha(float dir_x, float dir_y):
	Inimigo(1, 1)
{
	id = ID_ABELHA; 
	initShape();
	rapidez = 5.f;
	aparece = true;
	dir_x -= this->getPosition().x;
	dir_y -= this->getPosition().y;
	direcao.x = dir_x / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
}

Abelha::Abelha()
{
	id = ID_ABELHA; // 1n1m1g0
	initShape();
}

Abelha::~Abelha()
{
}

float Abelha::getDirecao_x()
{
	return direcao.x;
}

float Abelha::getDirecao_y()
{
	return direcao.y;
}

void Abelha::setShowing(bool x)
{
	aparece = x;
}

const bool Abelha::getShowing() const
{
	return aparece;
}


void Abelha::initShape()
{
	setSize(30.f, 30.f);
	setTexture("Imagens/bee.png",1.f);
	setOriginCenter();
	setPosition(static_cast<float> (rand() % 1100+25), static_cast<float>(rand() % 50+25));
}
