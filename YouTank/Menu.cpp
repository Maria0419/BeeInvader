#include "stdafx.h"
#include "Menu.h"
using namespace ElementosVisuais;

Menu::Menu(const char* file):
	plano_fundo(file)
{
	pGrafico = GerenciadorGrafico::getInstancia();
	fonte = pGrafico->getFont();
}

Menu::~Menu()
{

}

void Menu::deletarBotoes()
{
	auto it = botoes.begin();
	for (it = botoes.begin(); it != botoes.end(); ++it)
	{
		delete it->second;
	}
}

void Menu::renderBotoes()
{
	for (auto& it : botoes)
	{
		it.second->render();
		it.second->renderText();
	}
}

void Menu::renderText()
{
	for (auto it : texto)
	{
		renderTexto(it);
	}
	
}