#include "stdafx.h"
#include "GameOverState.h"

void GameOverState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text gameOver;
	texto.push_back(gameOver);

	texto[0].setFont(*fonte);
	texto[0].setString("GAME OVER");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(380.f, 80.f);
}

void GameOverState::initButtons()
{
	buttons["VOLTAR_MENU"] = new Button(300, "Voltar ao Menu");
	buttons["SAIR"] = new Button(375, "Sair");
}

GameOverState::GameOverState(std::stack<State*>* state, InputManager* pIM):
	State(state,pIM, GOVER_STATE),
	Menu("Imagens/f.png")
{
	gameOver = true;
	initButtons();
	initText();
}

GameOverState::~GameOverState()
{
	deletarButtons();
}

const short GameOverState::getState()
{
	return stateID;
}

void GameOverState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
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

void GameOverState::updateInput()
{
	pInput->updateMousePos();
}

void GameOverState::update()
{
	updateInput();
	updateButtons();
}

void GameOverState::render()
{
	background.render();
	renderText();
	renderButtons();
}
