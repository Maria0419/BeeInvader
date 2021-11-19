#include "stdafx.h"
#include "Jogador2.h"

Jogador2::Jogador2():
	Personagem(0,0)
{
	id = 5312;
	rapidez = 25.f;
	cooldownAtaqueMax = 30.f;
	cooldownAtaque = cooldownAtaqueMax;
	setSize(20.f, 20.f);
	setTexture("Imagens/cupido.png");
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Jogador2::~Jogador2()
{
}

void Jogador2::setOlhaEsquerda(bool x)
{
	olhaEsquerda = x;
}

const bool Jogador2::olhandoEsquerda() const
{
	return olhaEsquerda;
}

void Jogador2::update()
{
	updateAnimacao();
}

void Jogador2::updateAnimacao()
{
	if (1)
	{
		body.setScale(1.f, 1.f);
	}
	//caso esteja andando para a esquerda, vira a imagem
	else
	{
		body.setScale(-1.f, 1.f);
	}
}