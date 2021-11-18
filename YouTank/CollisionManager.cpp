#include "stdafx.h"
#include "CollisionManager.h"
#include "Global.h"


CollisionManager::CollisionManager():
	pJogador(NULL),
	pWindow(NULL),
	pGraphic(NULL)
{
	direcao.x = 0.0f;
	direcao.y = 0.0f;
	
}

CollisionManager::~CollisionManager()
{
}


bool CollisionManager::verificaColisao(Entidade& entidade, sf::Vector2f& direcao, float push)
{
	sf::Vector2f outraPosicao = entidade.getPosition();
	sf::Vector2f outraMetadeTam = (entidade.getSize()/ 2.f);
	sf::Vector2f jogadorPosicao = pJogador->getPosition();
	sf::Vector2f jogadorMetadeTam = (pJogador->getSize() / 2.f);

	float deltaX = outraPosicao.x - jogadorPosicao.x;
	float deltaY = outraPosicao.y - jogadorPosicao.y;

	float intersectX = abs(deltaX) - (outraMetadeTam.x + jogadorMetadeTam.x);
	float intersectY = abs(deltaY) - (outraMetadeTam.y + jogadorMetadeTam.y);

	if (intersectX < 0.f && intersectY < 0.f && entidade.getId() != ID_PROJETIL)
	{
		push = std::min(std::max(push, 0.f), 1.f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				pJogador->move(intersectX * (1.0f - push), 0.0f);
				entidade.move(-intersectX * push, 0.0f);
				
				direcao.x = 1.0f;
				direcao.y = 0.0f;
			}
			else
			{
				pJogador->move(-intersectX * (1.0f - push), 0.0f);
				entidade.move(intersectX * push, 0.0f);

				direcao.x = -1.0f;
				direcao.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				pJogador->move(0.0f,intersectY * (1.0f - push));
				entidade.move(0.0f ,-intersectY * push);

				direcao.x = 0.0f;
				direcao.y = 1.0f;
			}
			else
			{
				pJogador->move(0.0f, -intersectY * (1.0f - push));
				entidade.move(0.0f, intersectY * push);

				direcao.x = 0.0f;
				direcao.y = -1.0f;
			}
		}
		if (entidade.getId() == ID_INIMIGO)
		{
	
		}
		else if (entidade.getId() == ID_PLATAFORMA)
		{
			
		}
		pJogador->naColisao(direcao);
		return true;
	}
	return false;
}

void CollisionManager::colidindoComInimigo(Entidade entidade)
{
	
}

void CollisionManager::colidindoComPlataforma()
{
	
}

void CollisionManager::updateColisoesJanela()
{
	//Colisão com a borda esquerda da janela
	if (pJogador->getBounds().left < 0.f)
	{
		pJogador->setPosition(pJogador->getBounds().width / 2.f, pJogador->getBounds().top + pJogador->getBounds().width/2.f);
	}
	if (pJogador->getBounds().left + pJogador->getBounds().width > pWindow->getSize().x)
	{
		pJogador->setPosition(pWindow->getSize().x - pJogador->getBounds().width/2.f, pJogador->getBounds().top + pJogador->getBounds().width/2.f);
	}

	//Colisão com a borda inferior da janela
	if (pJogador->getBounds().top + pJogador->getBounds().height > pWindow->getSize().y)
	{
		pJogador->setPosition(pJogador->getPosition().x, pWindow->getSize().y - pJogador->getBounds().height/2);
	}

	//Colisão com a borda superior da janela
	else if (pJogador->getBounds().top < 0.f)
	{
		pJogador->setPosition(pJogador->getPosition().x, pJogador->getBounds().height / 2.f);
		direcao.x = 0.0f;
		direcao.y = -1.f;
		pJogador->naColisao(direcao);
	}
}

bool CollisionManager::updateColisoes(Entidade* pEn)
{
	updateColisoesJanela();
	return verificaColisao(*pEn, direcao, 0.0f);
}

bool CollisionManager::updateCombate(Entidade* pProjetil, Entidade* pInimigo)
{
	if (pProjetil->getBounds().intersects(pInimigo->getBounds()))
		return true;
	else
		return false;
}

bool CollisionManager::entidadeSaiuDaTela(Entidade* entidade)
{
	if (entidade->getBounds().top + entidade->getBounds().height < 0.f ||
		entidade->getBounds().top + entidade->getBounds().height > pGraphic->getWindow()->getSize().y ||
		entidade->getPosition().x > pGraphic->getWindow()->getSize().x ||
		entidade->getPosition().x + entidade->getBounds().width < 0.f)
	{
		return true;
	}
	return false;
}


void CollisionManager::setJogador(Jogador* pJ1)
{
	if(pJ1)
		pJogador = pJ1;
	else
		std::cout << "ERROR::COLLISIONMANAGER::SETJOGADOR::Ponteiro Nulo" << std::endl;
}

void CollisionManager::setGraphicManager(GraphicManager* pGM)
{
	if (pGM)
	{
		pGraphic = pGM;
		pWindow = pGraphic->getWindow();
	}
	else
		std::cout << "ERROR::COLLISIONMANAGER::SETGRAPHICMANAGER::Ponteiro Nulo" << std::endl;
}





