#pragma once
#include "stdafx.h"

class GerenciadorGrafico
{
private:

	//Singleton
	static GerenciadorGrafico* instancia;

	//window
	sf::RenderWindow window;
	sf::Font fonte;

	//private functions
	void initFont();

	GerenciadorGrafico();

public:
	~GerenciadorGrafico();

	//Singleton
	static GerenciadorGrafico* getInstancia();

	//clear & display
	void clear();
	void render(sf::RectangleShape body);
	void render(sf::Text text);
	void display();

	//close
	void close();


	//modifiers

	//accessors
	sf::RenderWindow* getWindow();
	sf::Font* getFont();
	const bool estaExecutando() const;

};
