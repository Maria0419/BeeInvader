#include "stdafx.h"
#include "Abelha.h"
#include "Global.h"

Abelha::Abelha():
	Inimigo(1, 1)
{
	id = ID_ABELHA; 
	initShape();
	setRapidez(8.f);
	aparece = true;
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

void Abelha::persegue(float x_jogador, float y_jogador)
{
	x_jogador -= getPosition().x;
	y_jogador -= getPosition().y;
	direcao.x = x_jogador / sqrtf(static_cast<float>(pow(x_jogador, 2)) + static_cast<float>(pow(y_jogador, 2)));
	direcao.y = y_jogador / sqrtf(static_cast<float>(pow(x_jogador, 2)) + static_cast<float>(pow(y_jogador, 2)));
	this->body.move(direcao.x * rapidez, direcao.y * rapidez);
}


void Abelha::initShape()
{
	setSize(30.f, 30.f);
	setTexture("Imagens/bee.png");
	setOriginCenter();
	setPosition(static_cast<float> (rand() % 1100+25), static_cast<float>(rand() % 50+25));
}
