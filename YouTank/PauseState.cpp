#include "stdafx.h"
#include "PauseState.h"


void PauseState::initButtons()
{
	buttons["CONTINUAR"] = new Button(250, "Continuar");
	buttons["SALVAR"] = new Button(325, "Salvar");
	buttons["VOLTAR_MENU"] = new Button(400, "Voltar ao Menu");
	buttons["SAIR"] = new Button(475, "Sair");
}

PauseState::PauseState(std::stack<State*>* state, InputManager* pIM):
	State(state, pIM),
	Menu("Imagens/floresta.png")
{
	stateID = PAUSE_STATE;
	pause = true;
	initButtons();
}

PauseState::~PauseState()
{

}

const short PauseState::getState()
{
	return stateID;
}

const bool PauseState::getPause() const
{
	return pause;
}

void PauseState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}

	if (buttons["CONTINUAR"]->estaPressionado())
	{
		pause = false;
	}
	if (buttons["SALVAR"]->estaPressionado())
	{
		pause = false;
	}
	if (buttons["VOLTAR_MENU"]->estaPressionado())
	{
		goToMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void PauseState::updateInput()
{
	pInput->updateMousePos();
	verificarPause();
}

void PauseState::update()
{
	updateButtons();
	updateInput();
}


void PauseState::render()
{
	background.render();
	renderButtons();
	
}
