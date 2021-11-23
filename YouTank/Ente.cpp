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
	body.setTexture(&texture);
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
	body.setOrigin(body.getSize() / 2.0f);
}

void Ente::rotate(float angulo)
{
	body.rotate(angulo);
}

void Ente::renderBodyBack()
{
	pGraphic->render(bodyBack);
}


Ente::Ente():
	aparece(true),
	id(0),
	texture()
{
	
}

Ente::Ente(int i):
	aparece(true),
	id(i),
	texture()
{
}

Ente::~Ente()
{
	
}


//FUNCOES PARA INICIAR E POSICIONAR O SHAPE
void Ente::setPosition(float x, float y)
{
	body.setPosition(x, y);

}

void Ente::render()
{
	pGraphic->render(body);
}

void Ente::renderTexto(sf::Text texto)
{
	pGraphic->render(texto);
}

bool Ente::contem(float x, float y)
{
	if (body.getGlobalBounds().contains(sf::Vector2f(x, y)))
		return true;
	else
		return false;
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
	return body.getPosition();
}

sf::FloatRect Ente::getBounds() const
{	
	return body.getGlobalBounds();
}

sf::Vector2f Ente::getSize() const
{
	return body.getSize();
}

const int Ente::getId() const
{
	return id;
}
