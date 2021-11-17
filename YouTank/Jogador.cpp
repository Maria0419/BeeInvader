#include "stdafx.h"
#include "Jogador.h"

void Jogador::initShape()
{
	id = 402; //j0g4d0r, 2 pois é rectangle shape
	setSize(50.f, 50.f);
	setTexture("Imagens/tank.png", 1.f);
	body.setOrigin(getSize() / 2.0f);
	setPosition(50.f, 50.f);
}

void Jogador::initBarraVida()
{
	barraVida.setSize(sf::Vector2f(200.f, 30.f));
	barraVida.setPosition(1060.f, 20.f);
	barraVidaFundo = barraVida;

	barraVida.setFillColor(sf::Color(240, 10, 10));
	barraVidaFundo.setFillColor(sf::Color(25, 25, 25, 125));

}

Jogador::Jogador():
	Personagem(),
	barraVida(),
	barraVidaFundo()
{
	rapidez = 25.f;
	alturaPulo = 100.f;
	cooldownAtaqueMax = 30.f;
	cooldownAtaque = cooldownAtaqueMax;
	initShape();
	initBarraVida();
}

Jogador::~Jogador()
{

}

void Jogador::setOlhaEsquerda(bool x)
{
	olhaEsquerda = x;
}


const bool Jogador::olhandoEsquerda() const
{
	return olhaEsquerda;
}

void Jogador::updateBarraVida()
{
	
}

void Jogador::renderBarraVida()
{
	pGraphic->drawShapes(barraVida);
	pGraphic->drawShapes(barraVidaFundo);
}

void Jogador::naColisao(sf::Vector2f direcao)
{
	if (direcao.x < 0.0f)
	{
		//colisao na esquerda
		setVelocidadeX(0.0f);
	}
	else if (direcao.x > 0.0f)
	{
		//colisao na direita
		setVelocidadeX(0.0f);
	}
	if (direcao.y > 0.0f)
	{
		//colisao embaixo
		velocidade.y = 0.0f;
		podePular = true;
	}
	else if (direcao.y < 0.0f)
	{
		//colisao em cima
		velocidade.y = 0.0f;
	}
}

void Jogador::updateAnimacao()
{
	if (olhaEsquerda == false)
	{
		body.setScale(1.f, 1.f);
	}
	//caso esteja andando para a esquerda, vira a imagem
	if (olhaEsquerda == true)
	{
		body.setScale(-1.f, 1.f);
	}
}

void Jogador::update()
{
	updateAnimacao();
}
