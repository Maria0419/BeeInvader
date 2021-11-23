#include "stdafx.h"
#include "Fase.h"
#include "Global.h"

void Fase::initInimigo()
{
	spawnTimer = SPAWN_TIMER_MAX;
	spawnTimerMAX = SPAWN_TIMER_MAX;
	contaAbelhas = 0;
	abelhasMAX = rand()%10 + 5;
	contaCogu = 0;
	obstaculosMAX = rand() % 3 + 3;
	contaPedras = 0;
	contaObstaculos = 0;
}

Fase::Fase():
	pFadaCaida(NULL),
	pCurandeira(NULL),
	listaEntidades(),
	background("Imagens/floresta.png")
{
	initInimigo();
}

Fase::~Fase()
{
	listaEntidades.limpaLista();
}

void Fase::limpeza()
{
	unsigned counter = 0;
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](counter)->getShowing() == false)
		{
			Entidade* pAux = listaEntidades.operator[](counter);
			listaEntidades.destruaEntidade(pAux);
			delete pAux;
			counter--;
		}
		counter++;
	}
}

void Fase::update()
{
}

void Fase::updateMovimento()
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

void Fase::updateColisoes()
{
	int i;
	collisionManager.updateColisoesJanela();
	for (i = 0; i < listaEntidades.getTamanho(); i++)
	{

		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA://update colisoes com plataforma
		{
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
			if(pCurandeira)
				collisionManager.updateColisoesCurandeira(listaEntidades.operator[](i));
		}
		break;
		case ID_FAVOMEL:
		{
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
			if (pCurandeira)
				collisionManager.updateColisoesCurandeira(listaEntidades.operator[](i));
		}
		case ID_ABELHA://update colisoes do player com inimigos e janela
		{
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				pFadaCaida->tomarDano(listaEntidades.operator[](i)->getDano());
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
			}
			if (pCurandeira)
			{
				if (collisionManager.updateColisoesCurandeira(listaEntidades.operator[](i)))
				{
					pCurandeira->tomarDano(listaEntidades.operator[](i)->getDano());
					listaEntidades.operator[](i)->setShowing(false);
					contaAbelhas--;
				}
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
		break;
		case ID_COGUMELO:
		{
			if (collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i)))
			{
				if (!pFadaCaida->getColisaoBot())
					pFadaCaida->tomarDano(5);
				listaEntidades.operator[](i)->setShowing(false);
				contaCogu--;
			}
			if (pCurandeira)
			{
				if (collisionManager.updateColisoesCurandeira(listaEntidades.operator[](i)))
				{
					//TODO COLISAO NA CABEÇA DO COGU
					listaEntidades.operator[](i)->setShowing(false);
					contaCogu--;
				}
			}
		}
		break;
		case ID_ESPINHOS:
		{
			if (collisionManager.verificaContatoFadaCaida(listaEntidades.operator[](i)))
			{
				int x = rand() % 21;
				if(x > 19)
					pFadaCaida->tomarDano(1);
			}
			if (pCurandeira)
			{
				if (collisionManager.verificaContatoCurandeira(listaEntidades.operator[](i)))
				{
					int x = rand() % 21;
					if (x > 19)
						pCurandeira->tomarDano(1);
				}
			}
		}
		break;
		case ID_PEDRA:
		{
			collisionManager.updateColisoesFadaCaida(listaEntidades.operator[](i));
			if(pCurandeira)
				collisionManager.updateColisoesCurandeira(listaEntidades.operator[](i));
		}
		break;

		}
		
	}
}

void Fase::updateCombate()
{
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

void Fase::updateInimigoPlataforma()
{
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](i)->getId() == ID_PLATAFORMA)
		{
			for (int j = 0; j < listaEntidades.getTamanho(); j++)
			{
				if (listaEntidades.operator[](j)->getId() == ID_COGUMELO)
					collisionManager.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));
				if(listaEntidades.operator[](j)->getId() == ID_PEDRA)
					collisionManager.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));
				if (listaEntidades.operator[](j)->getId() == ID_ESPINHOS)
					collisionManager.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));
			}
				
		}
	}
}