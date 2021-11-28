#include "stdafx.h"
#include "EventManager.h"
#include "NomeEstado.h"
#include "Estado.h"

EventManager::EventManager():
	ev(),
	pGraphic(NULL)
{
	
}

EventManager::~EventManager()
{
	pGraphic = NULL;
}

void EventManager::pollEvents(Estado* pEstado)
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
			if (pEstado->getEstado() == NOME_STATE && ev.text.unicode <= 128)
			{
				NomeEstado* nEstado = static_cast<NomeEstado*>(pEstado);
				char tecla = static_cast<char> (ev.text.unicode);
				if (tecla == '\b')
					nEstado->retiraLetra(tecla);
				else if(tecla != ' ')
					nEstado->incluaLetra(tecla);
			}
		}
			
		}
		
	}
}

void EventManager::setGraphicManager(GraphicManager *pGM)
{
    pGraphic = pGM;
}



