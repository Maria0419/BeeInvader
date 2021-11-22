#include "stdafx.h"
#include "Game.h"

Game::Game():
	sair(false)
{
	pGraphic = GraphicManager::getInstance();

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
	//Menu::setGraphicManager(pGraphic);
	Ente::setGraphicManager(pGraphic);
	inputManager.setGraphicManager(pGraphic);
	eventManager.setGraphicManager(pGraphic);
}

void Game::run()
{
	
	while (pGraphic->isRunning() && sair == false)
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
		if (states.top()->getGoToMenu() == true)
		{
			while (states.top()->getState() != MENU_STATE)
			{
				delete states.top();
				states.pop();
			}
		}

		if (states.top()->getSair())
		{
			sair = true;
			delete states.top();
			states.pop();
		}
	}
}

void Game::render()
{
	pGraphic->clear();

	if (!states.empty())
	{
		states.top()->render();
	}
				
	pGraphic->display();
}

void Game::updatePollEvents()
{
	eventManager.pollEvents();
	
}



