#include "stdafx.h"
#include "InimigoTerrestre.h"

InimigoTerrestre::InimigoTerrestre(float dir_x, float dir_y)
{
	id = 11102; // 1n1m1g0
	initShape();
	rapidez = 5.f;
	dir_x -= this->getPosition().x;
	dir_y -= this->getPosition().y;
	direcao.x = dir_x / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
}

InimigoTerrestre::InimigoTerrestre()
{
	id = 11102; // 1n1m1g0
	initShape();
}

InimigoTerrestre::~InimigoTerrestre()
{
}

float InimigoTerrestre::getDirecao_x()
{
	return direcao.x;
}

float InimigoTerrestre::getDirecao_y()
{
	return direcao.y;
}

void InimigoTerrestre::persegue()
{
	this->body.move(direcao.x * rapidez , direcao.y * rapidez);
}

void InimigoTerrestre::initShape()
{
	setSize(30.f, 30.f);
	texture.loadFromFile("Imagens/droid.png");
	body.setTexture(&texture);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(static_cast<float> (rand() % 700+25), static_cast<float>(rand() % 500+25));
}
