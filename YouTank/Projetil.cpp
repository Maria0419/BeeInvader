#include "stdafx.h"
#include "Projetil.h"

Projetil::Projetil()
{

}

Projetil::Projetil(float pos_x, float pos_y, float dir_x, float dir_y, float velocidade)
{
	id = 312;
	aparece = true;
	podeMatar = true;
	texture.loadFromFile("Imagens/bola.png");
	body.setTexture(&texture);
	setSize(30.f, 30.f);
	body.setOrigin(body.getSize() / 2.f);
	setPosition(pos_x, pos_y);
	direcao.x = dir_x/sqrtf(static_cast<float>(pow(dir_x,2))+ static_cast<float>(pow(dir_y,2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	rapidez = velocidade;
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
