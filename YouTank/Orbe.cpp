#include "stdafx.h"
#include "Orbe.h"
#include "Global.h"

Orbe::Orbe()
{

}

Orbe::Orbe(float dir_x, float dir_y, float velocidade, float x_jogador, float y_jogador)
{
	id = ID_ORBE;
	aparece = true;
	podeMatar = true;
	setTexture("Imagens/orb3.png");
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

Orbe::~Orbe()
{
}

void Orbe::renderOrbe()
{
	pGraphic->getWindow()->draw(body);
}

void Orbe::updateOrbe()
{
	float dt = 0.1f;
	float gravidade = 9.81f;
	move((getPosition().x + velocidade.x * dt) - getPosition().x, (getPosition().y - velocidade.y * dt) - getPosition().y);
	rotate(5.f);
	velocidade.y = velocidade.y - 0.5f * gravidade * dt;
}
