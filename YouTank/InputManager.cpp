#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() :
	pCurandeira(NULL),
	pFadaCaida(NULL),
	pGraphic(NULL), 
	pFase(NULL)
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
	pFadaCaida->updateAtaqueCooldown();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pFadaCaida->getPodeAtacar())
	{
		float dir_x = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).x);
		float dir_y = static_cast<float> (sf::Mouse::getPosition(*pGraphic->getWindow()).y);
		pFadaCaida->ataca(dir_x, dir_y);
	}
	
}

void InputManager::updateAtaqueCurandeira()
{
	pCurandeira->updateAtaqueCooldown();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && pCurandeira->getPodeAtacar())
	{
		pCurandeira->curar(pFadaCaida->getPosition().x , pFadaCaida->getPosition().y, pCurandeira->getPosition().x, pCurandeira->getPosition().y);
	}
}

void InputManager::updateMousePos()
{
	mousePosWindow = sf::Mouse::getPosition(*pGraphic->getWindow());
}

void InputManager::updateFadaCaida(float deltaTime)
{
	
	pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() * 0.94f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() - pFadaCaida->getRapidez());

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() + pFadaCaida->getRapidez());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pFadaCaida->getPodePular())
	{
		pFadaCaida->setPodePular(false);
		pFadaCaida->setVelocidadeY(-sqrtf(2.0f * 981.f * pFadaCaida->getAlturaPulo()));
	}
	pFadaCaida->setVelocidadeY(pFadaCaida->getVelocidadeY() + 981.f * deltaTime);

	if (pFadaCaida->getVelocidadeX() < 0)
		pFadaCaida->setOlhaEsquerda(true);
	else
		pFadaCaida->setOlhaEsquerda(false);

	pFadaCaida->move(pFadaCaida->getVelocidadeX() * deltaTime, pFadaCaida->getVelocidadeY() * deltaTime);

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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pCurandeira->getPodePular())
	{
		pCurandeira->setPodePular(false);
		pCurandeira->setVelocidadeY(-sqrtf(2.0f * 981.f * pCurandeira->getAlturaPulo()));
	}
	pCurandeira->setVelocidadeY(pCurandeira->getVelocidadeY() + 981.f * deltaTime);

	if (pCurandeira->getVelocidadeX() < 0)
		pCurandeira->setOlhaEsquerda(true);
	else
		pCurandeira->setOlhaEsquerda(false);
	pCurandeira->move(pCurandeira->getVelocidadeX() * deltaTime, pCurandeira->getVelocidadeY() * deltaTime);
	updateAtaqueCurandeira();
}


void InputManager::setFadaCaida(FadaCaida* pFada)
{
	pFadaCaida = pFada;
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
