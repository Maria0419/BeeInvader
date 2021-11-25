#include "stdafx.h"
#include "RankingState.h"
#include "stdafx.h"

void RankingState::initText()
{

	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	pontuacao[0].setFont(*fonte);
	pontuacao[0].setString("PONTUAÇÃO\n");
	pontuacao[0].setFillColor(sf::Color::Yellow);
	pontuacao[0].setOutlineColor(sf::Color::Black);
	pontuacao[0].setOutlineThickness(3.f);
	pontuacao[0].setCharacterSize(134);
	pontuacao[0].setPosition(370.f, 30.f);

}

void RankingState::initButtons()
{
	
}

RankingState::RankingState(std::stack<State*>* state, InputManager* pIM) :
	State(state, pIM, MENU_STATE),
	Menu("Imagens/menu.png")
{
	initButtons();
	initText();
}

RankingState::~RankingState()
{
	deletarButtons();
}

const short RankingState::getState()
{
	return stateID;
}

void RankingState::updateButtons()
{
	
}

void RankingState::updateInput()
{
	pInput->updateMousePos();
}

void RankingState::update()
{
	updateInput();
	updateButtons();

}

void RankingState::render()
{
	background.render();
	renderText();
	renderButtons();
}

