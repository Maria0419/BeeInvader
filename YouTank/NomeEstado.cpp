#include "stdafx.h"
#include "NomeEstado.h"
using namespace ElementosVisuais;

void NomeEstado::initText()
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

void NomeEstado::initButtons()
{
	buttons["CONTINUAR"] = new Button(450, "Continuar");
}

NomeEstado::NomeEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM) :
	Estado(estado, pIM, NOME_STATE),
	Menu("Imagens/f.png")
{
	initButtons();
	initText();
}

NomeEstado::~NomeEstado()
{
	deletarButtons();
	texto.clear();
}

const short NomeEstado::getEstado()
{
	return estadoID;
}

const std::string NomeEstado::getNome() const
{
	return texto[1].getString();
}

void NomeEstado::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}

	if (buttons["CONTINUAR"]->estaPressionado() && texto[1].getString()!="")
	{
		terminarEstado = true;
	}
}

void NomeEstado::updateInput()
{
	pComando->updateMousePos();
}

void NomeEstado::update()
{
	updateInput();
	updateButtons();
}

void NomeEstado::retiraLetra(char letra)
{
	std::string nome = texto[1].getString();
	if (nome != "")
		nome.pop_back();
	texto[1].setString(nome);
}

void NomeEstado::incluaLetra(char letra)
{
	std::string nome = texto[1].getString();
	nome += letra;
	texto[1].setString(nome);
}

void NomeEstado::render()
{
	background.render();
	renderText();
	renderButtons();
}