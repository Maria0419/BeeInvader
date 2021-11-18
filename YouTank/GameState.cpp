#include "stdafx.h"
#include "GameState.h"

//Construtora e Destrutora
GameState::GameState(std::stack<State*>* state, InputManager* pIM, short f):
	State(state),
	fasePrimeira(NULL)
{
	pInput = pIM;
	stateID = GAME_STATE;
	fase = f;

	switch (fase)
	{
	case 1:
		fasePrimeira = new FasePrimeira();
		fasePrimeira->spawnPlataforma();
		pInput->setFase(static_cast<Fase*>(fasePrimeira));
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
}

GameState::~GameState()
{
	switch (fase)
	{
	case 1:
		delete fasePrimeira;
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
}

const short GameState::getState()
{
	return stateID;
}

void GameState::endState()
{
	std::cout << "ending game state" << std::endl;
}


void GameState::updateInput(const float& dt)
{
	verificarFim();
}

void GameState::update(const float& dt)
{
	updateInput(dt);
	switch (fase)
	{
	case 1:
		fasePrimeira->update();
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
	
}

void GameState::render()
{
	switch (fase)
	{
	case 1:
		fasePrimeira->renderFasePrimeira();
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
	
}
