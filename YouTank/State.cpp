#include "stdafx.h"
#include "State.h"

State::State(std::stack<State*>* state, InputManager* pIM, short id) :
	sair(false),
	pause(false),
	gameOver(false),
	gameWin(false),
	goToMenu(false),
	terminarState(false),
	salvarPontos(false),
	salvarFase(false),
	stateID(id),
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

void State::setNome(std::string nome)
{
	nomeJ = nome;
}

void State::setPontos(int i)
{
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

const bool State::getTerminarState() const
{
	return terminarState;
}

const bool State::getSalvarFase() const
{
	return salvarFase;
}

const std::string State::getNome() const
{
	return std::string();
}

void State::verificarPause()
{
	if (pInput->getPause() == true)
		pause = true;	
}

void State::verificarGoToMenu()
{

}

void State::salvar()
{
}

void State::recuperar()
{
}
