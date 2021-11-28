#pragma once
#include "stdafx.h"
#include "GraphicManager.h"
class NomeEstado;
class Estado;
class EventManager
{
private:
	
	GraphicManager *pGraphic;
	sf::Event ev;

public:
	EventManager();
	~EventManager();

	//functions
	void pollEvents(Estado* pEstado);

	//modifiers
	void setGraphicManager(GraphicManager *pGM);
};

