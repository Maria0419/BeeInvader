#include "stdafx.h"
#include "BarraVida.h"

BarraVida::BarraVida(Personagem* pP, float x, float y, float largura, float altura)
{
	pPersonagem = pP;
	setPosition(x, y);
	setSize(largura, altura);
	setCor(200, 10, 10, 255);
	setBodyBack(x, y, largura, altura);
}

BarraVida::~BarraVida()
{
}

void BarraVida::update()
{
	float vidaPorcento = static_cast<float> (pPersonagem->getVida()) / pPersonagem->getVidaMAX();
	setSize(210.f * vidaPorcento, 25.f);
}


