#include "stdafx.h"
#include "Global.h"
#include "Cogumelo.h"

Cogumelo::Cogumelo():
	Inimigo(100,10)
{
	id = ID_COGUMELO;
	aparece = true;
	olhaEsquerda = false;
	setTexture("Imagens/mushroom.png");
	setSize(50.f, 55.f);
	setOriginCenter();
	setPosition((float)(rand()%1200), (float)(rand()%100));
	setVelocidadeY(1.f);
	setVelocidadeX(2.f);
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
