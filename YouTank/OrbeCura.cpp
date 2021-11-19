#include "stdafx.h"
#include "Global.h"
#include "OrbeCura.h"

OrbeCura::OrbeCura()
{
}

OrbeCura::OrbeCura(float x_jogador, float y_jogador)
{
	id = ID_ORBECURA;
	rapidez = 2.f;
	x_jogador -= getPosition().x;
	y_jogador -= getPosition().y;
	direcao.x = x_jogador / sqrtf(static_cast<float>(pow(x_jogador, 2)) + static_cast<float>(pow(y_jogador, 2)));
	direcao.y = y_jogador / sqrtf(static_cast<float>(pow(x_jogador, 2)) + static_cast<float>(pow(y_jogador, 2)));
}

OrbeCura::~OrbeCura()
{
}

void OrbeCura::updateOrbeCura()
{
	move(direcao.x * rapidez, direcao.y * rapidez);
}
