#include "stdafx.h"
#include "CollisionManager.h"
#include "Global.h"


CollisionManager::CollisionManager():
	pJogador(NULL),
	pCurandeira(NULL),
	pWindow(NULL),
	pGraphic(NULL)
{
	timerMAX = 300.f;
	timer = timerMAX;
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::verificaColisaoJogador(Entidade& entidade)
{
	sf::Vector2f outraPosicao = entidade.getPosition();
	sf::Vector2f outraMetadeTam = (entidade.getSize()/ 2.f);
	sf::Vector2f jogadorPosicao = pJogador->getPosition();
	sf::Vector2f jogadorMetadeTam = (pJogador->getSize() / 2.f);

	float deltaX = outraPosicao.x - jogadorPosicao.x;
	float deltaY = outraPosicao.y - jogadorPosicao.y;

	float intersectX = abs(deltaX) - (outraMetadeTam.x + jogadorMetadeTam.x);
	float intersectY = abs(deltaY) - (outraMetadeTam.y + jogadorMetadeTam.y);

	if (intersectX < 0.f && intersectY < 0.f && entidade.getId() != ID_ORBE)
	{

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				pJogador->move(intersectX , 0.0f);
				
				pJogador->setDirecao_x(1.0f);
				pJogador->setDirecao_y(0.0f);
			}
			else
			{
				pJogador->move(-intersectX * 1.0f , 0.0f);

				pJogador->setDirecao_x(-1.0f);
				pJogador->setDirecao_y(0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				pJogador->move(0.0f,intersectY * 1.0f );
		
				pJogador->setDirecao_x(0.0f);
				pJogador->setDirecao_y(1.0f);
			}
			else
			{
				pJogador->move(0.0f, -intersectY * 1.0f );
	
				pJogador->setDirecao_x(0.0f);
				pJogador->setDirecao_y(-1.0f);
			}
		}
		pJogador->naColisao();
		return true;
	}
	return false;
}

void CollisionManager::updateColisoesJanela()
{
	updateColisoesJanelaJ1();
	if(pCurandeira!=NULL)
		updateColisoesJanelaJ2();
}

void CollisionManager::updateColisoesJanelaJ1()
{
	//Colisão com a borda esquerda da janela
	if (pJogador->getBounds().left < 0.f)
	{
		pJogador->setPosition(pJogador->getBounds().width / 2.f, pJogador->getBounds().top + pJogador->getBounds().width / 2.f);
	}
	if (pJogador->getBounds().left + pJogador->getBounds().width > pWindow->getSize().x)
	{
		pJogador->setPosition(pWindow->getSize().x - pJogador->getBounds().width / 2.f, pJogador->getBounds().top + pJogador->getBounds().width / 2.f);
	}

	//Colisão com a borda inferior da janela
	if (pJogador->getBounds().top + pJogador->getBounds().height > pWindow->getSize().y)
	{
		pJogador->setPosition(pJogador->getPosition().x, pWindow->getSize().y - pJogador->getBounds().height / 2);
	}

	//Colisão com a borda superior da janela
	else if (pJogador->getBounds().top < 0.f)
	{
		pJogador->setPosition(pJogador->getPosition().x, pJogador->getBounds().height / 2.f);
		pJogador->setDirecao_x(0.0f);
		pJogador->setDirecao_y(-1.0f);
	}
}

void CollisionManager::updateColisoesJanelaJ2()
{
	//Colisão com a borda esquerda da janela
	if (pCurandeira->getBounds().left < 0.f)
	{
		pCurandeira->setPosition(pCurandeira->getBounds().width / 2.f, pCurandeira->getBounds().top + pCurandeira->getBounds().width / 2.f);
	}
	if (pCurandeira->getBounds().left + pCurandeira->getBounds().width > pWindow->getSize().x)
	{
		pCurandeira->setPosition(pWindow->getSize().x - pCurandeira->getBounds().width / 2.f, pCurandeira->getBounds().top + pCurandeira->getBounds().width / 2.f);
	}

	//Colisão com a borda inferior da janela
	if (pCurandeira->getBounds().top + pCurandeira->getBounds().height + 100.f> pWindow->getSize().y)
	{
		pCurandeira->setPosition(pCurandeira->getPosition().x, pWindow->getSize().y - pCurandeira->getBounds().height / 2 - 100.f);
	}

	//Colisão com a borda superior da janela
	else if (pCurandeira->getBounds().top < 0.f)
	{
		pCurandeira->setPosition(pCurandeira->getPosition().x, pCurandeira->getBounds().height / 2.f);
	}
}

bool CollisionManager::updateColisoes(Entidade* pEn)
{
	updateColisoesJanela();
	return verificaColisaoJogador(*pEn);
}

bool CollisionManager::updateCombate(Entidade* pOrbe, Entidade* pInimigo)
{
	return pOrbe->intersecta(static_cast<Ente*>(pInimigo));
}

void CollisionManager::updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma)
{
	sf::Vector2f outraPosicao = plataforma->getPosition();
	sf::Vector2f outraMetadeTam = (plataforma->getSize() / 2.f);
	sf::Vector2f Posicao = inimigo.getPosition();
	sf::Vector2f MetadeTam = (inimigo.getSize() / 2.f);

	float deltaX = outraPosicao.x - Posicao.x;
	float deltaY = outraPosicao.y - Posicao.y;

	float intersectX = abs(deltaX) - (outraMetadeTam.x + MetadeTam.x);
	float intersectY = abs(deltaY) - (outraMetadeTam.y + MetadeTam.y);
	if (intersectX < 0.f && intersectY < 0.f)
	{
		
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				inimigo.move(intersectX, 0.0f);
				inimigo.setVelocidadeX(-2.f);
			}
			else
			{
				inimigo.move(-intersectX, 0.0f);
				inimigo.setVelocidadeX(2.f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				inimigo.move(0.0f, intersectY);
				inimigo.setVelocidadeY(0.0f);
			}
			else
			{
				inimigo.move(0.0f, -intersectY);
				inimigo.setVelocidadeY(0.0f);
			}
		}
	}
	
	if (inimigo.getBounds().left + inimigo.getBounds().width > pGraphic->getWindow()->getSize().x)
		inimigo.setVelocidadeX(-2.f);
	else if (inimigo.getBounds().left < 0.f)
		inimigo.setVelocidadeX(2.f);
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

bool CollisionManager::verificaContato(Entidade* entidade)
{
	bool intersecta = pJogador->intersecta(static_cast<Ente*>(entidade));
	if (timer < timerMAX || intersecta == false )
	{
		timer += 1.f;
		return false;
	}
	else
	{
		timer = 0.f;
		return intersecta;
	}
	
	
}

void CollisionManager::setJogador(Jogador* pJ1)
{
	if(pJ1)
		pJogador = pJ1;
	else
		std::cout << "ERROR::COLLISIONMANAGER::SETJOGADOR::Ponteiro Nulo" << std::endl;
}

void CollisionManager::setCurandeira(Curandeira* curandeira)
{
	pCurandeira = curandeira;
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






