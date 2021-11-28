#include "stdafx.h"
#include "PauseEstado.h"
using namespace ElementosVisuais;


void PauseEstado::initButtons()
{
	buttons["CONTINUAR"] = new Button(250, "Continuar");
	buttons["SALVAR"] = new Button(325, "Salvar");
	buttons["VOLTAR_MENU"] = new Button(400, "Voltar ao Menu");
	buttons["SAIR"] = new Button(475, "Sair");
}

PauseEstado::PauseEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM):
	Estado(estado, pIM, PAUSE_STATE),
	Menu("Imagens/floresta.png")
{
	pause = true;
	initButtons();
}

PauseEstado::~PauseEstado()
{
	deletarButtons();
	texto.clear();
}

const short PauseEstado::getEstado()
{
	return estadoID;
}

const bool PauseEstado::getPause() const
{
	return pause;
}

void PauseEstado::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}

	if (buttons["CONTINUAR"]->estaPressionado())
	{
		pause = false;
	}
	if (buttons["SALVAR"]->estaPressionado())
	{
		salvarFase = true;
	}
	if (buttons["VOLTAR_MENU"]->estaPressionado())
	{
		irMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void PauseEstado::updateInput()
{
	pComando->updateMousePos();
	verificarPause();
}

void PauseEstado::update()
{
	updateButtons();
	updateInput();
}


void PauseEstado::render()
{
	background.render();
	renderButtons();
	
}
