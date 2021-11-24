#include "stdafx.h"
#include "CollisionManager.h"
#include "Global.h"


CollisionManager::CollisionManager():
	pWindow(NULL),
	pGraphic(NULL)
{

}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::verificaColisaoJogador(Entidade& entidade, Jogador& jogador)
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
	sf::Vector2f jogadorPosicao = jogador.getPosition();
	sf::Vector2f jogadorMetadeTam = (jogador.getSize() / 2.f);

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
				jogador.move(intersectX , 0.0f);
				
				jogador.setDirecao_x(1.0f);
				jogador.setDirecao_y(0.0f);
			}
			else
			{
				jogador.move(-intersectX * 1.0f , 0.0f);

				jogador.setDirecao_x(-1.0f);
				jogador.setDirecao_y(0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				jogador.move(0.0f,intersectY * 1.0f );
		
				jogador.setDirecao_x(0.0f);
				jogador.setDirecao_y(1.0f);
			}
			else
			{
				jogador.move(0.0f, -intersectY * 1.0f );
	
				jogador.setDirecao_x(0.0f);
				jogador.setDirecao_y(-1.0f);
			}
		}
		jogador.naColisao();
		
		//colisao com o favo de mel, diminui a velocidade do jogador
		if (entidade.getId() == ID_FAVOMEL)
			jogador.setVelocidadeX(jogador.getVelocidadeX() * 0.5f);
		return true;
	}
	
	return false;
}

void CollisionManager::updateColisoesJanela(Jogador* pJogador)
{
	if (pJogador)
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
			pJogador->naColisao();
		}
	}
}

bool CollisionManager::updateColisoesJogador(Entidade* pEn, Jogador* pJogador)
{
	return verificaColisaoJogador(*pEn, *pJogador);
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
				inimigo.setVelocidadeX(inimigo.getVelocidadeX()*-1);
			}
			else
			{
				inimigo.move(-intersectX, 0.0f);
				inimigo.setVelocidadeX(inimigo.getVelocidadeX() * -1);
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

bool CollisionManager::verificaContatoJogador(Entidade* entidade, Jogador* pJogador)
{
	/*===================VERIFICA CONTATO=======================*/
	/*															*/
	/*	VERIFICA O CONTATO DA FADA COM A ENTIDADE			    */
	/*==========================================================*/
	return pJogador->intersecta(static_cast<Ente*>(entidade));
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






