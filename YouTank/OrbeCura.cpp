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
	dirX = x_dir;
	dirY = y_dir;
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
	if (getShowing())
	{
		std::ofstream gravador("./Carregamentos/OrbeCura.txt", std::ios::app);
		if (!gravador)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		gravador
			<< dirX << " "
			<< dirY << " "
			<< getPosition().x << " "
			<< getPosition().y << std::endl;
		gravador.close();
	}
}

void OrbeCura::updateOrbeCura()
{
	move(direcao.x * rapidez, direcao.y * rapidez);
}
