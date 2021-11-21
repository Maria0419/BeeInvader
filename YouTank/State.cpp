#include "stdafx.h"
#include "State.h"

GraphicManager* State::pGraphic = NULL;

State::State(std::stack<State*>* state, InputManager* pIM) :
	sair(false),
	pause(false),
	gameOver(false),
	gameWin(false),
	goToMenu(false),
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

const bool State::getSair() const
{
	return sair;
}

const bool State::getPause() const
{
	return pause;
}

const bool State::getGameOver() const
{
	return gameOver;
}

const bool State::getGameWin() const
{
	return gameWin;
}

const bool State::getGoToMenu() const
{
	return goToMenu;
}

void State::verificarPause()
{
	if (pInput->getPause() == true)
		pause = true;	
}

void State::verificarGoToMenu()
{

}

void State::endState()
{
}
