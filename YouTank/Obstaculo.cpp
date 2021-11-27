#include "stdafx.h"
#include "Obstaculo.h"

Obstaculo::Obstaculo(int i, float tam_x, float tam_y):
	Entidade(i),
	tamX(tam_x),
	tamY(tam_y)
{
}

Obstaculo::~Obstaculo()
{
	
}

void Obstaculo::salvar()
{
	if (getShowing())
	{
		std::ofstream gravador("./Carregamentos/Obstaculos.txt", std::ios::app);
		if (!gravador)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		gravador
			<< id << " "
			<< getVelocidadeY() << " "
			<< tamX << " "
			<< tamY << " "
			<< getPosition().x << " "
			<< getPosition().y << std::endl;
		gravador.close();
	}
}
