#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntidades
{
private:
	Lista <Entidade> listaEntidades;

public:
	ListaEntidades();
	~ListaEntidades();
	void incluaEntidade(Entidade* pE);
	void destruaEntidade(Entidade* pE);
	void limpaLista();
	int getTamanho();

	Entidade* operator[](int i);
};

