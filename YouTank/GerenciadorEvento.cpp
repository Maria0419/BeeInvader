#include "stdafx.h"
#include "GerenciadorEvento.h"
#include "NomeEstado.h"
#include "Estado.h"

GerenciadorEvento::GerenciadorEvento():
	ev(),
	pGrafico(NULL)
{
	
}

GerenciadorEvento::~GerenciadorEvento()
{
	pGrafico = NULL;
}

void GerenciadorEvento::pollEvents(Estado* pEstado)
{
	while (pGrafico->getWindow()->pollEvent(ev))
	{
		switch (ev.Event::type)
		{
		case sf::Event::Closed:
		{
			pGrafico->close();
		}
		break;
		case (sf::Event::TextEntered):
		{
			if (pEstado->getEstado() == NOME_ESTADO && ev.text.unicode <= 128)
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

void GerenciadorEvento::setGerenciadorGrafico(GerenciadorGrafico *pGG)
{
    pGrafico = pGG;
}



