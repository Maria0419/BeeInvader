#include "stdafx.h"
#include "Global.h"
#include "Cogumelo.h"
using namespace Inimigos;

Cogumelo::Cogumelo():
	Inimigo(100,10, ID_COGUMELO, 3)
{
	setTexture("Imagens/mushroom.png");
	setSize(50.f, 55.f);
	setOriginCenter();
	setPosition(static_cast<float>(rand()%1000 + 200), static_cast<float>(rand()%100));
	setVelocidadeX(static_cast<float>(rand() % 3 + 1));
}

Cogumelo::Cogumelo(float velX, float posX, float posY):
	Inimigo(100, 10, ID_COGUMELO, 3)
{
	setTexture("Imagens/mushroom.png");
	setSize(50.f, 55.f);
	setOriginCenter();
	setPosition(posX, posY);
	setVelocidadeX(velX);
}

Cogumelo::~Cogumelo()
{
}

void Cogumelo::updateAnimacao()
{
	if (velocidade.x > 0)
	{
		if (olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = false;
	}
	else if (velocidade.x < 0)
	{
		if (!olhaEsquerda)
			body.setScale(-1.f * body.getScale().x, body.getScale().y);
		olhaEsquerda = true;
	}

}

void Cogumelo::updateCogumelo()
{
	move(velocidade.x, velocidade.y);
	setVelocidadeY(velocidade.y + 1.f);
	updateAnimacao();
}

void Cogumelo::salvar()
{
	if (getShowing())
	{
		std::ofstream gravador("./Carregamentos/Cogumelo.txt", std::ios::app);
		if (!gravador)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		gravador << getVelocidadeX() << " "
			<< getPosition().x << " "
			<< getPosition().y << std::endl;
		gravador.close();
	}
}
