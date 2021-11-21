#include "stdafx.h"
#include "GameOverState.h"

void GameOverState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	texto.setFont(*fonte);
	texto.setString("GAME OVER");
	texto.setFillColor(sf::Color::Yellow);
	texto.setOutlineColor(sf::Color::Black);
	texto.setOutlineThickness(3.f);
	texto.setCharacterSize(120);
	texto.setPosition(390.f, 80.f);
}

void GameOverState::initButtons()
{
	buttons["VOLTAR"] = new Button(550, 300, "Voltar ao Menu");
	buttons["SAIR"] = new Button(550, 375, "Sair");
}

GameOverState::GameOverState(std::stack<State*>* state, InputManager* pIM):
	State(state,pIM),
	Menu("Imagens/f.png", 1.9f)
{
	stateID = GOVER_STATE;
	gameOver = true;
	initButtons();
	initText();
}

GameOverState::~GameOverState()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
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

	if (buttons["VOLTAR"]->estaPressionado())
	{
		goToMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		
	}
}

void GameOverState::updateInput()
{
	pInput->updateMousePos();
	verificarPause();
}

void GameOverState::update()
{
	updateInput();
	updateButtons();
}

void GameOverState::renderText()
{
	pGraphic->render(texto);
}

void GameOverState::renderButtons()
{
	for (auto& it : buttons)
	{
		it.second->render();
		it.second->renderText();
	}
}

void GameOverState::render()
{
	background.render();
	renderText();
	renderButtons();
}
