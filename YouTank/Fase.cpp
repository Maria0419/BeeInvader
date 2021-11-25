#include "stdafx.h"
#include "Fase.h"
#include "Global.h"

void Fase::initInimigo()
{
	criarTimer = SPAWN_TIMER_MAX;
	criarTimerMAX = SPAWN_TIMER_MAX;
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
	pCurandeira = NULL;

	listaEntidades.limpaLista();
}

void Fase::limpeza()
{
	unsigned counter = 0;
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		if (listaEntidades.operator[](counter)->getShowing() == false)
		{
			listaEntidades.destruaEntidade(listaEntidades.operator[](counter));
			counter--;
		}
		counter++;
	}
}

void Fase::criarCogumelos()
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

void Fase::criarAbelhas(int i)
{
	/*=========================ABELHAS==========================*/
	/*															*/
	/*	CRIA ABELHAS										    */
	/*	Abelhas perseguem o jogador, dão dano ou pontos			*/
	/*==========================================================*/

	//timer
	if (criarTimer < criarTimerMAX)
		criarTimer += 5;

	else if (contaAbelhas < abelhasMAX)
	{
		Abelha* inim = new Abelha(i);
		listaEntidades.incluaEntidade(static_cast<Entidade*>(inim));
		contaAbelhas++;
		criarTimer = 0;
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
			listaEntidades.operator[](i)->updateCogumelo();

		}
		break;
		}
	}
}

void Fase::updateColisoes()
{
	int i;
	collisionManager.updateColisoesJanela(static_cast<Jogador*>(pFadaCaida));
	if(pCurandeira)
		collisionManager.updateColisoesJanela(static_cast<Jogador*>(pCurandeira));
	for (i = 0; i < listaEntidades.getTamanho(); i++)
	{

		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA://update colisoes com plataforma
		{
			collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if(pCurandeira)
				collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
		}
		break;
		case ID_FAVOMEL:
		{
			collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if (pCurandeira)
				collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
		}
		case ID_ABELHA://update colisoes do player com inimigos e janela
		{
			if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				pFadaCaida->tomarDano(listaEntidades.operator[](i)->getDano());
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
			}
			if (pCurandeira)
			{
				if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
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
			if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
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
			if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				if (!pFadaCaida->getColisaoBot())
					pFadaCaida->tomarDano(5);
				else
					pFadaCaida->operator+=(listaEntidades.operator[](i)->getPontos());
				listaEntidades.operator[](i)->setShowing(false);
				contaCogu--;
			}
			if (pCurandeira)
			{
				if (collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
				{
					if (!pCurandeira->getColisaoBot())
						pCurandeira->tomarDano(5);
					else
						pFadaCaida->operator+=(listaEntidades.operator[](i)->getPontos());
					listaEntidades.operator[](i)->setShowing(false);
					contaCogu--;
				}
			}
		}
		break;
		case ID_ESPINHOS:
		{
			if (collisionManager.verificaContatoJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				int x = rand() % 21;
				if(x > 19)
					pFadaCaida->tomarDano(1);
			}
			if (pCurandeira)
			{
				if (collisionManager.verificaContatoJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
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
			collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if (pCurandeira)
				collisionManager.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
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
						pFadaCaida->operator+=(listaEntidades.operator[](j)->getPontos());
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
						pFadaCaida->operator+=(listaEntidades.operator[](j)->getPontos());
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
		if (listaEntidades.operator[](i)->getId() == ID_PLATAFORMA || listaEntidades.operator[](i)->getId() == ID_FAVOMEL)
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
void Fase::setFadaCaida(FadaCaida* pJ)
{
	if (pJ)
	{
		pFadaCaida = pJ;
	}
	else
		std::cout << "ERRO::FASEPRIMEIRA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
}
void Fase::setCurandeira(Curandeira* pC)
{
	if (pC)
	{
		pCurandeira = pC;
	}
	else
		std::cout << "ERRO::FASEPRIMEIRA::SETJOGADOR::Ponteiro FadaCaida NULL" << std::endl;
	
}
