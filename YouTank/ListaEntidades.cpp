#include "stdafx.h"
#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():
	listaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::incluaEntidade(Entidade* pE)
{
	if (pE != NULL)
	{
		listaEntidades.incluaInfo(pE);
	}
		
	else
	{
		std::cout << "ERROR::LISTAENTIDADES::INCLUAENTIDADE::Ponteiro nulo!" << std::endl;
	}
}

void ListaEntidades::destruaEntidade(Entidade* pE)
{
	listaEntidades.deletaInfo(pE);

}

void ListaEntidades::limpaLista()
{
	listaEntidades.limpaLista();
}


int ListaEntidades::getTamanho()
{
	return listaEntidades.getTamanho();
}

Entidade* ListaEntidades::operator[](int i)
{
	return listaEntidades.operator[](i);
}

