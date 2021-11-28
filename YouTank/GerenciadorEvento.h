#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
class NomeEstado;
class Estado;
class GerenciadorEvento
{
private:
	
	GerenciadorGrafico *pGrafico;
	sf::Event ev;

public:
	GerenciadorEvento();
	~GerenciadorEvento();

	//functions
	void pollEvents(Estado* pEstado);

	//modifiers
	void setGerenciadorGrafico(GerenciadorGrafico *pGG);
};

