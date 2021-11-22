#include "stdafx.h"
#include "FaseSegunda.h"
#include "Global.h"



FaseSegunda::FaseSegunda():
	Fase()
{
	Ente::pLista = &listaEntidades;
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);	
}

FaseSegunda::~FaseSegunda()
{
	if(pCurandeira != NULL)
		delete pCurandeira;
}

void FaseSegunda::spawnCurandeira()
{
	pCurandeira = new Curandeira();
	collisionManager.setCurandeira(pCurandeira);
}

void FaseSegunda::spawnCogumelo()
{
	cogumelosMAX = rand() % 5;

	if (contaCogu < cogumelosMAX)
	{
		Cogumelo* cogu = new Cogumelo();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(cogu));
		contaCogu++;
	}
}

void FaseSegunda::spawnAbelhas()
{
	//timer
	if (spawnTimer < spawnTimerMAX)
		spawnTimer += 5;

	else if (contaAbelhas < abelhasMAX)
	{
		Abelha* inim = new Abelha(2);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		spawnTimer = 0;
	}
}

void FaseSegunda::spawnPlataforma()
{
	//plataforma
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

void FaseSegunda::spawnObstaculos()
{
	if (contaObstaculos < obstaculosMAX)
	{
		Espinhos* espinhos = new Espinhos((float)(rand() % 1180+100), 620.f);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(espinhos));
		if (contaPedras < obstaculosMAX)
		{
			Pedra* pedra = new Pedra((float)(rand() % 170 + 180), 480.f);
			listaEntidades.incluaEntidade(static_cast<Entidade*>(pedra));
			contaPedras++;
		}
		if (contaPedras < obstaculosMAX)
		{
			Pedra* pedra2 = new Pedra((float)(rand() % 190 + 160), 160.f);
			listaEntidades.incluaEntidade(static_cast<Entidade*>(pedra2));
			contaPedras++;
		}
		
		contaObstaculos++;

	}

}

void FaseSegunda::updateMovimento()
{
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_ABELHA://move inimigos
		{
			listaEntidades.operator[](i)->persegue(pFadaCaida->getPosition().x, pFadaCaida->getPosition().y);
		}
		break;
		case ID_ORBE://move orbe de dano
		{
			listaEntidades.operator[](i)->updateOrbe();
		}
		break;
		case ID_ORBECURA: //move orbe de cura
		{
			listaEntidades.operator[](i)->updateOrbeCura();
		}
		break;
		case ID_FERRAO://move ferrao
		{
			listaEntidades.operator[](i)->updateFerrao();
		}
		break;
		case ID_COGUMELO:
		{
			listaEntidades.operator[](i)->move(listaEntidades.operator[](i)->getVelocidadeX(), listaEntidades.operator[](i)->getVelocidadeY());
			listaEntidades.operator[](i)->setVelocidadeY(listaEntidades.operator[](i)->getVelocidadeY() + 1.f);
			listaEntidades.operator[](i)->updateAnimacao();
		}
		break;
		}
	}
}

void FaseSegunda::updateColisoes()
{
	int i;
	collisionManager.updateColisoesJanela();
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
		{	//update colisoes do orbe de dano com janela
			if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_ORBECURA:
		{   //update colisoes do orbe de cura com janela
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
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
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(abelha_rainha.getDano());
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_COGUMELO:
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				if(!pFadaCaida->getColisaoBot())
					pFadaCaida->tomarDano(5);
				listaEntidades.operator[](i)->setShowing(false);
				contaCogu--;
			}
		}
		break;
		case ID_ESPINHOS:
		{
			if (collisionManager.verificaContatoFadaCaida(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(1);
			}
		}
		break;
		case ID_PEDRA:
		{
			collisionManager.updateColisoes(listaEntidades.operator[](i));
		}
		break;
		
		}
		if(collisionManager.verificaContatoFadaCaida(static_cast<Entidade*>(&abelha_rainha)))
			pFadaCaida->tomarDano(4);
		if (pCurandeira != NULL)
		{
			if (collisionManager.verificaContatoCurandeira(static_cast<Entidade*>(&abelha_rainha)))
				pFadaCaida->tomarDano(4);
		}
	}
}

void FaseSegunda::updateCombate()
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
				abelha_rainha.tomarDano(pFadaCaida->getDano());
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
				else if (listaEntidades.operator[](counter_2)->getId() == ID_COGUMELO)
				{
					if (collisionManager.updateCombate(listaEntidades.operator[](counter), listaEntidades.operator[](counter_2)))
					{
						listaEntidades.operator[](counter_2)->setShowing(false);
						listaEntidades.operator[](counter)->setShowing(false);
						contaCogu--;
						colidiu = true;
					}
				}
				counter_2++;
			}
			
		}
		counter++;
	}
	if (abelha_rainha.emFuria())
		spawnAbelhas();
}

void FaseSegunda::updateInimigoPlataforma()
{
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getId() == ID_PLATAFORMA)
		{
			for (int j = 0; j < listaEntidades.getTamanho(); j++)
				if (listaEntidades.operator[](j)->getId() == ID_COGUMELO)
					collisionManager.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));
		}
	}
}

void FaseSegunda::updateBoss()
{
	if(abelha_rainha.getShowing())
		abelha_rainha.update();
}

void FaseSegunda::update()
{
	
	updateColisoes();
	limpeza();
	spawnCogumelo();
	spawnObstaculos();
	updateMovimento();
	updateCombate();
	updateInimigoPlataforma();
	updateBoss();
	pFadaCaida->update();

	if(pCurandeira!=NULL)
		pCurandeira->update();
	
	
}


void FaseSegunda::renderFaseSegunda()
{
	background.render();
	
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getShowing())
		{
			listaEntidades.operator[](i)->render();
		}
		if(abelha_rainha.getShowing())
			abelha_rainha.renderAbelhaRainha();
	}
	pFadaCaida->renderBarraVida();
	pFadaCaida->render();

	if(pCurandeira!=NULL)
		pCurandeira->render();
}

void FaseSegunda::setFadaCaida(FadaCaida* pJ)
{
	if (pJ)
	{
		pFadaCaida = pJ;
		collisionManager.setFadaCaida(pFadaCaida);
		abelha_rainha.setFadaCaidaAlvo(pFadaCaida);
	}
	else
		std::cout << "ERRO::FASEPRIMEIRA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
}

Curandeira* FaseSegunda::getCurandeira() const
{
	return pCurandeira;
}

const bool FaseSegunda::getTerminou() const
{
	if (abelha_rainha.getVida() <= 0)
		return true;

	else
		return false;
}
