#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "GerenciadorComando.h"

#include "MenuEstado.h"
#include "PauseEstado.h"


class Jogo
{
private:
	//Gerenciadores
	GraphicManager *pGraphic;
	EventManager eventManager;
	GerenciadorComando inputManager;

	std::stack<Estado*> estados;

	bool sair;

	void initEstados();
	void setGraphicManager();

public:
	Jogo();
	~Jogo();

	//render & update
	void run();

	void render();
	void update();
	
	void updatePollEvents();

};

