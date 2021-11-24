#include "stdafx.h"
#include "Global.h"
#include "Cogumelo.h"

Cogumelo::Cogumelo():
	Inimigo(100,10, ID_COGUMELO)
{
	pontos = 5;
	setTexture("Imagens/mushroom.png");
	setSize(50.f, 55.f);
	setOriginCenter();
	setPosition(static_cast<float>(rand()%1200), static_cast<float>(rand()%100));
	setVelocidadeX(static_cast<float>(rand() % 3 + 1));
}

Cogumelo::~Cogumelo()
{
}

void Cogumelo::updateAnimacao()
{
	if (velocidade.x > 0)
	{
		if (olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = false;
	}
	else if (velocidade.x < 0)
	{
		if (!olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = true;
	}

}

void Cogumelo::updateCogumelo()
{
	move(velocidade.x, velocidade.y);
	setVelocidadeY(velocidade.y + 1.f);
	updateAnimacao();
}
