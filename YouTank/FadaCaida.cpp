#include "stdafx.h"
#include "FadaCaida.h"
#include "Global.h"

void FadaCaida::initShape()	
{
	setSize(50.f, 50.f);
	setTexture("Imagens/red_fairy.png");
	setOriginCenter();
	setPosition(80.f, 500.f);
}

FadaCaida::FadaCaida():
	Personagem(100,100, ID_JOGADOR),
	barraVida(static_cast<Personagem*>(this), 25.f, 20.f, 210.f, 25.f, 1),
	pOrbe(NULL)
	
{
	rapidez = 25.f;
	alturaPulo = 100.f;
	cooldownAtaqueMax = 30.f;
	direcao.x = 0.0f;
	direcao.y = 0.0f;
	colisaoBot = false;
	cooldownAtaque = 0.f;
	initShape();
}

FadaCaida::~FadaCaida()
{
	if (pOrbe)
		delete pOrbe;
}

void FadaCaida::setOlhaEsquerda(bool x)
{
	olhaEsquerda = x;
}


const bool FadaCaida::olhandoEsquerda() const
{
	return olhaEsquerda;
}

void FadaCaida::setDirecao_x(float dir_x)
{
	direcao.x = dir_x;
}

void FadaCaida::setDirecao_y(float dir_y)
{
	direcao.y = dir_y;
}

void FadaCaida::renderBarraVida()
{
	barraVida.renderBodyBack();
	barraVida.render();
}

const bool FadaCaida::getColisaoBot() const
{
	return colisaoBot;
}

const bool FadaCaida::getExisteNaFase() const
{
	return aparece;
}

void FadaCaida::naColisao()
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

void FadaCaida::updateAnimacao()
{
	//caso esteja andando para direita, o personagem irá virar para a direita
	if (olhaEsquerda == false)
	{
		body.setScale(1.f, 1.f);
	}
	//caso esteja andando para esquerda, o personagem irá virar para a esquerda
	if (olhaEsquerda == true)
	{
		body.setScale(-1.f, 1.f);
	}
}

void FadaCaida::updateTaVivo()
{
	if (vida <= 0)
		aparece = false;
}

void FadaCaida::ataca(float dir_x, float dir_y)
{
	Orbe* pP = new Orbe(dir_x, dir_y, 80.f, getPosition().x, getPosition().y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}

void FadaCaida::update()
{
	updateAnimacao();
	updateTaVivo();
	barraVida.update();
}
