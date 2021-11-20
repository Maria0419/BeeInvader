#include "stdafx.h"
#include "Game.h"

Game::Game() :
	deltaTime(0)
{
	graphicManager = GraphicManager::getInstance();

	setGraphicManager();
	setJogador();

	clock.restart();
	deltaTime = clock.restart().asSeconds();

	initStates();
	run();
}

Game::~Game()
{
	//delete states
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

void Game::initStates()
{
	states.push(new MenuState(&states, &inputManager));
}

void Game::setGraphicManager()
{
	State::setGraphicManager(graphicManager);
	Ente::setGraphicManager(graphicManager);
	inputManager.setGraphicManager(graphicManager);
	eventManager.setGraphicManager(graphicManager);
}

void Game::setJogador()
{
	fase.setJogador(&jogador1);
	inputManager.setJogador(&jogador1);

}

void Game::run()
{
	
	while (graphicManager->isRunning())
	{
		update();
		render();
	}
	
}

void Game::update()
{
	updatePollEvents();
	updateDeltaTime();

	if (!states.empty())
	{
		states.top()->update();
		if (states.top()->getState() == MENU_STATE)
		{
		}

		else if (states.top()->getState() == GAME_STATE)
		{
			inputManager.update(deltaTime);			
		}
		else if (states.top()->getState() == PAUSE_STATE && states.top()->getPause() == false)
		{
			delete states.top();
			states.pop();
			states.top()->setPause(false);
		}

		if (states.top()->getTerminar())
		{
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}
}

void Game::render()
{
	graphicManager->clear();

	if (!states.empty())
	{
		states.top()->render();

		if (states.top()->getState() == GAME_STATE)
		{
			jogador1.renderBarraVida();
			jogador1.render();
		}
	}
				
	graphicManager->display();
}


void Game::updateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

void Game::updatePollEvents()
{
	eventManager.pollEvents();
	
}



