#include "stdafx.h"
#include "Global.h"
#include "OrbeCura.h"

OrbeCura::OrbeCura(float x_dir, float y_dir, float x_pos, float y_pos):
	Projetil(ID_ORBECURA)
{
	setTexture("Imagens/orb2.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(x_pos, y_pos);
	rapidez = 2.f;
	x_dir -= getPosition().x;
	y_dir -= getPosition().y;
	direcao.x = x_dir / sqrtf(static_cast<float>(pow(x_dir, 2)) + static_cast<float>(pow(y_dir, 2)));
	direcao.y = y_dir / sqrtf(static_cast<float>(pow(x_dir, 2)) + static_cast<float>(pow(y_dir, 2)));
}

OrbeCura::~OrbeCura()
{
}

void OrbeCura::salvar()
{
}

void OrbeCura::updateOrbeCura()
{
	move(direcao.x * rapidez, direcao.y * rapidez);
}
