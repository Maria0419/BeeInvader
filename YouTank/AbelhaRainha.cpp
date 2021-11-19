#include "stdafx.h"
#include "AbelhaRainha.h"
#include "Global.h"

AbelhaRainha::AbelhaRainha():
	Inimigo(1000, 7),
	barraVida(static_cast<Personagem*>(this), 1000.f, 20.f, 250.f, 25.f)
{
	id = ID_RAINHA; //j0g4d0r, 2 pois é rectangle shape
	setSize(300.f, 400.f);
	setTexture("Imagens/queen_bee.png", 1.f);
	setOriginCenter();
	setPosition(1130.f, 250.f);
	curaTimerMAX = 20.f;
	curaTimer = curaTimerMAX;
}

AbelhaRainha::~AbelhaRainha()
{
}

const bool AbelhaRainha::EmFuria()
{
	if (vida < float(vidaMAX) / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
		
}

void AbelhaRainha::curaVida(int x)
{
	if (EmFuria())
	{
		if (curaTimer < curaTimerMAX)
			curaTimer += 1.f;
		else
		{
			vida += x;
			curaTimer = 0.f;
		}
	}
}

void AbelhaRainha::update()
{
	barraVida.update();
}

void AbelhaRainha::renderAbelhaRainha()
{
	barraVida.renderBodyBack();
	barraVida.render();
	render();
}
