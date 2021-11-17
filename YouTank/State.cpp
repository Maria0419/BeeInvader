#include "stdafx.h"
#include "State.h"

GraphicManager* State::pGraphic = NULL;

State::State(std::stack<State*>* state):
	terminar(false),
	stateID(STATE),
	pInput(NULL)
{
	states = state;
}

State::~State()
{
}

void State::setGraphicManager(GraphicManager* pGM)
{
	if(pGM)
		pGraphic = pGM;

	else
		std::cout << "ERROR::STATE::SETGRAPHICMANAGER::Ponteiro Nulo" << std::endl;
	
}

const bool& State::getTerminar() const
{
	return terminar;
}

void State::verificarFim()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		terminar = true;
}
