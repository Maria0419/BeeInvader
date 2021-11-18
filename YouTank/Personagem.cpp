#include "stdafx.h"
#include "Personagem.h"

Personagem::Personagem():
	Entidade(),
	dano(0),
	pontos(0),
	alturaPulo(3.f),
	podePular(false),
	cooldownAtaque(0.f),
	cooldownAtaqueMax(0.f),
	vida(0),
	vidaMAX(0),
	podeAtacar(true)
{

}

Personagem::Personagem(int n_vida, int dmg) :
	Entidade(),
	dano(dmg),
	pontos(0),
	alturaPulo(3.f),
	podePular(false),
	cooldownAtaque(0.f),
	cooldownAtaqueMax(0.f),
	podeAtacar(true)
{
	vidaMAX = n_vida;
	vida = 33;
}

Personagem::~Personagem()
{
}

void Personagem::tomarDano(int dmg)
{
	vida -= dmg;

	if (vida < 0)
		vida = 0;
}

const int Personagem::getVida() const
{
	return vida;
}

const int Personagem::getVidaMAX() const
{
	return vidaMAX;
}

void Personagem::setPodePular(bool pode)
{
	podePular = pode;
}

const bool Personagem::getPodePular() const
{
	return podePular;
}

float Personagem::getAlturaPulo() const
{
	return alturaPulo;
}

const bool Personagem::getPodeAtacar() 
{
	if (cooldownAtaque >= cooldownAtaqueMax)
	{
		cooldownAtaque = 0.f;
		return true;
	}
	return false;

}

void Personagem::updateAtaqueCooldown()
{
	if (cooldownAtaque < cooldownAtaqueMax)
	{
		cooldownAtaque += 1.f;
	}
}
