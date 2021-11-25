#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(int hp, int dmg, int i) :
	Ente(i),
	rapidez(1.f),
	dano(dmg),
	vida(hp),
	pontos(0),
	podeMatar(true),
	olhaEsquerda(false)
{
	aparece = true;
	vidaMAX = hp;
	vida = vidaMAX;
	direcao.x = 1.f;
	direcao.y = 0.f;
}

Entidade::Entidade(int i):
	Ente(i),
	rapidez(5.f),
	dano(0),
	pontos(0),
	vida(0),
	vidaMAX(0),
	podeMatar(true),
	olhaEsquerda(false)
{
	aparece = true;
}

Entidade::~Entidade()
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

void Entidade::receberCura(int cura)
{
	if (vida + cura > vidaMAX)
		vida = vidaMAX;
	else
		vida += cura;
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

const bool Entidade::getShowing() const
{
	return aparece;
}

void Entidade::setDirecao_x(float dir_x)
{
}

void Entidade::setDirecao_y(float dir_y)
{
}

float Entidade::getDirecao_x()
{
	return direcao.x;
}

float Entidade::getDirecao_y()
{
	return direcao.y;
}

void Entidade::setPodeMatar(bool x)
{
	podeMatar = x;
}

const bool Entidade::getPodeMatar() const
{
	return podeMatar;
}

const int Entidade::getPontos() const
{
	return pontos;
}

void Entidade::persegue(float x_jogador, float y_jogador)
{
}

void Entidade::updateOrbe()
{
}

void Entidade::updateOrbeCura()
{
}

void Entidade::updateFerrao()
{
}

void Entidade::updateAnimacao()
{
}

void Entidade::updateCogumelo()
{
}

void Entidade::movePlataforma()
{
}

void Entidade::naColisao()
{
}

void Entidade::operator+=(int i)
{
}


