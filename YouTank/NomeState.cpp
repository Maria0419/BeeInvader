#include "stdafx.h"
#include "NomeState.h"
using namespace ElementosVisuais;

void NomeState::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text cabecalho;
	texto.push_back(cabecalho);
	sf::Text nome;
	texto.push_back(nome);

	texto[0].setFont(*fonte);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setString("Insira seu nome:");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setCharacterSize(124);
	texto[0].setPosition(340.f, 80.f);
	
	texto[1].setFont(*fonte);
	texto[1].setFillColor(sf::Color::White);
	texto[1].setCharacterSize(84);
	texto[1].setPosition(500.f, 300.f);
	texto[1].setOutlineColor(sf::Color::Black);
	texto[1].setOutlineThickness(3.f);
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

const std::string NomeState::getNome() const
{
	return texto[1].getString();
}

void NomeState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pInput->getMousePos().x), (const float)(pInput->getMousePos().y));
	}

	if (buttons["CONTINUAR"]->estaPressionado() && texto[1].getString()!="")
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

void NomeState::retiraLetra(char letra)
{
	std::string nome = texto[1].getString();
	if (nome != "")
		nome.pop_back();
	texto[1].setString(nome);
}

void NomeState::incluaLetra(char letra)
{
	std::string nome = texto[1].getString();
	nome += letra;
	texto[1].setString(nome);
}

void NomeState::render()
{
	background.render();
	renderText();
	renderButtons();
}