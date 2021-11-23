#include "stdafx.h"
#include "FasePrimeira.h"
#include "Global.h"

FasePrimeira::FasePrimeira() :
	Fase()
{
	Ente::pLista = &listaEntidades;
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);
	obstaculosMAX = rand() % 3 + 3;
	contaPoteMel = 0;
}

FasePrimeira::~FasePrimeira()
{
	if (pCurandeira != NULL)
		delete pCurandeira;
}

void FasePrimeira::spawnCurandeira()
{
	/*========================CURANDEIRA========================*/
	/*															*/
	/*	CRIA CURANDEIRA										    */
	/*	Curandeira é o jogador dois, cura o jogador principal	*/
	/*==========================================================*/
	pCurandeira = new Curandeira();
	collisionManager.setCurandeira(pCurandeira);
}

void FasePrimeira::spawnCogumelo()
{
	/*========================COGUMELOS=========================*/
	/*															*/
	/*	CRIA COGUMELOS										    */
	/*	Cogumelos andam pra direita e pra esquerda				*/
	/*==========================================================*/

	cogumelosMAX = rand() % 5;

	if (contaCogu < cogumelosMAX)
	{
		Cogumelo* cogu = new Cogumelo();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(cogu));
		contaCogu++;
	}
}

void FasePrimeira::spawnAbelhas()
{
	/*=========================ABELHAS==========================*/
	/*															*/
	/*	CRIA ABELHAS										    */
	/*	Abelhas perseguem o jogador, dão dano ou pontos			*/
	/*==========================================================*/

	//timer
	if (spawnTimer < spawnTimerMAX)
		spawnTimer += 5;

	else if (contaAbelhas < abelhasMAX)
	{
		Abelha* inim = new Abelha(1);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		spawnTimer = 0;
	}
}

void FasePrimeira::spawnPoteMel()
{

	/*=====================POTES DE MEL=========================*/
	/*															*/
	/*	CRIA POTES DE MEL RANDOMICAMENTE					    */
	/*	Potes de mel dão ao player pontos para o ranking		*/
	/*==========================================================*/

	if (contaPoteMel < 1)
	{
		PoteMel* pote = new PoteMel();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(pote));
		contaPoteMel++;
	}
}


void FasePrimeira::spawnPlataforma()
{
	/*=====================PLATAFORMAS==========================*/
	/*															*/
	/*	CRIA PLATAFORMAS OU FAVOS DE MEL RANDOMICAMENTE			*/
	/*==========================================================*/


	//chao principal
	Plataforma* plat = new Plataforma();
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat));

	//favo mel principal
	FavoMel* favo = new FavoMel(100.f, 20.f, 60.f, 600.f);
	favo->setVelocidadeY(0.0f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(favo));

	//plataformas ou favos de mel ao longo do eixo x na fase
	int random;
	int contaPlat = 0;
	for (int i = 180; i <= 1140; i += 120)
	{
		random = rand() % 2;
		if (random || contaPlat > 5)
		{
			FavoMel* favo1 = new FavoMel(100.f, 20.f, (float) i, static_cast<float>(rand() % 400 + 100));
			listaEntidades.incluaEntidade(static_cast<Entidade*>(favo1));
		}
		else
		{
			Plataforma* plat1 = new Plataforma(100.f, 20.f, (float) i, static_cast<float>(rand() % 400 + 100));
			listaEntidades.incluaEntidade(static_cast<Entidade*>(plat1));
			contaPlat++;
		}
			
	}
}

void FasePrimeira::spawnObstaculos()
{
	/*=====================OBSTACULOS===========================*/
	/*															*/
	/*  CRIA OBSTACULOS PELA FASE DE FORMA RANDOMICA			*/
	/*==========================================================*/
	if (contaObstaculos < obstaculosMAX)
	{
		Espinhos* espinhos = new Espinhos((float)(rand() % 1180 + 100), 620.f);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(espinhos));
		contaObstaculos++;
	}

}

void FasePrimeira::updateMovimento()
{
	/*========================MOVIMENTACAO======================*/
	/*															*/
	/*	ADMINISTRA OS MOVIMENTOS DAS ENTIDADES				    */
	/*==========================================================*/
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA:
		{
			//movimenta as plataformas para cima e para baixo
			if (listaEntidades.operator[](i)->getPosition().y > 550)
				listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() * -1);
			else if(listaEntidades.operator[](i)->getPosition().y < 100)
				listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() * -1);
			listaEntidades.operator[](i)->movePlataforma();

		}
		break;
		case ID_FAVOMEL:
		{
			//movimenta os favos de mel para cima e para baixo
			if (listaEntidades.operator[](i)->getPosition().y > 550)
				listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() * -1);
			else if (listaEntidades.operator[](i)->getPosition().y < 100)
				listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() * -1);
			listaEntidades.operator[](i)->movePlataforma();
		}
		break;
		case ID_ABELHA:
		{
			//move as abelhas na direcao do jogador atraves da funcao persegue
			listaEntidades.operator[](i)->persegue(pFadaCaida->getPosition().x, pFadaCaida->getPosition().y);
		}
		break;
		case ID_ORBE:
		{
			//move orbe de dano
			listaEntidades.operator[](i)->updateOrbe();
		}
		break;
		case ID_ORBECURA: 
		{
			//move orbe de cura
			listaEntidades.operator[](i)->updateOrbeCura();
		}
		break;
		case ID_FERRAO:
		{
			//move ferrao
			listaEntidades.operator[](i)->updateFerrao();
		}
		break;
		case ID_COGUMELO:
		{
			//move cogumelos
			listaEntidades.operator[](i)->move(listaEntidades.operator[](i)->getVelocidadeX(), listaEntidades.operator[](i)->getVelocidadeY());
			listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() + 1.f);
			listaEntidades.operator[](i)->updateAnimacao();
		}
		break;
		}
	}
}

