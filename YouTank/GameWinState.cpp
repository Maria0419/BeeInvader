#include "stdafx.h"
#include "GameWinState.h"

void GameWinState::initText()
{
	//Inicializa o texto do bot�o
	fonte = pGraphic->getFont();

	texto.setFont(*fonte);
	texto.setString("VITORIA");
	texto.setFillColor(sf::Color::Yellow);
	texto.setOutlineColor(sf::Color::Black);
	texto.setOutlineThickness(3.f);
	texto.setCharacterSize(74);
	texto.setPosition(390.f, 80.f);
}

void GameWinState::initButtons()
{
	buttons["RANKING"] = new Button(300, "Ranking");
	buttons["VOLTAR_MENU"] = new Button(375, "Voltar ao Menu");
	buttons["SAIR"] = new Button(450, "Sair");
}

GameWinState::GameWinState(std::stack<State*>* state, InputManager* pIM) :
	State(state, pIM),
	Menu("Imagens/treeForest.jpg")
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