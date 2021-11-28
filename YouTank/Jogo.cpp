#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo():
	sair(false)
{
	pGraphic = GraphicManager::getInstance();

	setGraphicManager();

	initEstados();
	run();
}

Jogo::~Jogo()
{
	//delete estados
	while (!estados.empty())
	{
		delete estados.top();
		estados.pop();
	}
}

void Jogo::initEstados()
{
	estados.push(new MenuEstado(&estados, &inputManager));
}

void Jogo::setGraphicManager()
{
	//Menu::setGraphicManager(pGraphic);
	Ente::setGraphicManager(pGraphic);
	inputManager.setGraphicManager(pGraphic);
	eventManager.setGraphicManager(pGraphic);
}

void Jogo::run()
{
	
	while (pGraphic->isRunning() && sair == false)
	{
		update();
		render();
	}
	
}

void Jogo::update()
{
	updatePollEvents();

	if (!estados.empty())
	{
		estados.top()->update();
		
		//Caso estiver na janela do Pause e quer voltar a jogar
		if (estados.top()->getEstado() == PAUSE_STATE && estados.top()->getPause() == false)
		{
			delete estados.top();
			estados.pop();
			estados.top()->setPause(false); //ver se funciona sem
		}
		//Caso estiver na janela do Pause e quer salvar
		if (estados.top()->getEstado() == PAUSE_STATE && estados.top()->getSalvarFase())
		{
			delete estados.top();
			estados.pop();
			estados.top()->salvar();
			estados.push(new PauseEstado(&estados, &inputManager));
		}

		//caso deseja ir ao menu
		if (estados.top()->getIrMenu() == true)
		{
			while (estados.top()->getEstado() != MENU_STATE)
			{
				delete estados.top();
				estados.pop();
			}
		}

		//após ter inserido o nome, continuar para o jogo
		if (estados.top()->getEstado() == NOME_STATE && estados.top()->getTerminarEstado())
		{
			sf::String nome = estados.top()->getNome();
			delete estados.top();
			estados.pop();
			if(estados.top()->getEstado() == GAME_STATE)
				estados.top()->setNome(nome);

		}

		//fechar o jogo
		if (estados.top()->getSair())
		{
			sair = true;
			while (!estados.empty())
			{
				delete estados.top();
				estados.pop();
			}
		}
	}
}

void Jogo::render()
{
	pGraphic->clear();

	if (!estados.empty())
	{
		estados.top()->render();
	}
				
	pGraphic->display();
}

void Jogo::updatePollEvents()
{
	eventManager.pollEvents(estados.top());
	
}



