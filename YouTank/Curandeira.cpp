#include "stdafx.h"
#include "Curandeira.h"
#include "Global.h"

Curandeira::Curandeira():
	Personagem(100, 0, ID_CURANDEIRA),
	pOrbeCura(NULL)
{
	cura = 5;
	rapidez = 15.f;
	alturaPulo = 200.f;
	olhaEsquerda = false;
	direcao.x = 0.0f;
	direcao.y = 0.0f;
	colisaoBot = false;
	cooldownAtaqueMax = 100.f;
	cooldownAtaque = cooldownAtaqueMax;
	setSize(50.f, 50.f);
	setTexture("Imagens/fada_blue.png", 1.f);
	setOriginCenter();
	setPosition(500.f, 500.f);
}

Curandeira::~Curandeira()
{
}

void Curandeira::setDirecao_x(float dir_x)
{
	direcao.x = dir_x;
}

void Curandeira::setDirecao_y(float dir_y)
{
	direcao.y = dir_y;
}

void Curandeira::setOlhaEsquerda(bool x)
{
	olhaEsquerda = x;
}


const bool Curandeira::olhandoEsquerda() const
{
	return olhaEsquerda;
}

void Curandeira::update()
{
	updateAnimacao();
}

void Curandeira::naColisao()
{
	if (direcao.x < 0.0f)
	{
		//colisao na esquerda
		setVelocidadeX(0.0f);
		colisaoBot = false;
	}
	else if (direcao.x > 0.0f)
	{
		//colisao na direita
		setVelocidadeX(0.0f);
		colisaoBot = false;
	}
	if (direcao.y > 0.0f)
	{
		//colisao embaixo
		velocidade.y = 0.0f;
		podePular = true;
		colisaoBot = true;
	}
	else if (direcao.y < 0.0f)
	{
		//colisao em cima
		velocidade.y = 0.0f;
		colisaoBot = false;
	}
}

void Curandeira::curar(float dir_x, float dir_y, float pos_x, float pos_y)
{
	OrbeCura* pP = new OrbeCura(dir_x, dir_y, pos_x, pos_y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}

const int Curandeira::getCura() const
{
	return cura;
}

const bool Curandeira::getColisaoBot() const
{
	return colisaoBot;
}

void Curandeira::updateAnimacao()
{
	if (olhaEsquerda == false)
	{
		body.setScale(-1.f, 1.f);
	}
	//caso esteja andando para a esquerda, vira a imagem
	if (olhaEsquerda == true)
	{
		body.setScale(1.f, 1.f);
	}
}