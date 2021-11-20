#include "stdafx.h"
#include "MenuState.h"

void MenuState::initButtons()
{
	buttons["NOVO_JOGO"] = new Button(550, 100, "Novo Jogo");
	buttons["FASE_1"] = new Button(550, 175, "Primeira Fase");
	buttons["FASE_2"] = new Button(550, 250 , "Segunda Fase");
	buttons["MULTIPLAYER"] = new Button(550, 325, "Multiplayer");
	buttons["RANKING"] = new Button(550, 400, "Ranking");
	buttons["SAIR"] = new Button(550, 475, "Sair");
}

MenuState::MenuState(std::stack<State*>* state, InputManager* pIM):
	State(state, pIM),
	background("Imagens/background_.jpg", 0.73f)
{
	stateID = MENU_STATE;
	initButtons();
}

MenuState::~MenuState()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

const short MenuState::getState()
{
	return stateID;
}

void MenuState::endState()
{
	std::cout << "ending Menu state" << std::endl;
}


void MenuState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float) (pInput->getMousePos().x), (const float) (pInput->getMousePos().y));
	}

	if (buttons["NOVO_JOGO"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	else if (buttons["FASE_1"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	else if (buttons["FASE_2"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	else if (buttons["MULTIPLAYER"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	else if (buttons["RANKING"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		terminar = true;
	}
}

void MenuState::updateInput()
{
	pInput->updateMousePos();
}

void MenuState::update()
{
	updateInput();
	updateButtons();
	
}

void MenuState::renderButtons()
{
	for (auto& it : buttons)
	{
		it.second->render();
		it.second->renderText();
	}
}

void MenuState::render()
{
	background.render();

	renderButtons();
}

