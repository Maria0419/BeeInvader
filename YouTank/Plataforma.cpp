#include "stdafx.h"
#include "Plataforma.h"
#include "Global.h"


Plataforma::Plataforma(float tam_x, float tam_y, float pos_x, float pos_y):
	Obstaculo(ID_PLATAFORMA)
{
	setSize(tam_x, tam_y);
	setPosition(pos_x, pos_y);
	setTexture("Imagens/grass.png");
	setOriginCenter();
	setOutline(2.f);
	rapidez = 1.f;
	velocidade.y = static_cast<float>(rand()%2 + 1.f);
}

Plataforma::Plataforma():
	Obstaculo(ID_PLATAFORMA)
{
	initShape();
}

Plataforma::~Plataforma()
{
}

void Plataforma::movePlataforma()
{
	move(velocidade.x * rapidez, velocidade.y * rapidez);
}

void Plataforma::salvar()
{
	if (getShowing())
	{
		std::ofstream gravador("./Carregamentos/Plataforma.txt", std::ios::app);
		if (!gravador)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		gravador
			<< getPosition().x << " "
			<< getPosition().y << std::endl;
		gravador.close();
	}
}

void Plataforma::initShape()
{
	setSize(1400.f, 100.f);
	aparece = true;
	setOriginCenter();
	setPosition(700.f, 700.f);
	setTexture("Imagens/grass_main.png");
	setOutline(2.f);
}