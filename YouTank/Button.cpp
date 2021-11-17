#include "stdafx.h"
#include "Button.h"


Button::Button(float x, float y, float largura, float altura, std::string text):
	Ente()
{
	id = 302;
	estadoBotao = BT_IDLE;

	setSize(largura, altura);
	setPosition(x, y);
	setOutline(2.f);

	fonte = pGraphic->getFont();


	texto.setFont(*fonte);
	texto.setString(text);
	texto.setFillColor(sf::Color::White);
	texto.setCharacterSize(24);
	texto.setPosition(
		getPosition().x + getBounds().width / 2.f - texto.getGlobalBounds().width / 2.f,
		getPosition().y + getBounds().height / 3.f - texto.getGlobalBounds().height / 2.f);
	

	red = 100;
	green = 100;
	blue = 100;

	setCor(red, green, blue, 255);
}

Button::~Button()
{
}

const bool Button::estaPressionado() const
{
	if (estadoBotao == BT_PRESSIONADO)
		return true;
	else
		return false;
}

void Button::update(const float posX, const float posY)
{
	estadoBotao = BT_IDLE;

	//mouse em cima do borao
	if (contem(posX, posY))
	{
		estadoBotao = BT_EMCIMA;

		//botao pressionado
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			estadoBotao = BT_PRESSIONADO;
		}
	}

	switch (estadoBotao)
	{
	case BT_IDLE:
		setCor(red, green, blue, 255);
		break;

	case BT_EMCIMA:
		setCor(red, green, blue+60, 255);
		break;

	case BT_PRESSIONADO:
		setCor(red, green, blue+120, 255);
		break;

	default:
		setCor(255, 0, 0, 255);
		break;
	}

}

void Button::renderText()
{
	renderTexto(texto);
}
