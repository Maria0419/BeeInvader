#include "stdafx.h"
#include "FimJogoEstado.h"
using namespace ElementosVisuais;

void FimJogoEstado::initText()
{
	//Inicializa o texto do botão
	fonte = pGraphic->getFont();

	sf::Text fimJogo;
	texto.push_back(fimJogo);

	texto[0].setFont(*fonte);
	texto[0].setString("GAME OVER");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(380.f, 80.f);
}

void FimJogoEstado::initButtons()
{
	buttons["VOLTAR_MENU"] = new Button(300, "Voltar ao Menu");
	buttons["SAIR"] = new Button(375, "Sair");
}

FimJogoEstado::FimJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM):
	Estado(estado,pIM, GOVER_STATE),
	Menu("Imagens/f.png")
{
	fimJogo = true;
	initButtons();
	initText();
}

FimJogoEstado::~FimJogoEstado()
{
	deletarButtons();
	texto.clear();
}

const short FimJogoEstado::getEstado()
{
	return estadoID;
}

void FimJogoEstado::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}

	if (buttons["VOLTAR_MENU"]->estaPressionado())
	{
		irMenu = true;
	}
	else if (buttons["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void FimJogoEstado::updateInput()
{
	pComando->updateMousePos();
}

void FimJogoEstado::update()
{
	updateInput();
	updateButtons();
}

void FimJogoEstado::render()
{
	background.render();
	renderText();
	renderButtons();
}
