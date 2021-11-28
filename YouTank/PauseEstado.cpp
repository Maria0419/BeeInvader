#include "stdafx.h"
#include "PauseEstado.h"
using namespace ElementosVisuais;


void PauseEstado::initBotoes()
{
	botoes["CONTINUAR"] = new Botao(250, "Continuar");
	botoes["SALVAR"] = new Botao(325, "Salvar");
	botoes["VOLTAR_MENU"] = new Botao(400, "Voltar ao Menu");
	botoes["SAIR"] = new Botao(475, "Sair");
}

PauseEstado::PauseEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC):
	Estado(estado, pGC, PAUSE_ESTADO),
	Menu("Imagens/floresta.png")
{
	pause = true;
	initBotoes();
}

PauseEstado::~PauseEstado()
{
	deletarBotoes();
	texto.clear();
}

const short PauseEstado::getEstado()
{
	return estadoID;
}

const bool PauseEstado::getPause() const
{
	return pause;
}

void PauseEstado::updateBotoes()
{
	for (auto& it : botoes)
	{
		it.second->update((const float)(pComando->getMousePos().x), (const float)(pComando->getMousePos().y));
	}

	if (botoes["CONTINUAR"]->estaPressionado())
	{
		pause = false;
	}
	if (botoes["SALVAR"]->estaPressionado())
	{
		salvarFase = true;
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

void PauseEstado::updateComando()
{
	pComando->updateMousePos();
	verificarPause();
}

void PauseEstado::update()
{
	updateBotoes();
	updateComando();
}


void PauseEstado::render()
{
	plano_fundo.render();
	renderBotoes();
	
}
