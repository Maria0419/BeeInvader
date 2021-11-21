#include "stdafx.h"
#include "Fase.h"
#include "Global.h"

Fase::Fase():
	pEn(NULL),
	pFadaCaida(NULL),
	pCurandeira(NULL),
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
			Entidade* pAux = listaEntidades.operator[](counter);
			listaEntidades.destruaEntidade(pAux);
			delete pAux;
			counter--;
		}
		counter++;
	}
}

void Fase::update()
{
}