void FasePrimeira::updateColisoes()
{
	/*========================COLISOES==========================*/
	/*															*/
	/*	ADMINISTRA AS EVENTUAIS COLISOES					    */
	/*==========================================================*/

	collisionManager.updateColisoesJanela(); //colisoes da janela
	int i;
	for (i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA:
		{
			//update colisoes com plataforma
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
		}
		break;
		case ID_FAVOMEL:
		{
			//update colisoes com favor de mel
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
		}
		case ID_ABELHA:
		{
			//update colisoes das abelhas com jogador e janela
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(listaEntidades.operator[](i)->getDano());
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
				
			}
			else if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
			}

		}
		break;
		case ID_ORBE:
		{	
			//update colisoes da orbe de dano com janela
			if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_ORBECURA:
		{   
			//update colisoes do orbe de cura com jogador e janela
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				if (pCurandeira)
				{
					pFadaCaida->receberCura(pCurandeira->getCura());
					listaEntidades.operator[](i)->setShowing(false);
				}
			}
			else if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		case ID_FERRAO:
		{
			//update colisoes do ferrao
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_COGUMELO:
		{
			//update colisoes do cogumelo
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				//se o jogador pular na cabeca do cogumelo, nao toma dano
				if (!pFadaCaida->getColisaoBot())
					pFadaCaida->tomarDano(5);
				listaEntidades.operator[](i)->setShowing(false);
				contaCogu--;
			}
		}
		break;
		case ID_ESPINHOS:
		{
			//update colisoes com espinho, se estiver em contato o jogador sofre dano
			if (collisionManager.verificaContatoFadaCaida(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(3);
			}
		}
		break;
		case ID_PEDRA:
		{
			//update colisoes pedra, obstaculo que não causa dano
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
		}
		break;
		case ID_POTEMEL:
		{
			//update contato com o pote de mel, objetivo que dá pontos
			if (collisionManager.verificaContatoFadaCaida(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				contaPoteMel--;
			
			}
				
		}
		default:
			break;
		}
		
	
	}
}

void FasePrimeira::updateCombate()
{
	/*==========================COMBATE=========================*/
	/*															*/
	/*	ADMINISTRA O COMBATE DO JOGADOR NA FASE				    */
	/*  Mais precisamente as colisoes dos orbes da fada caida   */
	/*==========================================================*/
	int i, j;
	bool colidiu = false;
	for (i = 0; !colidiu && i < listaEntidades.getTamanho(); i++)
	{

		if (listaEntidades.operator[](i)->getId() == ID_ORBE)
		{
			
			for (j = 0; !colidiu && j < listaEntidades.getTamanho(); j++)
			{
				if (listaEntidades.operator[](j)->getId() == ID_ABELHA)
				{
					if (collisionManager.updateCombate(listaEntidades.operator[](i), listaEntidades.operator[](j)))
					{
						listaEntidades.operator[](j)->setShowing(false);
						listaEntidades.operator[](i)->setShowing(false);
						contaAbelhas--;
						colidiu = true;
					}
				}
				else if (listaEntidades.operator[](j)->getId() == ID_COGUMELO)
				{
					if (collisionManager.updateCombate(listaEntidades.operator[](i), listaEntidades.operator[](j)))
					{
						listaEntidades.operator[](j)->setShowing(false);
						listaEntidades.operator[](i)->setShowing(false);
						contaCogu--;
						colidiu = true;
					}
				}
			}

		}
	}
}

void FasePrimeira::updateInimigoPlataforma()
{
	/*================GRAVIDADE NOS INIMIGOS====================*/
	/*															*/
	/*	ADMINISTRA A COLISAO ENTRE OS INIMIGOS E PLATAFORMA		*/
	/*  Na pratica, serve para dar o efeito de gravidade.	    */
	/*==========================================================*/

	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getId() == ID_PLATAFORMA || listaEntidades.operator[](i)->getId() == ID_FAVOMEL)
		{
			for (int j = 0; j < listaEntidades.getTamanho(); j++)
				if (listaEntidades.operator[](j)->getId() == ID_COGUMELO)
					collisionManager.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));
		}
	}
}



void FasePrimeira::update()
{

	updateColisoes();
	limpeza();
	spawnCogumelo();
	spawnAbelhas();
	spawnObstaculos();
	spawnPoteMel();
	updateMovimento();
	updateCombate();
	updateInimigoPlataforma();
	pFadaCaida->update();
	if (pCurandeira != NULL)
		pCurandeira->update();


}


void FasePrimeira::renderFasePrimeira()
{
	background.render();

	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getShowing())
		{
			listaEntidades.operator[](i)->render();
		}
		
	}
	pFadaCaida->renderBarraVida();
	pFadaCaida->render();

	if (pCurandeira != NULL)
		pCurandeira->render();
}

void FasePrimeira::setFadaCaida(FadaCaida* pJ)
{
	if (pJ)
	{
		pFadaCaida = pJ;
		collisionManager.setFadaCaida(pFadaCaida);
		
	}
	else
		std::cout << "ERRO::FASEPRIMEIRA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
}

Curandeira* FasePrimeira::getCurandeira() const
{
	return pCurandeira;
}
