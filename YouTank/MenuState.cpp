#include "stdafx.h"
#include "MenuState.h"

void MenuState::initButtons()
{
	buttons["FASE_1"] = new Button(550, 200, 200, 50, "Primeira Fase");
	buttons["SAIR"] = new Button(550, 275, 200, 50, "Sair");
}

MenuState::MenuState(InputManager* pIM, std::stack<State*>* state):
	State(state),
	background("Imagens/background_.jpg", 0.8f)
{
	stateID = MENU_STATE;
	pInput = pIM;
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
		it.second->update(pInput->getMousePos().x, pInput->getMousePos().y);
	}

	if (buttons["FASE_1"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1));
	}
	if (buttons["SAIR"]->estaPressionado())
	{
		terminar = true;
	}
}

void MenuState::updateInput(const float& dt)
{
	verificarFim();
	pInput->updateMousePos();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		std::cout << "BEIJAR OUTRAS BOCAS DEPOIS QUE TERMINA" << std::endl;
}

void MenuState::update(const float& dt)
{
	updateInput(dt);
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

