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
		
		//Caso estiver na janela do Pause e quer voltar a jogar
		if (states.top()->getState() == PAUSE_STATE && states.top()->getPause() == false)
		{
			delete states.top();
			states.pop();
			states.top()->setPause(false); //ver se funciona sem
		}
		//Caso estiver na janela do Pause e quer salvar
		if (states.top()->getState() == PAUSE_STATE && states.top()->getSalvarFase())
		{
			delete states.top();
			states.pop();
			states.top()->salvar();
			states.push(new PauseState(&states, &inputManager));
		}

		//caso deseja ir ao menu
		if (states.top()->getGoToMenu() == true)
		{
			while (states.top()->getState() != MENU_STATE)
			{
				delete states.top();
				states.pop();
			}
		}

		//após ter inserido o nome, continuar para o jogo
		if (states.top()->getState() == NOME_STATE && states.top()->getTerminarState())
		{
			sf::String nome = states.top()->getNome();
			delete states.top();
			states.pop();
			if(states.top()->getState() == GAME_STATE)
				states.top()->setNome(nome);

		}

		//fechar o jogo
		if (states.top()->getSair())
		{
			sair = true;
			while (!states.empty())
			{
				delete states.top();
				states.pop();
			}
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
	eventManager.pollEvents(states.top());
	
}



