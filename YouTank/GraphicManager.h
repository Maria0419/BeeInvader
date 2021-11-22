#pragma once
#include "stdafx.h"

class GraphicManager
{
private:

	//Singleton
	static GraphicManager* instance;

	//window
	sf::RenderWindow window;
	sf::Font fonte;

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
	void render(sf::RectangleShape body);
	void render(sf::Sprite body);
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

