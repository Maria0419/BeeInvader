#include "stdafx.h"
#include "PauseState.h"


void PauseState::initButtons()
{
	buttons["CONTINUAR"] = new Button(550, 300, "Continuar");
	buttons["SAIR"] = new Button(550, 375, "Sair");
}

PauseState::PauseState(std::stack<State*>* state, InputManager* pIM):
	State(state, pIM),
	Menu("Imagens/floresta.png", 2.f)
{
	stateID = PAUSE_STATE;
	pause = true;
	initButtons();
}

PauseState::~PauseState()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
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
	else if (buttons["SAIR"]->estaPressionado())
	{
		pause = false;
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

void PauseState::renderButtons()
{
	for (auto& it : buttons)
	{
		it.second->render();
		it.second->renderText();
	}
}

void PauseState::render()
{
	background.render();
	renderButtons();
	
}
