#include "stdafx.h"
#include "FimJogoEstado.h"
using namespace ElementosVisuais;

void FimJogoEstado::initText()
{
	//Inicializa o texto do botão
	fonte = pGrafico->getFont();

	sf::Text fimJogo;
	texto.push_back(fimJogo);

	texto[0].setFont(*fonte);
	texto[0].setString("JOGO OVER");
	texto[0].setFillColor(sf::Color::Yellow);
	texto[0].setOutlineColor(sf::Color::Black);
	texto[0].setOutlineThickness(3.f);
	texto[0].setCharacterSize(134);
	texto[0].setPosition(380.f, 80.f);
}

void FimJogoEstado::initBotoes()
{
	botoes["VOLTAR_MENU"] = new Botao(300, "Voltar ao Menu");
	botoes["SAIR"] = new Botao(375, "Sair");
}

FimJogoEstado::FimJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC):
	Estado(estado,pGC, JOGOFIM_ESTADO),
	Menu("Imagens/f.png")
{
	fimJogo = true;
	initBotoes();
	initText();
}

FimJogoEstado::~FimJogoEstado()
{
	deletarBotoes();
	texto.clear();
}

const short FimJogoEstado::getEstado()
{
	return estadoID;
}

void FimJogoEstado::updateBotoes()
{
	for (auto& it : botoes)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}

	if (botoes["VOLTAR_MENU"]->estaPressionado())
	{
		irMenu = true;
	}
	else if (botoes["SAIR"]->estaPressionado())
	{
		sair = true;
	}
}

void FimJogoEstado::updateComando()
{
	pComando->updateMousePos();
}

void FimJogoEstado::update()
{
	updateComando();
	updateBotoes();
}

void FimJogoEstado::render()
{
	plano_fundo.render();
	renderText();
	renderBotoes();
}
