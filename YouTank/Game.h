#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "InputManager.h"

#include "MenuState.h"
#include "PauseState.h"

#include "FadaCaida.h"
#include "Fase.h"
using namespace Fases;

class Game
{
private:
	//Gerenciadores
	GraphicManager *pGraphic;
	EventManager eventManager;
	InputManager inputManager;

	std::stack<State*> states;

	bool sair;

	void initStates();
	void setGraphicManager();

public:
	Game();
	~Game();

	//render & update
	void run();

	void render();
	void update();
	
	void updatePollEvents();

};

