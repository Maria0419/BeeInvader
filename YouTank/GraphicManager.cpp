#include "stdafx.h"
#include "GraphicManager.h"

void GraphicManager::initFont()
{
	if (!fonte.loadFromFile("Fonts/GraphikSemibold.otf"))
		std::cout << "ERROR::GRAPHICMANAGER::INITFONT::Erro ao carregar a fonte" << std::endl;
}

GraphicManager::GraphicManager():
	window(sf::VideoMode(1280, 720), "CubeTank", sf::Style::Close | sf::Style::Titlebar)
{
	window.setFramerateLimit(60);
	initFont();
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::clear()
{
	window.clear();
}

void GraphicManager::drawShapes(sf::RectangleShape body)
{
	window.draw(body); 
}

void GraphicManager::drawShapes(sf::Sprite body)
{
	window.draw(body);
}

void GraphicManager::display()
{
	window.display();
}


void GraphicManager::close()
{
	window.close();
}

sf::RenderWindow* GraphicManager::getWindow()
{
	return &window;
}

sf::Font* GraphicManager::getFont()
{
	return &fonte;
}

const bool GraphicManager::isRunning() const
{
	return window.isOpen();
}


