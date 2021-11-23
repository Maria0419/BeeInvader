#include "stdafx.h"
#include "Abelha.h"
#include "Global.h"

Abelha::Abelha(int i):
	Inimigo(1, 1, ID_ABELHA)
{
	initShape();
	if (i == 1)
	{
		int x = rand() % 2;
		if (x)
			setPosition(10.f, static_cast<float>(rand() % 500 + 25));
		else
			setPosition(1200.f, static_cast<float>(rand() % 500 + 25));
	}
	else if(i == 2)
		setPosition(static_cast<float> (rand() % 1100 + 25), static_cast<float>(rand() % 50 + 25));
	
		
	setRapidez(8.f);
	olhaEsquerda = true;
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
	if (direcao.x > 0)
	{
		if(olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = false;
	}
	else if (direcao.x < 0)
	{
		if (!olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = true;
	}

	this->body.move(direcao.x * rapidez, direcao.y * rapidez);
}


void Abelha::initShape()
{
	setSize(30.f, 30.f);
	setTexture("Imagens/bee.png");
	setOriginCenter();
	
}
