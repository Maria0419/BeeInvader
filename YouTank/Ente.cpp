#include "stdafx.h"
#include "Ente.h"

GraphicManager* Ente::pGraphic = NULL;
ListaEntidades* Ente::pLista = NULL;


void Ente::setSize(float x, float y)
{
	body.setSize(sf::Vector2f(x, y));
}

void Ente::setCor(int r, int g, int b, int t)
{
	body.setFillColor(sf::Color(r, g, b, t));
}

void Ente::setOutline(float grossura)
{
	body.setOutlineColor(sf::Color::Black);
	body.setOutlineThickness(grossura);
}

void Ente::setTexture(const char* file, float escala)
{
	texture.loadFromFile(file);
	if (id % 2)
	{
		sprite.setTexture(texture);
		sprite.setScale(escala, escala);
	}
	else
	{
		body.setTexture(&texture);
	}
}

void Ente::setBodyBack(float x, float y, float largura, float altura)
{
	bodyBack.setPosition(x, y);
	bodyBack.setSize(sf::Vector2f(largura, altura));
	bodyBack.setFillColor(sf::Color(255, 255, 255, 10));
	bodyBack.setOutlineColor(sf::Color::Black);
	bodyBack.setOutlineThickness(2.f);
}

void Ente::setOriginCenter()
{
	if (id % 2)
	{
		//sprite.setOrigin(sprite.getGlobalBounds() / 2.0f);;
	}
	else
	{
		body.setOrigin(body.getSize() / 2.0f);
	}
	
}

void Ente::rotate(float angulo)
{
	body.rotate(angulo);
}

void Ente::renderBodyBack()
{
	pGraphic->drawShapes(bodyBack);
}


Ente::Ente():
	aparece(true),
	id(0),
	pWindow(NULL),
	texture()
{
	
}

Ente::~Ente()
{
	
}


//FUNCOES PARA INICIAR E POSICIONAR O SHAPE
void Ente::setPosition(float x, float y)
{
	if (id % 2 ) // se é Sprite
	{
		sprite.setPosition(x, y);
	}
	else //se é rectangle Shape
	{
		body.setPosition(x, y);
	}
}

void Ente::render()
{
	if (id % 2)
		pGraphic->drawShapes(sprite);
	else
		pGraphic->drawShapes(body);
}

void Ente::renderTexto(sf::Text texto)
{
	pGraphic->getWindow()->draw(texto);
}

bool Ente::contem(float x, float y)
{
	if (id % 2) // se é Sprite
	{
		if (sprite.getGlobalBounds().contains(sf::Vector2f(x, y)))
			return true;
		else
			return false;
	}
	else //se é rectangle Shape
	{
		if (body.getGlobalBounds().contains(sf::Vector2f(x, y)))
			return true;
		else
			return false;
	}
}

bool Ente::intersecta(Ente* pE)
{
	if (this->getBounds().intersects(pE->getBounds()))
		return true;
	else
		return false;
}

void Ente::setGraphicManager(GraphicManager* pGM)
{
	pGraphic = pGM;
}


void Ente::setShowing(bool x)
{
	aparece = x;
}


const bool Ente::getShowing() const
{
	return aparece;
}



sf::RectangleShape* Ente::getBody()
{
	return &body;
}

sf::Vector2f Ente::getPosition() const
{
	if (id % 2) // se é Sprite
	{
		return sprite.getPosition();
	}
	else //se é rectangle Shape
	{
		return body.getPosition();
	}
	
}

sf::FloatRect Ente::getBounds() const
{	
	if (id % 2) // se é Sprite
	{
		return sprite.getGlobalBounds();
	}
	else //se é rectangle Shape
	{
		return body.getGlobalBounds();
	}
}

sf::Vector2f Ente::getSize() const
{
	if (id % 2) // se é Sprite
	{
		return static_cast<sf::Vector2f> (texture.getSize());
	}
	else //se é rectangle Shape
	{
		return body.getSize();
	}
	
}

const int Ente::getId() const
{
	return id;
}
