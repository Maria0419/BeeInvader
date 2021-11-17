#include "stdafx.h"
#include "Personagem.h"

Personagem::Personagem():
	Entidade(),
	num_vidas(0),
	dano(0),
	points(0),
	alturaPulo(3.f),
	podePular(false),
	cooldownAtaque(0.f),
	cooldownAtaqueMax(0.f),
	podeAtacar(true)
{

}

Personagem::Personagem(int n_vida, int dmg, int pontos) :
	Entidade(),
	num_vidas(n_vida),
	dano(dmg),
	points(pontos),
	alturaPulo(3.f),
	podePular(false),
	cooldownAtaque(0.f),
	cooldownAtaqueMax(0.f),
	podeAtacar(true)
{
	
}

Personagem::~Personagem()
{
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
