#include "stdafx.h"
#include "MenuState.h"

void MenuState::initText()
{

	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	texto.setFont(*fonte);
	texto.setString("BEEINVADER");
	texto.setFillColor(sf::Color::Yellow);
	texto.setOutlineColor(sf::Color::Black);
	texto.setOutlineThickness(3.f);
	texto.setCharacterSize(134);
	texto.setPosition(370.f, 30.f);

}

void MenuState::initButtons()
{
	buttons["NOVO_JOGO"] = new Button(200, "Novo Jogo");
	buttons["FASE_1"] = new Button(275, "Primeira Fase");
	buttons["FASE_2"] = new Button(350, "Segunda Fase");
	buttons["MULTIPLAYER"] = new Button(425, "Multiplayer");
	buttons["RANKING"] = new Button(500, "Ranking");
	buttons["SAIR"] = new Button(575, "Sair");
}

MenuState::MenuState(std::stack<State*>* state, InputManager* pIM):
	State(state, pIM),
	Menu("Imagens/menu.png")
{
	stateID = MENU_STATE;
	initButtons();
	initText();
}

MenuState::~MenuState()
{

}

const short MenuState::getState()
{
	return stateID;
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
		states->push(new GameState(states, pInput, 2));
	}
	else if (buttons["MULTIPLAYER"]->estaPressionado())
	{
		states->push(new GameState(states, pInput, 1, true));
	}
	else if (buttons["RANKING"]->estaPressionado())
	{
		
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
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

void MenuState::render()
{
	background.render();
	renderText();
	renderButtons();
}

