#include "stdafx.h"
#include "State.h"

GraphicManager* State::pGraphic = NULL;

State::State(std::stack<State*>* state, InputManager* pIM):
	terminar(false),
	pause(false),
	stateID(STATE),
	pInput(pIM)
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

void State::setPause(bool p)
{
	pause = p;
}

const bool& State::getTerminar() const
{
	return terminar;
}

const bool State::getPause() const
{
	return pause;
}

void State::verificarPause()
{
	if (pInput->getPause() == true)
		pause = true;	
}

void State::endState()
{
}
