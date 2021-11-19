#pragma once
#include "stdafx.h"

class GraphicManager
{
private:
	//window
	sf::RenderWindow window;
	sf::Font fonte;

	//private functions
	void initFont();

public:
	GraphicManager();
	~GraphicManager();

	//clear & display
	void clear();
	void drawShapes(sf::RectangleShape body);
	void drawShapes(sf::Sprite body);
	void display();

	//close
	void close();


	//modifiers

	//accessors
	sf::RenderWindow* getWindow();
	sf::Font* getFont();
	const bool isRunning() const;

};

