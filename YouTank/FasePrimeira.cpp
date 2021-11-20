#include "stdafx.h"
#include "FasePrimeira.h"
#include "Global.h"

void FasePrimeira::initInimigo()
{
	abelha_rainha.setJogadorAlvo(&(*pJogador));
	contaCogu = 0;
	cogumelosMAX = rand() % 4;
	obstaculosMAX = rand() % 3 + 3;
	contaPedras = 0;
	contaObstaculos = 0;
}

FasePrimeira::FasePrimeira():
	Fase(),
	background("Imagens/floresta.png", 2.f)
{
	Ente::pLista = &listaEntidades;
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);
	collisionManager.setJogador(pJogador);
	
}

FasePrimeira::~FasePrimeira()
{
	delete pCurandeira;
}

void FasePrimeira::spawnCurandeira()
{
	pCurandeira = new Curandeira();
	collisionManager.setCurandeira(pCurandeira);
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

void FasePrimeira::spawnObstaculos()
{
	if (contaObstaculos < obstaculosMAX)
	{
		Espinhos* espinhos = new Espinhos((float)(rand() % 1180+100), 620.f);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(espinhos));
		if (contaPedras < obstaculosMAX)
		{
			Pedra* pedra = new Pedra((float)(rand() % 190 + 160), 480.f);
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
				abelha_rainha.morreuAbelha();
			}
			else if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				abelha_rainha.morreuAbelha();
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
			if (collisionManager.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		case ID_FERRAO:
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				pJogador->tomarDano(abelha_rainha.getDano());
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_COGUMELO:
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](i)))
			{
				if(!pJogador->getColisaoBot())
					pJogador->tomarDano(5);
				listaEntidades.operator[](i)->setShowing(false);
				contaCogu--;
			}
		}
		break;
		case ID_ESPINHOS:
		{
			if (collisionManager.verificaContato(listaEntidades.operator[](i)))
			{
				pJogador->tomarDano(1);
			}
		}
		break;
		case ID_PEDRA:
		{
			collisionManager.updateColisoes(listaEntidades.operator[](i));
		}
		break;
		default:
		break;
		}
		if(collisionManager.verificaContato(static_cast<Entidade*>(&abelha_rainha)))
			pJogador->tomarDano(4);
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
						abelha_rainha.morreuAbelha();
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
}

void FasePrimeira::updateInimigoPlataforma()
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

void FasePrimeira::updateBoss()
{
	abelha_rainha.update();
}

void FasePrimeira::update()
{
	
	updateColisoes();
	limpeza();
	spawnCogumelo();
	spawnObstaculos();
	updateMovimento();
	updateCombate();
	updateInimigoPlataforma();
	pJogador->update();
	pCurandeira->update();
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
	pCurandeira->render();
}

Curandeira* FasePrimeira::getCurandeira() const
{
	return pCurandeira;
}
