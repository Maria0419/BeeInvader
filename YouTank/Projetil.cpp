#include "stdafx.h"
#include "Projetil.h"
#include "Global.h"

Projetil::Projetil()
{

}

Projetil::Projetil(float pos_x, float pos_y, float dir_x, float dir_y, float velocidade, float x_jogador, float y_jogador)
{
	id = ID_PROJETIL;
	aparece = true;
	podeMatar = true;
	texture.loadFromFile("Imagens/bola.png");
	body.setTexture(&texture);
	setSize(30.f, 30.f);
	body.setOrigin(body.getSize() / 2.f);
	setPosition(pos_x, pos_y);
	destino.x = dir_x;
	destino.y = dir_y;
	direcao.x = dir_x/sqrtf(static_cast<float>(pow(dir_x,2))+ static_cast<float>(pow(dir_y,2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	posicaoInicial.x = pos_x;
	posicaoInicial.y = pos_y;
	rapidez = velocidade;
	tempo = 0.02f;
	//pedir para o monitor
	//if (x_jogador > destino.x)
	//{
	//	float troca;
	//	troca = x_jogador;
	//	x_jogador = destino.x;
	//	destino.x = troca;
	//	troca = y_jogador;
	//	y_jogador = destino.y;
	//	destino.y = troca;
	//}
	//float angulo = atanf((y_jogador - destino.y)/(destino.x - x_jogador));
	this->velocidade.x = 2*rapidez *cosf(45);
	this->velocidade.y = rapidez * sinf(45);
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
	float gravidade = 10.f;
	if (direcao.x < 0)
	{
		this->move(-((this->getPosition().x + velocidade.x * dt) - this->getPosition().x), (this->getPosition().y - velocidade.y * dt) - this->getPosition().y);
	}
	else
		this->move((this->getPosition().x + velocidade.x * dt)-this->getPosition().x, (this->getPosition().y - velocidade.y * dt) - this->getPosition().y);
	velocidade.y = velocidade.y - 0.5 * gravidade * dt;
}
