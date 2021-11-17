#include "stdafx.h"
#include "Fase.h"

Jogador* Fase::pJogador = NULL;

Fase::Fase():
	pEn(NULL),
	listaEntidades()
{
	
}

Fase::~Fase()
{
	//TO DO: Limpa lISTA
}

void Fase::executar()
{
}

void Fase::gerenciarColisoes()
{

}

void Fase::ataca(float dir_x, float dir_y)
{
	Projetil* pP = new Projetil(pJogador->getPosition().x, pJogador->getPosition().y, dir_x, dir_y, 10.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(pP));
}

void Fase::setJogador(Jogador* pJ)
{
	if (pJ)
		pJogador = pJ;
	
	else
		std::cout << "ERROR::FASE::SETJOGADOR::Ponteiro Jogador Nulo" << std::endl;
	
}
