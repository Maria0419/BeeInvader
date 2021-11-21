#include "stdafx.h"
#include "GameState.h"

void GameState::runFase()
{
	switch (fase)
	{
	case 1:
		jogador1 = new Jogador();
		pInput->setJogador(jogador1);
		fasePrimeira = new FasePrimeira();
		fasePrimeira->setJogador(jogador1);
		fasePrimeira->spawnPlataforma();
	
		if (multiplayer == true)
		{
			fasePrimeira->spawnCurandeira();
			pInput->setCurandeira(fasePrimeira->getCurandeira());
		}
		
		pInput->setFase(static_cast<Fase*>(fasePrimeira));
		
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
}

void GameState::updateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

//Construtora e Destrutora
GameState::GameState(std::stack<State*>* state, InputManager* pIM, short f, bool multip):
	State(state,pIM),
	fasePrimeira(NULL)
{
	multiplayer = multip;
	stateID = GAME_STATE;
	fase = f;
	clock.restart();
	deltaTime = clock.restart().asSeconds();
	runFase();
	
}

GameState::~GameState()
{
	switch (fase)
	{
	case 1:
		delete fasePrimeira;
		delete jogador1;
		break;

	case 2:
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
}

void GameState::setPause(bool p)
{
	pause = p;
}

const short GameState::getState()
{
	return stateID;
}

const bool GameState::getPause() const
{
	return pause;
}

void GameState::endState()
{
	std::cout << "ending game state" << std::endl;
}


void GameState::updatePause()
{
	if (pause == true)
	{
		states->push(new PauseState(states, pInput));
	}
		
}

void GameState::updateInput()
{
	updateDeltaTime();
	pInput->update(deltaTime);
	verificarPause();
}

void GameState::update()
{
	updateInput();
	updatePause();
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
