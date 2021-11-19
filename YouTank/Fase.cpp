#include "stdafx.h"
#include "Fase.h"
#include "Global.h"

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
