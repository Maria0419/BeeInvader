#include "stdafx.h"
#include "Menu.h"

Menu::Menu(const char* file):
	background(file)
{
	pGraphic = GraphicManager::getInstance();
	fonte = pGraphic->getFont();
}

Menu::~Menu()
{
	
}

void Menu::deletarButtons()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Menu::renderButtons()
{
	for (auto& it : buttons)
	{
		it.second->render();
		it.second->renderText();
	}
}

void Menu::renderText()
{
	renderTexto(texto);
}