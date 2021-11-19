#include "stdafx.h"
#include "AbelhaRainha.h"
#include "Global.h"

AbelhaRainha::AbelhaRainha():
	pFerrao(NULL),
	pJogador(NULL),
	pAbelha(NULL),
	Inimigo(1000, 7),
	barraVida(static_cast<Personagem*>(this), 1000.f, 20.f, 250.f, 25.f)
{
	id = ID_RAINHA; //j0g4d0r, 2 pois é rectangle shape
	setSize(300.f, 400.f);
	setTexture("Imagens/queen_bee.png", 1.f);
	setOriginCenter();
	setPosition(1130.f, 250.f);
	spawnTimerMAX = 200;
	spawnTimer = spawnTimerMAX;
	curaTimerMAX = 20;
	curaTimer = curaTimerMAX;
	ferraoTimerMAX = 500;
	ferraoTimer = ferraoTimerMAX;
	abelhasMAX = 10;
	contaAbelhas = 0;
}

AbelhaRainha::~AbelhaRainha()
{
}

const bool AbelhaRainha::emFuria()
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

void AbelhaRainha::curaVida()
{
	if (emFuria())
	{
		if (curaTimer < curaTimerMAX)
			curaTimer += 5;
		else
		{
			vida += 5;
			curaTimer = 0;
		}
	}
}

void AbelhaRainha::update()
{
	barraVida.update();
	if (emFuria())
	{
		curaVida();
		spawnAbelhas();
	}
	updateAtaque();
}

void AbelhaRainha::renderAbelhaRainha()
{
	barraVida.renderBodyBack();
	barraVida.render();
	render();
}

void AbelhaRainha::setJogadorAlvo(Jogador* pJ)
{
	pJogador = pJ;
}

void AbelhaRainha::updateAtaque()
{
	if (ferraoTimer < ferraoTimerMAX)
		ferraoTimer += 5;
	else
	{
		Ferrao* ferrao = new Ferrao(getPosition().x, getPosition().y,
									pJogador->getPosition().x, pJogador->getPosition().y);
		pLista->incluaEntidade(static_cast<Entidade*>(ferrao));
		ferraoTimer = 0;
	}
}

void AbelhaRainha::spawnAbelhas()
{
	//timer
	if (spawnTimer < spawnTimerMAX)
		spawnTimer += 5;

	else if (contaAbelhas < abelhasMAX)
	{
		Abelha* inim = new Abelha();
		std::cout << "nova abelha" << std::endl;
		pLista->incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		spawnTimer = 0;
	}
}

void AbelhaRainha::morreuAbelha()
{
	contaAbelhas--;
}
