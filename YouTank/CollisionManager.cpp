#include "stdafx.h"
#include "CollisionManager.h"
#include "Global.h"


CollisionManager::CollisionManager():
	pFadaCaida(NULL),
	pCurandeira(NULL),
	pWindow(NULL),
	pGraphic(NULL)
{
	timerMAX = 300.f;
	timer = timerMAX;
	timerCurandeira = timerMAX;
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::verificaColisaoFadaCaida(Entidade& entidade)
{
	/*==================COLISOES FADA CAIDA=====================*/
	/*															*/
	/*	ADMINISTRA AS COLISOES DO JOGADOR 1					    */
	/*  Utiliza-se de conceitos de geometria analitica para		*/
	/*  calcular se dois corpos se intersectam ou não,			*/
	/*  verificando a distancia entre seus centros de massa.	*/
	/*==========================================================*/

	sf::Vector2f outraPosicao = entidade.getPosition();
	sf::Vector2f outraMetadeTam = (entidade.getSize()/ 2.f);
	sf::Vector2f jogadorPosicao = pFadaCaida->getPosition();
	sf::Vector2f jogadorMetadeTam = (pFadaCaida->getSize() / 2.f);

	//calcula as distancias entre seus centros de massa
	float deltaX = outraPosicao.x - jogadorPosicao.x;
	float deltaY = outraPosicao.y - jogadorPosicao.y;

	//analisa a diferenca entre o delta e a menor distancia possivel antes de colidirem
	float intersectX = abs(deltaX) - (outraMetadeTam.x + jogadorMetadeTam.x);
	float intersectY = abs(deltaY) - (outraMetadeTam.y + jogadorMetadeTam.y);

	//verifica se houve interseccao
	if (intersectX < 0.f && intersectY < 0.f && entidade.getId() != ID_ORBE)
	{
		//verifica em qual direcao ocorreu a colisao
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				pFadaCaida->move(intersectX , 0.0f);
				
				pFadaCaida->setDirecao_x(1.0f);
				pFadaCaida->setDirecao_y(0.0f);
			}
			else
			{
				pFadaCaida->move(-intersectX * 1.0f , 0.0f);

				pFadaCaida->setDirecao_x(-1.0f);
				pFadaCaida->setDirecao_y(0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				pFadaCaida->move(0.0f,intersectY * 1.0f );
		
				pFadaCaida->setDirecao_x(0.0f);
				pFadaCaida->setDirecao_y(1.0f);
			}
			else
			{
				pFadaCaida->move(0.0f, -intersectY * 1.0f );
	
				pFadaCaida->setDirecao_x(0.0f);
				pFadaCaida->setDirecao_y(-1.0f);
			}
		}
		pFadaCaida->naColisao();
		
		//colisao com o favo de mel, diminui a velocidade do jogador
		if (entidade.getId() == ID_FAVOMEL)
			pFadaCaida->setVelocidadeX(pFadaCaida->getVelocidadeX() * 0.5f);
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
	if (pFadaCaida->getBounds().left < 0.f)
	{
		pFadaCaida->setPosition(pFadaCaida->getBounds().width / 2.f, pFadaCaida->getBounds().top + pFadaCaida->getBounds().width / 2.f);
	}
	if (pFadaCaida->getBounds().left + pFadaCaida->getBounds().width > pWindow->getSize().x)
	{
		pFadaCaida->setPosition(pWindow->getSize().x - pFadaCaida->getBounds().width / 2.f, pFadaCaida->getBounds().top + pFadaCaida->getBounds().width / 2.f);
	}

	//Colisão com a borda inferior da janela
	if (pFadaCaida->getBounds().top + pFadaCaida->getBounds().height > pWindow->getSize().y)
	{
		pFadaCaida->setPosition(pFadaCaida->getPosition().x, pWindow->getSize().y - pFadaCaida->getBounds().height / 2);
	}

	//Colisão com a borda superior da janela
	else if (pFadaCaida->getBounds().top < 0.f)
	{
		pFadaCaida->setPosition(pFadaCaida->getPosition().x, pFadaCaida->getBounds().height / 2.f);
		pFadaCaida->setDirecao_x(0.0f);
		pFadaCaida->setDirecao_y(-1.0f);
		pFadaCaida->naColisao();
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

bool CollisionManager::updateColisoesFadaCaida(Entidade* pEn)
{
	return verificaColisaoFadaCaida(*pEn);
}

bool CollisionManager::updateCombate(Entidade* pOrbe, Entidade* pInimigo)
{
	return pOrbe->intersecta(static_cast<Ente*>(pInimigo));
}

void CollisionManager::updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma)
{

	/*===============COLISOES INIMIGO/PLATAFORMA================*/
	/*															*/
	/*	ADMINISTRA AS COLISOES DO INIMIGO COM A PLATAFORMA	    */
	/*  Utiliza-se de conceitos de geometria analitica para		*/
	/*  calcular se dois corpos se intersectam ou não,			*/
	/*  verificando a distancia entre seus centros de massa.	*/
	/*==========================================================*/

	sf::Vector2f outraPosicao = plataforma->getPosition();
	sf::Vector2f outraMetadeTam = (plataforma->getSize() / 2.f);
	sf::Vector2f Posicao = inimigo.getPosition();
	sf::Vector2f MetadeTam = (inimigo.getSize() / 2.f);

	//calcula as distancias entre seus centros de massa
	float deltaX = outraPosicao.x - Posicao.x;
	float deltaY = outraPosicao.y - Posicao.y;

	//analisa a diferenca entre o delta e a menor distancia possivel antes de colidirem
	float intersectX = abs(deltaX) - (outraMetadeTam.x + MetadeTam.x);
	float intersectY = abs(deltaY) - (outraMetadeTam.y + MetadeTam.y);

	//verifica se houve interseccao
	if (intersectX < 0.f && intersectY < 0.f)
	{
		//verifica em qual direcao ocorreu a colisao
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
	/*=====================SAIU DA TELA=========================*/
	/*															*/
	/*	VERIFICA SE A ENTIDADE SAIU DOS LIMITES DA TELA		    */
	/*==========================================================*/
	if (entidade->getBounds().top + entidade->getBounds().height < 0.f ||
		entidade->getBounds().top + entidade->getBounds().height > pGraphic->getWindow()->getSize().y ||
		entidade->getPosition().x > pGraphic->getWindow()->getSize().x ||
		entidade->getPosition().x + entidade->getBounds().width < 0.f)
	{
		return true;
	}
	return false;
}

bool CollisionManager::verificaContatoFadaCaida(Entidade* entidade)
{
	/*===================VERIFICA CONTATO=======================*/
	/*															*/
	/*	VERIFICA O CONTATO DA FADA COM A ENTIDADE			    */
	/*==========================================================*/
	bool intersecta = pFadaCaida->intersecta(static_cast<Ente*>(entidade));
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

bool CollisionManager::verificaContatoCurandeira(Entidade* entidade)
{
	/*===================VERIFICA CONTATO=======================*/
	/*															*/
	/*	VERIFICA O CONTATO DA CURANDEIRA COM A ENTIDADE		    */
	/*==========================================================*/
	bool intersecta = pCurandeira->intersecta(static_cast<Ente*>(entidade));
	if (timerCurandeira < timerMAX || intersecta == false)
	{
		timerCurandeira += 1.f;
		return false;
	}
	else
	{
		timerCurandeira = 0.f;
		return intersecta;
	}
}

void CollisionManager::setFadaCaida(FadaCaida* pJ1)
{
	if(pJ1)
		pFadaCaida = pJ1;
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






