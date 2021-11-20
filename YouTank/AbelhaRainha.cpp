#include "stdafx.h"
#include "AbelhaRainha.h"
#include "Global.h"

void AbelhaRainha::initTimers()
{
	spawnTimerMAX = 200;
	spawnTimer = spawnTimerMAX;
	curaTimerMAX = 20;
	curaTimer = curaTimerMAX;
	ferraoTimerMAX = 500;
	ferraoTimer = 0;
}

void AbelhaRainha::initShape()
{
	setSize(300.f, 400.f);
	setTexture("Imagens/queen_bee.png");
	setOriginCenter();
	setPosition(1130.f, 250.f);
}

AbelhaRainha::AbelhaRainha():
	pFerrao(NULL),
	pJogador(NULL),
	pAbelha(NULL),
	Inimigo(1000, 7),
	barraVida(static_cast<Personagem*>(this), 1000.f, 20.f, 250.f, 25.f)
{
	id = ID_RAINHA; //j0g4d0r, 2 pois é rectangle shape
	initShape();
	initTimers();
	anguloMAX =(float) (2*3.1415);
	angulo = anguloMAX;
	abelhasMAX = 10;
	contaAbelhas = 0;
	x = getPosition().x - 50.f;
	y = getPosition().y;
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
			curaTimer += 1;
		else
		{
			vida += 1;
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
	else
		updateMovimento();
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

void AbelhaRainha::updateMovimento()
{
	float moveX, moveY;
	if (angulo > anguloMAX)
	{
		angulo = 0;
	}
	else
		angulo += 0.01f;
	moveX = x + cosf(angulo) * 50.f;
	moveY = y + sinf(angulo) * 50.f;
	setPosition(moveX, moveY);
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
		std::cout << contaAbelhas << std::endl;
		pLista->incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		spawnTimer = 0;
	}
}

void AbelhaRainha::morreuAbelha()
{
	contaAbelhas--;
}
