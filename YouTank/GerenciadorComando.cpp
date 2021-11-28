#include "stdafx.h"
#include "GerenciadorComando.h"
using namespace Jogadores;
using namespace Fases;

GerenciadorComando::GerenciadorComando() :
	pCurandeira(NULL),
	pFadaCaida(NULL),
	pGrafico(NULL), 
	pFase(NULL)
{
	
}

GerenciadorComando::~GerenciadorComando()
{
	pCurandeira = NULL;
}

void GerenciadorComando::update(float deltaTime)
{
	updateFadaCaida(deltaTime);

	if(pCurandeira!=NULL)
		updateCurandeira(deltaTime);
}

void GerenciadorComando::updateAtaqueFadaCaida()
{
	pFadaCaida->updateAtaqueCooldown();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pFadaCaida->getPodeAtacar())
	{
		float dir_x = static_cast<float> (sf::Mouse::getPosition(*pGrafico->getWindow()).x);
		float dir_y = static_cast<float> (sf::Mouse::getPosition(*pGrafico->getWindow()).y);
		pFadaCaida->ataca(dir_x, dir_y);
	}
	
}

void GerenciadorComando::updateAtaqueCurandeira()
{
	pCurandeira->updateAtaqueCooldown();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pCurandeira->getPodeAtacar())
	{
		pCurandeira->curar(pFadaCaida->getPosition().x , pFadaCaida->getPosition().y, pCurandeira->getPosition().x, pCurandeira->getPosition().y);
	}
}

void GerenciadorComando::updateMousePos()
{
	mousePosWindow = sf::Mouse::getPosition(*pGrafico->getWindow());
}

void GerenciadorComando::updateFadaCaida(float deltaTime)
{
	
	pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() * 0.94f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() - pFadaCaida->getRapidez());

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() + pFadaCaida->getRapidez());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pFadaCaida->getPodePular())
	{
		pFadaCaida->pular();
		pFadaCaida->setPodePular(false);
	}
	
	if (pFadaCaida->getVelocidadeX() < 0)
		pFadaCaida->setOlhaEsquerda(true);
	else
		pFadaCaida->setOlhaEsquerda(false);
	static_cast<Jogador*>(pFadaCaida)->update(deltaTime);
	updateAtaqueFadaCaida();
}

void GerenciadorComando::updateCurandeira(float deltaTime)
{
	pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() * 0.98f);
	pCurandeira->setVelocidadeY(pCurandeira->getVelocidadeY() * 0.98f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() - pCurandeira->getRapidez());

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pCurandeira->setVelocidadeX(pCurandeira->getVelocidadeX() + pCurandeira->getRapidez());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pCurandeira->getPodePular())
	{
		pCurandeira->pular();
		pCurandeira->setPodePular(false);
	}
	

	if (pCurandeira->getVelocidadeX() < 0)
		pCurandeira->setOlhaEsquerda(true);
	else
		pCurandeira->setOlhaEsquerda(false);
	static_cast<Jogador*>(pCurandeira)->update(deltaTime);
	updateAtaqueCurandeira();

}


void GerenciadorComando::setFadaCaida(FadaCaida* pFada)
{
	pFadaCaida = pFada;
}

void GerenciadorComando::setGerenciadorGrafico(GerenciadorGrafico* pGG)
{
	pGrafico = pGG;
}

void GerenciadorComando::setFase(Fase* pF)
{
	if (pF)
		pFase = pF;
	else
		std::cout << "ERROR::INPUTMANAGER::SETFASE::Ponteiro Nulo";
}

const sf::Vector2i GerenciadorComando::getMousePos() const
{
	return mousePosWindow;
}

const bool GerenciadorComando::getPause() const 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return true;
	else
		return false;

}

void GerenciadorComando::setCurandeira(Curandeira* pC)
{
	pCurandeira = pC;
}
