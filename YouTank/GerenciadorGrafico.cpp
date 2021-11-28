#include "stdafx.h"
#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

void GerenciadorGrafico::initFont()
{
	if (!fonte.loadFromFile("Fonts/TfFancy.otf"))
		std::cout << "ERROR::GRAPHICMANAGER::INITFONT::Erro ao carregar a fonte" << std::endl;
}

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1280, 720), "BeeInvader", sf::Style::Close | sf::Style::Titlebar)
{
	window.setFramerateLimit(60);
	initFont();
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	delete instancia;
}

GerenciadorGrafico* GerenciadorGrafico::getInstancia()
{
	if (instancia == NULL)
		instancia = new GerenciadorGrafico();
	return instancia;
}

void GerenciadorGrafico::clear()
{
	window.clear();
}

void GerenciadorGrafico::render(sf::RectangleShape body)
{
	window.draw(body); 
}

void GerenciadorGrafico::render(sf::Text text)
{
	window.draw(text);
}

void GerenciadorGrafico::display()
{
	window.display();
}


void GerenciadorGrafico::close()
{
	window.close();
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
	return &window;
}

sf::Font* GerenciadorGrafico::getFont()
{
	return &fonte;
}

const bool GerenciadorGrafico::estaExecutando() const
{
	return window.isOpen();
}


