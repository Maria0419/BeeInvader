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
		switch (ev.Event::type)
		{
		case sf::Event::Closed:
		{
			pGraphic->close();
		}
		break;
		case (sf::Event::TextEntered):
		{
			
		}
			
		}
		
	}
}

void EventManager::setGraphicManager(GraphicManager *pGM)
{
    pGraphic = pGM;
}



