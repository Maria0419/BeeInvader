#include "stdafx.h"
#include "EventManager.h"
#include "NomeState.h"
#include "State.h"

EventManager::EventManager():
	ev(),
	pGraphic(NULL)
{
	
}

EventManager::~EventManager()
{
	pGraphic = NULL;
}

void EventManager::pollEvents(State* pState)
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
			if (pState->getState() == NOME_STATE && ev.text.unicode <= 128)
			{
				NomeState* nState = static_cast<NomeState*>(pState);
				char tecla = static_cast<char> (ev.text.unicode);
				if (tecla == '\b')
					nState->retiraLetra(tecla);
				else
					nState->incluaLetra(tecla);
			}
		}
			
		}
		
	}
}

void EventManager::setGraphicManager(GraphicManager *pGM)
{
    pGraphic = pGM;
}



