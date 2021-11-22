#include "stdafx.h"
#include "State.h"

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
