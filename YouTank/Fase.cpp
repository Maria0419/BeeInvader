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
	listaEntidades.limpaLista();
}

void Fase::executar()
{
}

void Fase::gerenciarColisoes()
{

}

void Fase::ataca(float dir_x, float dir_y, float x_jogador, float y_jogador)
{
	Projetil* pP = new Projetil(dir_x, dir_y, 80.f, x_jogador, y_jogador);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(pP));
}

void Fase::limpeza()
{
	unsigned counter = 0;
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](counter)->getShowing() == false)
		{
			listaEntidades.destruaEntidade(listaEntidades.operator[](counter));
			counter--;
		}
		counter++;
	}
}

void Fase::update()
{
}


void Fase::setJogador(Jogador* pJ)
{
	if (pJ)
		pJogador = pJ;
	
	else
		std::cout << "ERROR::FASE::SETJOGADOR::Ponteiro Jogador Nulo" << std::endl;
	
}
