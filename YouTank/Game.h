#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "InputManager.h"

#include "MenuState.h"

#include "FadaCaida.h"
#include "Fase.h"


class Game
{
private:
	//Gerenciadores
	GraphicManager *graphicManager;
	EventManager eventManager;
	InputManager inputManager;

	//Fases
	Fase fase;

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
	
	void updateDeltaTime();
	void updatePollEvents();

};

