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

void FasePrimeira::updateFasePrimeira()
{
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_POTEMEL:
		{
			//update contato com o pote de mel, objetivo que dá pontos
			if (collisionManager.verificaContatoFadaCaida(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				contaPoteMel--;

			}
		}
		break;
		case ID_PLATAFORMA:
		{
			//movimenta as plataformas para cima e para baixo
			if (listaEntidades.operator[](i)->getPosition().y > 550)
				listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() * -1);
			else if (listaEntidades.operator[](i)->getPosition().y < 100)
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
	updateFasePrimeira();
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
	{
		pCurandeira->renderBarraVida();
		pCurandeira->render();
	}
		
}
