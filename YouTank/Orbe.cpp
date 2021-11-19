#include "stdafx.h"
#include "Orbe.h"
#include "Global.h"

Orbe::Orbe()
{

}

Orbe::Orbe(float dir_x, float dir_y, float vel, float jog_x, float jog_y)
{
	id = ID_ORBE;
	aparece = true;
	podeMatar = true;
	setTexture("Imagens/orb3.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(jog_x, jog_y);
	destino.x = dir_x;
	destino.y = dir_y;
	direcao.x = dir_x/sqrtf(static_cast<float>(pow(dir_x,2))+ static_cast<float>(pow(dir_y,2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	rapidez = vel;

	float distanciaJogadorDestino;
	distanciaJogadorDestino = (float) (sqrt(pow(jog_y - destino.y, 2) + pow(destino.x - jog_x, 2)));
	velocidade.x = rapidez * (destino.x - jog_x)/distanciaJogadorDestino;
	velocidade.y = rapidez * (jog_y - destino.y)/distanciaJogadorDestino;

	if(velocidade.y < 0)
		velocidade.y *= -1;
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
