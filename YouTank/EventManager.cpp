#include "stdafx.h"
#include "EventManager.h"

EventManager::EventManager():
	ev(),
	pGraphic(NULL)
{
	
}

EventManager::~EventManager()
{
	pGraphic = NULL;
}

void EventManager::pollEvents()
{
	while (pGraphic->getWindow()->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			pGraphic->close();
	}
}

void EventManager::setGraphicManager(GraphicManager *pGM)
{
    pGraphic = pGM;
}



