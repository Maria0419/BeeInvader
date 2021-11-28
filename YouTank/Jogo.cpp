#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo():
	sair(false)
{
	pGrafico = GerenciadorGrafico::getInstancia();

	setGerenciadorGrafico();

	initEstados();
	executar();
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
	estados.push(new MenuEstado(&estados, &gerenciadorComando));
}

void Jogo::setGerenciadorGrafico()
{
	//Menu::setGerenciadorGrafico(pGrafico);
	Ente::setGerenciadorGrafico(pGrafico);
	gerenciadorComando.setGerenciadorGrafico(pGrafico);
	gerenciadorEvento.setGerenciadorGrafico(pGrafico);
}

void Jogo::executar()
{
	
	while (pGrafico->estaExecutando() && sair == false)
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
		if (estados.top()->getEstado() == PAUSE_ESTADO && estados.top()->getPause() == false)
		{
			delete estados.top();
			estados.pop();
			estados.top()->setPause(false); //ver se funciona sem
		}
		//Caso estiver na janela do Pause e quer salvar
		if (estados.top()->getEstado() == PAUSE_ESTADO && estados.top()->getSalvarFase())
		{
			delete estados.top();
			estados.pop();
			estados.top()->salvar();
			estados.push(new PauseEstado(&estados, &gerenciadorComando));
		}

		//caso deseja ir ao menu
		if (estados.top()->getIrMenu() == true)
		{
			while (estados.top()->getEstado() != MENU_ESTADO)
			{
				delete estados.top();
				estados.pop();
			}
		}

		//após ter inserido o nome, continuar para o jogo
		if (estados.top()->getEstado() == NOME_ESTADO && estados.top()->getTerminarEstado())
		{
			sf::String nome = estados.top()->getNome();
			delete estados.top();
			estados.pop();
			if(estados.top()->getEstado() == JOGO_ESTADO)
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
	pGrafico->clear();

	if (!estados.empty())
	{
		estados.top()->render();
	}
				
	pGrafico->display();
}

void Jogo::updatePollEvents()
{
	gerenciadorEvento.pollEvents(estados.top());
	
}



