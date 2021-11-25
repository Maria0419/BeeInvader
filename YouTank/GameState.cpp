#include "stdafx.h"
#include "GameState.h"

void GameState::runFase()
{
	jogador1 = new FadaCaida();
	pInput->setFadaCaida(jogador1);

	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira = new FasePrimeira();
		fasePrimeira->setFadaCaida(jogador1);
		fasePrimeira->criarPlataforma();

		if (multiplayer == true)
		{
			criarCurandeira();
			fasePrimeira->setCurandeira(jogador2);
		}
		pInput->setCurandeira(jogador2);
		pInput->setFase(static_cast<Fase*>(fasePrimeira));
		
		break;

	case 2:
		faseSegunda = new FaseSegunda();
		faseSegunda->setFadaCaida(jogador1);
		faseSegunda->criarPlataforma();

		if (multiplayer == true)
		{
			criarCurandeira();
			faseSegunda->setCurandeira(jogador2);
		}
		pInput->setCurandeira(jogador2);
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
	if (deltaTime > 0.017f)
		deltaTime = 0.017f;
}

//Construtora e Destrutora
GameState::GameState(std::stack<State*>* state, InputManager* pIM, short f, bool mp):
	State(state,pIM, GAME_STATE),
	fasePrimeira(NULL),
	faseSegunda(NULL),
	jogador1(NULL),
	jogador2(NULL)
{
	multiplayer = mp;
	fase = f;
	clock.restart();
	deltaTime = clock.restart().asSeconds();
	runFase();
	
}

GameState::~GameState()
{
	delete jogador1;
	jogador1 = NULL;

	if (jogador2)
	{
		delete jogador2;
		jogador2 = NULL;
	}
		

	switch (fase)
	{
	case 12:
	case 1:
		delete fasePrimeira;
		
		break;

	case 2:
		delete faseSegunda;
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

void GameState::setNome(std::string nome)
{
	nomeJ = nome;
}


const short GameState::getState()
{
	return stateID;
}

const bool GameState::getPause() const
{
	return pause;
}

void GameState::criarCurandeira()
{
	jogador2 = new Curandeira();
	
}

void GameState::verificarGameOver()
{
	if (jogador1->getExisteNaFase() == false)
		gameOver = true;

	if (multiplayer == true)
	{
		if (jogador2->getExisteNaFase() == false)
			gameOver = true;
	}
}

void GameState::verificarGameWin()
{
	switch (fase)
	{
	case 12:
		if (fasePrimeira->getTerminou())
		{
			if(multiplayer)
				states->push(new GameWinState(states, pInput, nomeJ, jogador1->getPontos(), true, true));
			else
				states->push(new GameWinState(states, pInput, nomeJ, jogador1->getPontos(), true, false));
		}
			
		break;
	case 1:
		if (fasePrimeira->getTerminou())
			gameWin = true;
		break;

	case 2:
		if (faseSegunda->getTerminou())
			gameWin = true;
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
	
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

void GameState::updateGameWin()
{
	if (gameWin == true)
		states->push(new GameWinState(states, pInput, nomeJ, jogador1->getPontos(), false, false));
}

void GameState::updateInput()
{
	updateDeltaTime();
	pInput->update(deltaTime);
	verificarPause();
}

void GameState::update()
{
	updatePause();
	verificarGameOver();
	verificarGameWin();
	updateGameOver();
	updateGameWin();
	updateInput();
	switch (fase)
	{
	case 12:
	case 1:
		fasePrimeira->update();
		break;

	case 2:
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
	case 12:
	case 1:
		fasePrimeira->renderFasePrimeira();
		break;

	case 2:
		faseSegunda->renderFaseSegunda();
		break;

	default:
		std::cout << "ERROR::GAMESTATE::Fase não existente" << std::endl;
		break;
	}
	
}
