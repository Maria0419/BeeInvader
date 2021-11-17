#include "stdafx.h"
#include "Game.h"

Game::Game() :
	graphicManager(),
	deltaTime(0)
{
	inputManager.setGraphicManager(&graphicManager);
	State::setGraphicManager(&graphicManager);
	Ente::setGraphicManager(&graphicManager);
	fase.setJogador(&jogador1);

	setGraphicManager();

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
	states.push(new MenuState(&inputManager, &states));
}

void Game::setGraphicManager()
{
	eventManager.setGraphicManager(&graphicManager);
	

	inputManager.setJogador(&jogador1);
}

void Game::run()
{
	
	while (graphicManager.isRunning())
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
		
		if (states.top()->getState() == MENU_STATE)
		{
			states.top()->update(deltaTime);
		}

		if (states.top()->getState() == GAME_STATE)
		{
			inputManager.update(deltaTime);
			jogador1.update();
			states.top()->update(deltaTime);
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
	graphicManager.clear();

	if (!states.empty())
	{
		states.top()->render();

		if (states.top()->getState() == GAME_STATE)
		{
			jogador1.renderBarraVida();
			jogador1.render();
		}
	}
				
	graphicManager.display();
}


void Game::updateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

void Game::updatePollEvents()
{
	eventManager.pollEvents();
	
}



