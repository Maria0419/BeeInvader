#pragma once
#include "stdafx.h"
#include "GraphicManager.h"

class EventManager
{
private:
	
	GraphicManager *pGraphic;
	sf::Event ev;

public:
	EventManager();
	~EventManager();

	//functions
	void pollEvents();
	

	//modifiers
	void setGraphicManager(GraphicManager *pGM);
	//accessors
	

};

