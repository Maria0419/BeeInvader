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

void FaseSegunda::updateBoss()
{
	if (collisionManager.verificaContatoFadaCaida(static_cast<Entidade*>(&abelha_rainha)))
		pFadaCaida->tomarDano(4);
	if (pCurandeira != NULL)
	{
		if (collisionManager.verificaContatoCurandeira(static_cast<Entidade*>(&abelha_rainha)))
			pFadaCaida->tomarDano(4);
	}
	if(abelha_rainha.getShowing())
		abelha_rainha.update();
	if (abelha_rainha.emFuria())
		spawnAbelhas();
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_FERRAO:
		{
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(abelha_rainha.getDano());
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_ORBE:
		{
			if (collisionManager.updateCombate(listaEntidades.operator[](i), static_cast<Entidade*>(&abelha_rainha)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				abelha_rainha.tomarDano(pFadaCaida->getDano());
			}
		}
		break;
		}
	}
}

void FaseSegunda::update()
{
	updateInimigoPlataforma();
	updateColisoes();
	limpeza();
	spawnCogumelo();
	spawnObstaculos();
	updateMovimento();
	updateCombate();
	
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
		std::cout << "ERRO::FASESEGUNDA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
}

const bool FaseSegunda::getTerminou() const
{
	if (abelha_rainha.getVida() <= 0)
		return true;

	else
		return false;
}
