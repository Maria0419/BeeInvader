#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"

class Ente
{
private:
	sf::RectangleShape bodyBack;
	

protected:

	static GerenciadorGrafico* pGrafico;

	int id;
	bool aparece;
	

	//Shape
	sf::RectangleShape body;
	sf::Texture texture;

	//Create shape
	void setSize(float x, float y);
	void setCor(int r, int g, int b, int t);
	void setOutline(float grossura);
	void setTexture(const char* file);
	void setBodyBack(float x, float y, float largura, float altura);
	void setOriginCenter();
	void rotate(float angulo);
	

public:
	static ListaEntidades* pLista;

	Ente();
	Ente(int i);
	~Ente();

	void setPosition(float x, float y);

	//Functions
	void render();
	void renderTexto(sf::Text texto);
	void renderBodyBack();
	bool contem(float x, float y);
	bool intersecta( Ente* pE);

	//setters
	
	static void setGerenciadorGrafico(GerenciadorGrafico* pGG);
	virtual void setShowing(bool x);

	//Getters
	sf::RectangleShape* getBody();
	const bool getShowing() const;
	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getSize() const;
	const int getId() const;
};



