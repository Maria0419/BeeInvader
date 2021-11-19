#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager():
	pJogador1(NULL),
	pGraphic(NULL), 
	pFase(NULL)
{
	
}

InputManager::~InputManager()
{
}

void InputManager::updateAtaque()
{
	pJogador1->updateAtaqueCooldown();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pJogador1->getPodeAtacar())
	{
		float dir_x = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).x);
		float dir_y = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).y);
		pJogador1->ataca(dir_x, dir_y);
		
	}
}

void InputManager::updateMousePos()
{
	mousePosWindow = sf::Mouse::getPosition(*pGraphic->getWindow());
}


void InputManager::update(float deltaTime)
{
	
	pJogador1->setVelocidadeX(pJogador1->getVelocidadeX() * 0.94f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pJogador1->setVelocidadeX(pJogador1->getVelocidadeX() - pJogador1->getRapidez());

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pJogador1->setVelocidadeX(pJogador1->getVelocidadeX() + pJogador1->getRapidez());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pJogador1->getPodePular())
	{
		pJogador1->setPodePular(false);
		pJogador1->setVelocidadeY(-sqrtf(2.0f * 981.f * pJogador1->getAlturaPulo()));
	}
	pJogador1->setVelocidadeY(pJogador1->getVelocidadeY() + 981.f * deltaTime);

	if (pJogador1->getVelocidadeX() < 0)
		pJogador1->setOlhaEsquerda(true);
	else
		pJogador1->setOlhaEsquerda(false);

	pJogador1->move(pJogador1->getVelocidadeX() * deltaTime, pJogador1->getVelocidadeY() * deltaTime);

	updateAtaque();
}


void InputManager::setJogador(Jogador* pJogador)
{
	pJogador1 = pJogador;
}

void InputManager::setGraphicManager(GraphicManager* pGM)
{
	pGraphic = pGM;
}

void InputManager::setFase(Fase* pF)
{
	if (pF)
		pFase = pF;
	else
		std::cout << "ERROR::INPUTMANAGER::SETFASE::Ponteiro Nulo";
}

const sf::Vector2i InputManager::getMousePos() const
{
	return mousePosWindow;
}