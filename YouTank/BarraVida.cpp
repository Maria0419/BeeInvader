#include "stdafx.h"
#include "BarraVida.h"
using namespace ElementosVisuais;

BarraVida::BarraVida(Personagem* pP, float x, float y, float largura, float altura, int i)
{
	pPersonagem = pP;
	tamanho = largura;
	setPosition(x, y);
	setSize(largura, altura);
	if (i == 1)
		setCor(255, 60, 60, 255);
	else if (i == 2)
		setCor(60, 200, 200, 255);
	setBodyBack(x, y, largura, altura);
}

BarraVida::~BarraVida()
{
}

void BarraVida::update()
{
	float vidaPorcento = static_cast<float> (pPersonagem->getVida()) / pPersonagem->getVidaMAX();
	setSize(tamanho * vidaPorcento, getSize().y);
}



