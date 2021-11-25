#include "stdafx.h"
#include "NomeState.h"

void NomeState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	texto.setFont(*fonte);
	texto.setString("Insira seu nome: ");
	texto.setFillColor(sf::Color::Yellow);
	texto.setOutlineColor(sf::Color::Black);
	texto.setOutlineThickness(3.f);
	texto.setCharacterSize(124);
	texto.setPosition(340.f, 80.f);
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