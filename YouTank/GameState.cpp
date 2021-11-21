#include "stdafx.h"
#include "GameState.h"

void GameState::runFase()
{
	switch (fase)
	{
	case 1:
		jogador1 = new FadaCaida();
		pInput->setFadaCaida(jogador1);

		fasePrimeira = new FasePrimeira();
		fasePrimeira->setFadaCaida(jogador1);
		fasePrimeira->spawnPlataforma();
		
		pInput->setFase(static_cast<Fase*>(fasePrimeira));
		
		break;

	case 2:
		jogador1 = new FadaCaida();
		pInput->setFadaCaida(jogador1);
		faseSegunda = new FaseSegunda();
		faseSegunda->setFadaCaida(jogador1);
		faseSegunda->spawnPlataforma();
		pInput->setFase(static_cast<Fase*>(faseSegunda));
		break;

	case 12:
		jogador1 = new FadaCaida();
		pInput->setFadaCaida(jogador1);
		faseSegunda = new FaseSegunda();
		faseSegunda->setFadaCaida(jogador1);
		faseSegunda->spawnPlataforma();

		if (multiplayer == true)
		{
			faseSegunda->spawnCurandeira();
			pInput->setCurandeira(faseSegunda->getCurandeira());
		}

		pInput->setFase(static_cast<Fase*>(faseSegunda));
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
	fasePrimeira(NULL),
	faseSegunda(NULL)
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
		delete faseSegunda;
		delete jogador1;
		break;
	case 12:
		delete faseSegunda;
		delete jogador1;
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

void GameState::verificarGameOver()
{
	if (jogador1->getExisteNaFase() == false)
		gameOver = true;
	
}


void GameState::updatePause()
{
	if (pause == true)
	{
		states->push(new PauseState(states, pInput));
	}
		
}

void GameState::updateGameOver()
{
	if (gameOver == true)
		states->push(new GameOverState(states, pInput));
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
	verificarGameOver();
	updateGameOver();
	switch (fase)
	{
	case 1:
		fasePrimeira->update();
		break;

	case 2:
		faseSegunda->update();
		break;

	case 12:
		faseSegunda->update();
		break;
	default:
		std::cout << "ERROR::GAMESTATE::UPDATE::Fase não existente" << std::endl;
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
		faseSegunda->renderFaseSegunda();
		break;

	case 12:
		faseSegunda->renderFaseSegunda();
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
	
}
