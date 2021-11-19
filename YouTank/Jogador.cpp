#include "stdafx.h"
#include "Jogador.h"
#include "Global.h"

void Jogador::initShape()	
{
	id = ID_JOGADOR; //j0g4d0r, 2 pois é rectangle shape
	setSize(50.f, 50.f);
	setTexture("Imagens/red_fairy.png", 1.f);
	setOriginCenter();
	setPosition(150.f, 150.f);
}

void Jogador::initBarraVida()
{
	

}

Jogador::Jogador():
	Personagem(100,100),
	barraVida(static_cast<Personagem*>(this),25.f, 20.f, 210.f, 25.f)
{
	rapidez = 25.f;
	alturaPulo = 100.f;
	cooldownAtaqueMax = 30.f;
	cooldownAtaque = cooldownAtaqueMax;
	initShape();
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

void Jogador::renderBarraVida()
{
	barraVida.renderBodyBack();
	barraVida.render();
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

void Jogador::ataca(float dir_x, float dir_y)
{
	Orbe* pP = new Orbe(dir_x, dir_y, 80.f, getPosition().x, getPosition().y);
	pLista->incluaEntidade(static_cast<Entidade*>(pP));
}

void Jogador::update()
{
	updateAnimacao();
	barraVida.update();
}
