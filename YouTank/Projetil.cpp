#include "stdafx.h"
#include "Projetil.h"

Projetil::Projetil(int i):
	Entidade(i)
{
}

Projetil::~Projetil()
{
}

float Projetil::getDirecao_x()
{
	return direcao.x;
}

float Projetil::getDirecao_y()
{
	return direcao.y;
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