#pragma once
#include "stdafx.h"

class GraphicManager
{
private:
	//window
	sf::RenderWindow window;
	sf::Font fonte;

	//Singleton
	static GraphicManager* instance;

	//private functions
	void initFont();

protected:
	GraphicManager();

public:
	~GraphicManager();

	//Singleton
	static GraphicManager* getInstance();

	//clear & display
	void clear();
	void drawShapes(sf::RectangleShape body);
	void drawShapes(sf::Sprite body);
	void render(sf::Text text);
	void display();

	//close
	void close();


	//modifiers

	//accessors
	sf::RenderWindow* getWindow();
	sf::Font* getFont();
	const bool isRunning() const;

};

