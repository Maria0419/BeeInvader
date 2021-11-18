#include "stdafx.h"
#include "Projetil.h"
#include "Global.h"

Projetil::Projetil()
{

}

Projetil::Projetil(float dir_x, float dir_y, float velocidade, float x_jogador, float y_jogador)
{
	id = ID_PROJETIL;
	aparece = true;
	podeMatar = true;
	setTexture("Imagens/orb3.png", 1.f);
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(x_jogador, y_jogador);
	destino.x = dir_x;
	destino.y = dir_y;
	direcao.x = dir_x/sqrtf(static_cast<float>(pow(dir_x,2))+ static_cast<float>(pow(dir_y,2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	rapidez = velocidade;

	float distanciaJogadorDestino;
	distanciaJogadorDestino = (float) (sqrt(pow(y_jogador - destino.y, 2) + pow(destino.x - x_jogador, 2)));
	this->velocidade.x = rapidez * (destino.x - x_jogador)/distanciaJogadorDestino;
	this->velocidade.y = rapidez * (y_jogador - destino.y)/distanciaJogadorDestino;

	if(this->velocidade.y < 0)
		this->velocidade.y *= -1;
}

Projetil::~Projetil()
{
}

void Projetil::renderProjetil()
{
	pGraphic->getWindow()->draw(body);
}

float Projetil::getDirecao_x()
{
	return this->direcao.x;
}

float Projetil::getDirecao_y()
{
	return this->direcao.y;
}

void Projetil::setShowing(bool x)
{
	aparece = x;
}

const bool Projetil::getShowing() const
{
	return aparece;
}

void Projetil::setPodeMatar(bool x)
{
	podeMatar = x;
}

const bool Projetil::getPodeMatar() const
{
	return podeMatar;
}

void Projetil::updateProjetil()
{
	float dt = 0.1f;
	float gravidade = 9.81f;
	move((getPosition().x + velocidade.x * dt) - getPosition().x, (getPosition().y - velocidade.y * dt) - getPosition().y);
	rotate(5.f);
	velocidade.y = velocidade.y - 0.5f * gravidade * dt;
}
