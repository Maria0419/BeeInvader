#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	graphicManager = GraphicManager::getInstance();

	setGraphicManager();

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
	

	if (!states.empty())
	{
		states.top()->update();
		
		if (states.top()->getState() == MENU_STATE)
		{
		}

		else if (states.top()->getState() == GAME_STATE)
		{
			
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
	}
				
	graphicManager->display();
}

void Game::updatePollEvents()
{
	eventManager.pollEvents();
	
}



