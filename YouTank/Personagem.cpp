#include "stdafx.h"
#include "Personagem.h"

Personagem::Personagem(int hp, int dmg, int i) :
	Entidade(hp, dmg, i),
	pontos(0),
	alturaPulo(3.f),
	podePular(false),
	cooldownAtaque(0.f),
	cooldownAtaqueMax(0.f),
	podeAtacar(true)
{
	aparece = true;
}

Personagem::~Personagem()
{
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
