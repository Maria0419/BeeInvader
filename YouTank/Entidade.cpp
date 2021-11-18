#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade() :
	Ente(),
	rapidez(100.f)
{
	direcao.x = 1.f;
	direcao.y = 0.f;
}

Entidade::~Entidade()
{
}

void Entidade::executar()
{
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
	this->body.move(dx, dy);
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

void Entidade::updateProjetil()
{
}

void Entidade::naColisao(sf::Vector2f direcao)
{
}


