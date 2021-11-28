#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorComando.h"

#include "MenuEstado.h"
#include "PauseEstado.h"


class Jogo
{
private:
	//Gerenciadores
	GerenciadorGrafico *pGrafico;
	GerenciadorEvento gerenciadorEvento;
	GerenciadorComando gerenciadorComando;

	std::stack<Estado*> estados;

	bool sair;

	void initEstados();
	void setGerenciadorGrafico();

public:
	Jogo();
	~Jogo();

	//render & update
	void executar();

	void render();
	void update();
	
	void updatePollEvents();

};

