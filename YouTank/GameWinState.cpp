#include "stdafx.h"
#include "GameWinState.h"
#include "GameState.h"

void GameWinState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text gameWin;
	texto.push_back(gameWin);
	texto[0].setFont(*fonte);
	texto[0].setString("VITORIA");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(450.f, 50.f);
}

void GameWinState::initButtons()
{
	if(prox_fase == true)
		buttons["PROX_FASE"] = new Button(225, "Proxima fase");

	buttons["RANKING"] = new Button(300, "Ranking");
	buttons["VOLTAR_MENU"] = new Button(375, "Voltar ao Menu");
	buttons["SAIR"] = new Button(450, "Sair");
}

GameWinState::GameWinState(std::stack<State*>* state, InputManager* pIM, bool prox_f, bool mp) :
	State(state, pIM, GWIN_STATE),
	Menu("Imagens/treeForest.jpg")
{
	prox_fase = prox_f;
	multiplayer = mp;
	gameOver = true;
	initButtons();
	initText();
}

GameWinState::~GameWinState()
{
	deletarButtons();
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
	if (prox_fase)
	{
		if (buttons["PROX_FASE"]->estaPressionado())
		{
			if (multiplayer == true)
				states->push(new GameState(states, pInput, 2, true));
			else
				states->push(new GameState(states, pInput, 2, false));

		}
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