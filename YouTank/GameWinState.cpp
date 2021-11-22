#include "stdafx.h"
#include "GameWinState.h"

void GameWinState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	texto.setFont(*fonte);
	texto.setString("VITÓRIA");
	texto.setFillColor(sf::Color::Yellow);
	texto.setOutlineColor(sf::Color::Black);
	texto.setOutlineThickness(3.f);
	texto.setCharacterSize(120);
	texto.setPosition(430.f, 80.f);
}

void GameWinState::initButtons()
{
	buttons["SALVAR"] = new Button(550, 300, "Salvar");
	buttons["RANKING"] = new Button(550, 375, "Ranking");
	buttons["VOLTAR_MENU"] = new Button(550, 450, "Voltar ao Menu");
	buttons["SAIR"] = new Button(550, 525, "Sair");
}

GameWinState::GameWinState(std::stack<State*>* state, InputManager* pIM) :
	State(state, pIM),
	Menu("Imagens/gamewin.jpg")
{
	stateID = GWIN_STATE;
	gameOver = true;
	initButtons();
	initText();
}

GameWinState::~GameWinState()
{

}

const short GameWinState::getState()
{
	return stateID;
}

void GameWinState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}
	if (buttons["SALVAR"]->estaPressionado())
	{
		//goToMenu = true;
	}
	if (buttons["RANKING"]->estaPressionado())
	{
		//goToMenu = true;
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

void GameWinState::updateInput()
{
	pInput->updateMousePos();
}

void GameWinState::update()
{
	updateInput();
	updateButtons();
}

void GameWinState::render()
{
	background.render();
	renderText();
	renderButtons();
}