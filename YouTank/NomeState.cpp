#include "stdafx.h"
#include "NomeState.h"

void NomeState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	for (auto it : texto)
	{
		it.setFont(*fonte);
		it.setOutlineColor(sf::Color::Black);
		it.setOutlineThickness(3.f);
	}
	
	texto[0].setString("Insira seu nome: ");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setCharacterSize(124);
	texto[0].setPosition(340.f, 80.f);
	
	texto[1].setFillColor(sf::Color::White);
	texto[1].setCharacterSize(84);
	texto[1].setPosition(340.f, 400.f);
}

void NomeState::initButtons()
{
	buttons["CONTINUAR"] = new Button(450, "Continuar");
}

NomeState::NomeState(std::stack<State*>* state, InputManager* pIM) :
	State(state, pIM, NOME_STATE),
	Menu("Imagens/f.png")
{
	initButtons();
	initText();
}

NomeState::~NomeState()
{
	deletarButtons();
}

const short NomeState::getState()
{
	return stateID;
}

void NomeState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}

	if (buttons["CONTINUAR"]->estaPressionado())
	{
		terminarState = true;
	}
}

void NomeState::updateInput()
{
	pInput->updateMousePos();
}

void NomeState::update()
{
	updateInput();
	updateButtons();
}

void NomeState::render()
{
	background.render();
	renderText();
	renderButtons();
}