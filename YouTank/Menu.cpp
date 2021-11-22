#include "stdafx.h"
#include "Menu.h"

GraphicManager* Menu::pGraphic = NULL;

Menu::Menu(const char* file):
	background(file)
{
	pGraphic = GraphicManager::getInstance();
	fonte = pGraphic->getFont();
}

Menu::~Menu()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void Menu::setGraphicManager(GraphicManager* pGM)
{
	if (pGM)
		pGraphic = pGM;

	else
		std::cout << "ERROR::STATE::SETGRAPHICMANAGER::Ponteiro Nulo" << std::endl;
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
	pGraphic->render(texto);
}