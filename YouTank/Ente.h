#pragma once
#include "stdafx.h"
#include "GraphicManager.h"

class Ente
{
protected:
	int id;
	bool aparece;
	static GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;

	//Shape
	sf::RectangleShape body;
	sf::RectangleShape bodyBack;
	sf::Sprite sprite;
	sf::Texture texture;


	//Create shape
	void setSize(float x, float y);
	void setCor(int r, int g, int b, int t);
	void setOutline(float grossura);
	void setTexture(const char* file, float escala);
	void setBodyBack(float x, float y, float largura, float altura);
	

public:
	Ente();
	~Ente();

	void setPosition(float x, float y);

	//Functions
	void render();
	void renderTexto(sf::Text texto);
	void renderBodyBack();
	bool contem(float x, float y);

	//setters
	
	static void setGraphicManager(GraphicManager* pGM);
	virtual void setShowing(bool x);

	//Getters
	sf::RectangleShape* getBody();
	virtual const bool getShowing() const;
	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getSize() const;
	const int getId() const;

	

	
};

