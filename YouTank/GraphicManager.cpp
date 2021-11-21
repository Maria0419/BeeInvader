#include "stdafx.h"
#include "GraphicManager.h"

GraphicManager* GraphicManager::instance = NULL;

void GraphicManager::initFont()
{
	if (!fonte.loadFromFile("Fonts/Beezybee.ttf"))
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
	delete instance;
}

GraphicManager* GraphicManager::getInstance()
{
	if (instance == NULL)
		instance = new GraphicManager();
	return instance;
}

void GraphicManager::clear()
{
	window.clear();
}

void GraphicManager::render(sf::RectangleShape body)
{
	window.draw(body); 
}

void GraphicManager::render(sf::Sprite body)
{
	window.draw(body);
}

void GraphicManager::render(sf::Text text)
{
	window.draw(text);
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


