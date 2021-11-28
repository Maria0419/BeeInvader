#include "stdafx.h"
#include "Orbe.h"
#include "Global.h"

Orbe::Orbe(float dir_x, float dir_y, float jog_x, float jog_y):
	Projetil(ID_ORBE)
{
	podeMatar = true;
	setTexture("Imagens/orb3.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(jog_x, jog_y);
	direcao.x = dir_x/sqrtf(static_cast<float>(pow(dir_x,2))+ static_cast<float>(pow(dir_y,2)));
	direcao.y = dir_y / sqrtf(static_cast<float>(pow(dir_x, 2)) + static_cast<float>(pow(dir_y, 2)));
	rapidez = 80.f;

	float distanciaFadaCaidaDestino;
	distanciaFadaCaidaDestino = (float) (sqrt(pow(jog_y - dir_y, 2) + pow(dir_x - jog_x, 2)));
	velocidade.x = rapidez * (dir_x - jog_x)/distanciaFadaCaidaDestino;
	velocidade.y = rapidez * (jog_y - dir_y)/distanciaFadaCaidaDestino;

}

Orbe::Orbe(float dir_x, float dir_y, float pos_x, float pos_y, float vel_x, float vel_y):
	Projetil(ID_ORBE)
{
	podeMatar = true;
	setTexture("Imagens/orb3.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(pos_x, pos_y);

	direcao.x = dir_x;
	direcao.y = dir_y;

	rapidez = 80.f;

	velocidade.x = vel_x;
	velocidade.y = vel_y;
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
	velocidade.y = velocidade.y - gravidade * dt;
}

void Orbe::salvar()
{
	if (getShowing())
	{
		std::ofstream gravador("./Carregamentos/Orbe.txt", std::ios::app);
		if (!gravador)
		{
			std::cout << "arquivo não pode ser aberto" << std::endl;
			fflush(stdin);
			return;
		}
		gravador
			<< direcao.x << " "
			<< direcao.y << " "
			<< getPosition().x << " "
			<< getPosition().y << " "
			<< velocidade.x << " "
			<< velocidade.y <<	std::endl;
		gravador.close();
	}
}
