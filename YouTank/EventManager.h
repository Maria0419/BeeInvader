#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
#include "State.h"
#include "NomeState.h"

class EventManager
{
private:
	
	GraphicManager *pGraphic;
	sf::Event ev;

public:
	EventManager();
	~EventManager();

	//functions
	void pollEvents(State* pState);

	//modifiers
	void setGraphicManager(GraphicManager *pGM);
};

