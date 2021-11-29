#include "stdafx.h"
#include "Orbe.h"
#include "Global.h"

Orbe::Orbe(float dir_x, float dir_y, float jog_x, float jog_y):
	Projetil(ID_ORBE)
{

	setTexture("Imagens/orb3.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	setPosition(jog_x, jog_y);
	rapidez = 80.f;

	float distanciaFadaCaidaDestino;
	distanciaFadaCaidaDestino = (float) (sqrt(pow(jog_y - dir_y, 2) + pow(dir_x - jog_x, 2))); //hipotenusa
	velocidade.x = rapidez * (dir_x - jog_x)/distanciaFadaCaidaDestino; //cateto
	velocidade.y = rapidez * (jog_y - dir_y)/distanciaFadaCaidaDestino; //cateto

}

Orbe::Orbe():
	Projetil(ID_ORBE)
{
	setTexture("Imagens/orb3.png");
	setSize(20.f, 18.f);
	setOriginCenter();
	rapidez = 80.f;
}

Orbe::~Orbe()
{
}

void Orbe::renderOrbe()
{
	render();
}

void Orbe::update()
{
	/*Aplica o efeito da gravidade*/
	float dt = 0.1f;
	float gravidade = 9.81f;
	move((getPosition().x + velocidade.x * dt) - getPosition().x, (getPosition().y - velocidade.y * dt) - getPosition().y);
	rotate(5.f);
	velocidade.y = velocidade.y - gravidade * dt;
}

void Orbe::salvar()
{
	/*Salva as informações pertinentes*/
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
			<< getPosition().x << " "
			<< getPosition().y << " "
			<< velocidade.x << " "
			<< velocidade.y <<	std::endl;
		gravador.close();
	}
}
