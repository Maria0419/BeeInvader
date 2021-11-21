#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() :
	pCurandeira(NULL),
	pFadaCaida1(NULL),
	pGraphic(NULL), 
	pFase(NULL),
	mouseHeld(false)
{
	
}

InputManager::~InputManager()
{
}

void InputManager::update(float deltaTime)
{
	updateFadaCaida(deltaTime);
	if(pCurandeira!=NULL)
		updateCurandeira(deltaTime);
}

void InputManager::updateAtaqueFadaCaida()
{
	pFadaCaida1->updateAtaqueCooldown();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pFadaCaida1->getPodeAtacar())
	{
		float dir_x = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).x);
		float dir_y = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).y);
		pFadaCaida1->ataca(dir_x, dir_y);
	}
	
}

void InputManager::updateAtaqueCurandeira()
{
	pCurandeira->updateAtaqueCooldown();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && pCurandeira->getPodeAtacar())
	{
		pCurandeira->curar(pFadaCaida1->getPosition().x , pFadaCaida1->getPosition().y, pCurandeira->getPosition().x, pCurandeira->getPosition().y);
	}
}

void InputManager::updateMousePos()
{
	mousePosWindow = sf::Mouse::getPosition(*pGraphic->getWindow());
}

void InputManager::updateFadaCaida(float deltaTime)
{
	
	pFadaCaida1->setVelocidadeX(pFadaCaida1->getVelocidadeX() * 0.94f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pFadaCaida1->setVelocidadeX(pFadaCaida1->getVelocidadeX() - pFadaCaida1->getRapidez());

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pFadaCaida1->setVelocidadeX(pFadaCaida1->getVelocidadeX() + pFadaCaida1->getRapidez());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pFadaCaida1->getPodePular())
	{
		pFadaCaida1->setPodePular(false);
		pFadaCaida1->setVelocidadeY(-sqrtf(2.0f * 981.f * pFadaCaida1->getAlturaPulo()));
	}
	pFadaCaida1->setVelocidadeY(pFadaCaida1->getVelocidadeY() + 981.f * deltaTime);

	if (pFadaCaida1->getVelocidadeX() < 0)
		pFadaCaida1->setOlhaEsquerda(true);
	else
		pFadaCaida1->setOlhaEsquerda(false);

	pFadaCaida1->move(pFadaCaida1->getVelocidadeX() * deltaTime, pFadaCaida1->getVelocidadeY() * deltaTime);

	updateAtaqueFadaCaida();
}

void InputManager::updateCurandeira(float deltaTime)
{
	pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() * 0.98f);
	pCurandeira->setVelocidadeY(pCurandeira->getVelocidadeY() * 0.98f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() - pCurandeira->getRapidez());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() + pCurandeira->getRapidez());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		pCurandeira->setVelocidadeY(pCurandeira->getVelocidadeY() - pCurandeira->getRapidez());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		pCurandeira->setVelocidadeY(pCurandeira->getVelocidadeY() + pCurandeira->getRapidez());
	if (pCurandeira->getVelocidadeX() < 0)
		pCurandeira->setOlhaEsquerda(true);
	else
		pCurandeira->setOlhaEsquerda(false);
	pCurandeira->move(pCurandeira->getVelocidadeX() * deltaTime, pCurandeira->getVelocidadeY() * deltaTime);
	updateAtaqueCurandeira();
}


void InputManager::setFadaCaida(FadaCaida* pFadaCaida)
{
	pFadaCaida1 = pFadaCaida;
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

const bool InputManager::getPause() const 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return true;
	else
		return false;

}

void InputManager::setCurandeira(Curandeira* pC)
{
	pCurandeira = pC;
}
