#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
#include "EventManager.h"
#include "InputManager.h"

#include "MenuState.h"

#include "Jogador.h"
#include "Fase.h"


class Game
{
private:
	//Gerenciadores
	GraphicManager *graphicManager;
	EventManager eventManager;
	InputManager inputManager;

	//Menu menu;
	Jogador jogador1;

	//Fases
	Fase fase;

	//aux
	sf::Clock clock;
	float deltaTime;

	std::stack<State*> states;

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

