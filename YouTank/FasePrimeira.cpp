#include "stdafx.h"
#include "FasePrimeira.h"
#include "Global.h"

void FasePrimeira::initInimigo()
{
	spawnTimerMAX = 100.f;
	spawnTimer = spawnTimerMAX;
	ferraoTimerMAX = 500.f;
	ferraoTimer = ferraoTimerMAX;
	abelhasMAX = 10;
	contaAbelhas = 0;
	contaCogu = 0;
	cogumelosMAX = rand() % 3 + 2;
}

FasePrimeira::FasePrimeira():
	Fase(),
	background("Imagens/floresta.png", 2.f)
{
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);
	collisionManager.setJogador(pJogador);
}

FasePrimeira::~FasePrimeira()
{
	
}

void FasePrimeira::spawnAbelhas()
{
	//timer
	if (spawnTimer < spawnTimerMAX)
		spawnTimer += 5.f;

	else if (contaAbelhas < abelhasMAX)
	{
		Abelha* inim = new Abelha();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		spawnTimer = 0.f;
	}
}

void FasePrimeira::spawnCogumelo()
{
	if (contaCogu < cogumelosMAX)
	{
		Cogumelo* cogu = new Cogumelo();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(cogu));
		contaCogu++;
	}

	
}

void FasePrimeira::spawnPlataforma()
{

	Plataforma* plat = new Plataforma();
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat));

	Plataforma* plat2 = new Plataforma(300.f, 20.f, 100.f, 580.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat2));

	Plataforma* plat3 = new Plataforma(300.f, 20.f, 300.f, 500.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat3));

	Plataforma* plat4 = new Plataforma(300.f, 20.f, 500.f, 420.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat4));

	Plataforma* plat5 = new Plataforma(300.f, 20.f, 300.f, 340.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat5));

	Plataforma* plat6 = new Plataforma(300.f, 20.f, 500.f, 260.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat6));

	Plataforma* plat7 = new Plataforma(300.f, 20.f, 300.f, 180.f);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat7));
}

void FasePrimeira::updateMovimento()
{
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_ABELHA://move inimigos
		{
			listaEntidades.operator[](i)->persegue(pJogador->getPosition().x, pJogador->getPosition().y);
		}
		break;
		case ID_ORBE://move projeteis
		{
			listaEntidades.operator[](i)->updateOrbe();
		}
		break;
		case ID_FERRAO://move ferrao
		{
			listaEntidades.operator[](i)->updateFerrao();
		}
		break;
		}
	}
}

void FasePrimeira::updateColisoes()
{
	int i;
	for (i = 0; i < listaEntidades.getTamanho(); i++) 
	{
		
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA://update colisoes com plataforma
		{
			collisionManager.updateColisoes(listaEntidades.operator[](i));
		}
		break;
		case ID_ABELHA://update colisoes do player com inimigos e janela
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				pJogador->tomarDano(listaEntidades.operator[](i)->getDano());
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
		{	//update colisoes do projetil com janela
			if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_FERRAO:
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				pJogador->tomarDano(10);
				listaEntidades.operator[](i)->setShowing(false);
			}
		}

		}
	}
}

void FasePrimeira::updateCombate()
{
	int i, j;
	bool colidiu = false;
	unsigned counter = 0;
	for (i = 0; !colidiu && i < listaEntidades.getTamanho(); i++)
	{

		if (listaEntidades.operator[](counter)->getId() == ID_ORBE)
		{
			if (collisionManager.updateCombate(listaEntidades.operator[](counter), static_cast<Entidade*>(&abelha_rainha)))
			{
				listaEntidades.operator[](counter)->setShowing(false);
				abelha_rainha.tomarDano(pJogador->getDano());
			}
			unsigned counter_2 = 0;
			for (j = 0; !colidiu && j < listaEntidades.getTamanho(); j++)
			{
				if (listaEntidades.operator[](counter_2)->getId() == ID_ABELHA)
				{
					if (collisionManager.updateCombate(listaEntidades.operator[](counter), listaEntidades.operator[](counter_2)))
					{
						listaEntidades.operator[](counter_2)->setShowing(false);
						listaEntidades.operator[](counter)->setShowing(false);
						contaAbelhas--;
						colidiu = true;
					}
				}
				counter_2++;
			}
			
		}
		counter++;
	}
	if (abelha_rainha.emFuria())
	{
		spawnAbelhas();
		abelha_rainha.curaVida(3);
	}

}

void FasePrimeira::updateBoss()
{
	abelha_rainha.update();
	if (ferraoTimer < ferraoTimerMAX)
		ferraoTimer += 5.f;
	else
	{
		Ferrao* ferrao = new Ferrao(abelha_rainha.getPosition().x, abelha_rainha.getPosition().y,
									pJogador->getPosition().x, pJogador->getPosition().y);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(ferrao));
		ferraoTimer = 0.f;
	}
		

}

void FasePrimeira::update()
{
	
	updateColisoes();
	limpeza();
	spawnCogumelo();
	updateMovimento();
	updateCombate();
	
	pJogador->update();
	updateBoss();
	
}


void FasePrimeira::renderFasePrimeira()
{
	background.renderBackground();
	
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getShowing())
		{
			listaEntidades.operator[](i)->render();
		}
		abelha_rainha.renderAbelhaRainha();
	}
}
