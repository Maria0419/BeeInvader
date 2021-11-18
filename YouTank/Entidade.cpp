#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(int hp, int dmg) :
	Ente(),
	rapidez(100.f),
	dano(dmg),
	vida(hp),
	podeMatar(true)
{
	vidaMAX = hp;
	vida = vidaMAX;
	direcao.x = 1.f;
	direcao.y = 0.f;
}

Entidade::Entidade():
	Ente(),
	rapidez(100.f),
	dano(0),
	vida(0),
	vidaMAX(0),
	podeMatar(true)
{
}

Entidade::~Entidade()
{
}

void Entidade::executar()
{
}

void Entidade::tomarDano(int dmg)
{
	vida -= dmg;

	if (vida < 0)
		vida = 0;
}

const int Entidade::getDano() const
{
	return dano;
}

void Entidade::setRapidez(float rapidez)
{
	rapidez = rapidez;
}

float Entidade::getRapidez() const
{
	return rapidez;
}

void Entidade::setVelocidadeX(float x)
{
	velocidade.x = x;
}

void Entidade::setVelocidadeY(float y)
{
	velocidade.y = y;
}

float Entidade::getVelocidadeX()
{
	return velocidade.x;
}

float Entidade::getVelocidadeY() 
{
	return velocidade.y;
}

void Entidade::move(float dx, float dy)
{
	body.move(dx, dy);
}

float Entidade::getDirecao_x()
{
	return 0.0f;
}

float Entidade::getDirecao_y()
{
	return 0.0f;
}

void Entidade::setPodeMatar(bool x)
{
	podeMatar = x;
}

const bool Entidade::getPodeMatar() const
{
	return false;
}

void Entidade::persegue()
{
}

void Entidade::updateOrbe()
{
}

void Entidade::naColisao(sf::Vector2f direcao)
{
}


