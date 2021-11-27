#include "stdafx.h"
#include "Global.h"
#include "FaseSegunda.h"

FaseSegunda::FaseSegunda():
	Fase()
{
	Ente::pLista = &listaEntidades;
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);	
	abelha_rainha = new AbelhaRainha();
}

FaseSegunda::~FaseSegunda()
{
	delete abelha_rainha;
}

void FaseSegunda::criarPlataforma()
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

void FaseSegunda::criarObstaculos()
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
	if (collisionManager.verificaContatoJogador(static_cast<Entidade*>(abelha_rainha),static_cast<Jogador*>(pFadaCaida)))
		pFadaCaida->tomarDano(4);
	if (pCurandeira != NULL)
	{
		if (collisionManager.verificaContatoJogador(static_cast<Entidade*>(abelha_rainha), static_cast<Jogador*>(pCurandeira)))
			pFadaCaida->tomarDano(4);
	}
	if(abelha_rainha->getShowing())
		abelha_rainha->update();
	if (abelha_rainha->emFuria())
		criarAbelhas(2);
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_FERRAO:
		{
			if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				pFadaCaida->tomarDano(abelha_rainha->getDano());
				listaEntidades.operator[](i)->setShowing(false);
			}
			else if (pCurandeira)
			{
				if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
				{
					pCurandeira->tomarDano(abelha_rainha->getDano());
					listaEntidades.operator[](i)->setShowing(false);
				}
			}
		}
		break;
		case ID_ORBE:
		{
			if (collisionManager.updateCombate(listaEntidades.operator[](i), static_cast<Entidade*>(abelha_rainha)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				abelha_rainha->tomarDano(pFadaCaida->getDano());
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
	criarCogumelos();
	criarObstaculos();
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
		if(abelha_rainha->getShowing())
			abelha_rainha->renderAbelhaRainha();
	}
	pFadaCaida->renderBarraVida();
	pFadaCaida->render();

	if (pCurandeira != NULL)
	{
		pCurandeira->renderBarraVida();
		pCurandeira->render();
	}
		
}

void Fases::FaseSegunda::salvar()
{
	reiniciarArquivos();
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		listaEntidades[i]->salvar();
	}
	pFadaCaida->salvar();
	abelha_rainha->salvar();

	if (pCurandeira != NULL)
		pCurandeira->salvar();
}

void Fases::FaseSegunda::recuperar()
{
	recuperarAbelhas();
	recuperarCogumelos();
	pFadaCaida->recuperar();
	abelha_rainha->recuperar();

	if (pCurandeira != NULL)
		pCurandeira->recuperar();
}

void FaseSegunda::setFadaCaida(FadaCaida* pJ)
{
	if (pJ)
	{
		pFadaCaida = pJ;
		abelha_rainha->setFadaCaidaAlvo(pFadaCaida);
	}
	else
		std::cout << "ERRO::FASEPRIMEIRA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
	
}

const bool FaseSegunda::getTerminou() const
{
	if (abelha_rainha->getVida() <= 0)
	{
		pFadaCaida->operator+=(abelha_rainha->getPontos());
		return true;
	}
		

	else
		return false;
}
