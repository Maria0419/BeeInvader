#include "stdafx.h"
#include "Global.h"
#include "Fase.h"
using namespace Fases;
using namespace Jogadores;
using namespace ElementosVisuais;
using namespace Inimigos;


void Fase::initInimigo()
{
	criarTimer = SPAWN_TIMER_MAX;
	criarTimerMAX = SPAWN_TIMER_MAX;
	contaAbelhas = 0;
	obstaculosMAX = rand() % 3 + 3;
	abelhasMAX = rand() % 10 + 5;
	contaCogu = 0;
	contaPedras = 0;
	contaObstaculos = 0;
}

Fase::Fase():
	pFadaCaida(NULL),
	pCurandeira(NULL),
	listaEntidades(),
	plano_fundo("Imagens/floresta.png")
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
		if (listaEntidades.operator[](i)->getId() == ID_ABELHA)
			listaEntidades.operator[](i)->persegue(pFadaCaida->getPosition().x, pFadaCaida->getPosition().y);
		else
			listaEntidades.operator[](i)->update();

	}
}

void Fase::updateColisoes()
{
	int i;
	gerenciadorColisao.updateColisoesJanela(static_cast<Jogador*>(pFadaCaida));
	if(pCurandeira)
		gerenciadorColisao.updateColisoesJanela(static_cast<Jogador*>(pCurandeira));
	for (i = 0; i < listaEntidades.getTamanho(); i++)
	{

		switch (listaEntidades.operator[](i)->getId())
		{
		case ID_PLATAFORMA://update colisoes com plataforma
		{
			gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if(pCurandeira)
				gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
		}
		break;
		case ID_FAVOMEL:
		{
			gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if (pCurandeira)
				gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
		}
		case ID_ABELHA://update colisoes do player com inimigos e janela
		{
			if (gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				pFadaCaida->tomarDano(listaEntidades.operator[](i)->getDano());
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
			}
			if (pCurandeira)
			{
				if (gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
				{
					pCurandeira->tomarDano(listaEntidades.operator[](i)->getDano());
					listaEntidades.operator[](i)->setShowing(false);
					contaAbelhas--;
				}
			}
			else if (gerenciadorColisao.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
				contaAbelhas--;
			}

		}
		break;
		case ID_ORBE:
		{	//update colisoes do orbe de dano com janela
			if (gerenciadorColisao.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_ORBECURA:
		{   //update colisoes do orbe de cura com janela
			if (gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				if (pCurandeira)
				{
					pFadaCaida->receberCura(pCurandeira->getCura());
					listaEntidades.operator[](i)->setShowing(false);
				}
			}
			else if (gerenciadorColisao.entidadeSaiuDaTela(listaEntidades.operator[](i)))
			{
				listaEntidades.operator[](i)->setShowing(false);
			}
		}
		break;
		case ID_COGUMELO:
		{
			if (gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
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
				if (gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
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
			if (gerenciadorColisao.verificaContatoJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida)))
			{
				int x = rand() % 21;
				if(x > 19)
					pFadaCaida->tomarDano(1);
			}
			if (pCurandeira)
			{
				if (gerenciadorColisao.verificaContatoJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira)))
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
			gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pFadaCaida));
			if (pCurandeira)
				gerenciadorColisao.updateColisoesJogador(listaEntidades.operator[](i), static_cast<Jogador*>(pCurandeira));
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
					if (gerenciadorColisao.updateCombate(listaEntidades.operator[](i), listaEntidades.operator[](j)))
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
					if (gerenciadorColisao.updateCombate(listaEntidades.operator[](i), listaEntidades.operator[](j)))
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
				if (listaEntidades.operator[](j)->getId() == ID_COGUMELO ||
					listaEntidades.operator[](j)->getId() == ID_PEDRA ||
					listaEntidades.operator[](j)->getId() == ID_ESPINHOS)
					gerenciadorColisao.updateInimigoPlataforma(*listaEntidades.operator[](j), listaEntidades.operator[](i));

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

void Fase::recuperarAbelhas()
{
	std::ifstream recuperar("./Carregamentos/Abelha.txt", std::ios::in);
	if (!recuperar)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}
	float  posX, posY;
	while (recuperar >> posX >> posY)
	{
		Abelha* pAux = new Abelha(posX, posY);
		listaEntidades.incluaEntidade(pAux);
		contaAbelhas++;
	}
	recuperar.close();
}

void Fase::recuperarCogumelos()
{
	std::ifstream recuperar("./Carregamentos/Cogumelo.txt", std::ios::in);
	if (!recuperar)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}
	float  velX, posX, posY;
	while (recuperar >> velX >> posX >> posY)
	{
		Cogumelo* pAux = new Cogumelo(velX, posX, posY);
		listaEntidades.incluaEntidade(pAux);
		contaCogu++;
	}
	recuperar.close();
}

void Fase::recuperarObstaculos()
{
	std::ifstream recuperarFerrao("./Carregamentos/Obstaculos.txt", std::ios::in);
	if (!recuperarFerrao)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}
	int id;
	float velY, tamX, tamY, posX, posY;
	Plataforma* pPlat = NULL;
	FavoMel* pFavo = NULL;
	Espinhos* pEsp = NULL;
	Pedra* pPedra = NULL;
	while (recuperarFerrao >> id >> velY >> tamX >> tamY >> posX >> posY)
	{
		switch (id)
		{
		case ID_PLATAFORMA:
			pPlat = new Plataforma(tamX, tamY, posX, posY);
			pPlat->setVelocidadeY(velY);
			listaEntidades.incluaEntidade(pPlat);
			break;

		case ID_FAVOMEL:
			pFavo = new FavoMel(posX, posY);
			pFavo->setVelocidadeY(velY);
			listaEntidades.incluaEntidade(pFavo);
			break;

		case ID_ESPINHOS:
			pEsp = new Espinhos(posX, posY);
			listaEntidades.incluaEntidade(pEsp);
			contaObstaculos++;
			break;

		case ID_PEDRA:
			pPedra = new Pedra(posX, posY);
			listaEntidades.incluaEntidade(pPedra);
			contaObstaculos++;
			break;

		default:
			break;
		}
	}
	recuperarFerrao.close();
}

void Fase::recuperarProjetil()
{
	/*ORBE*/
	std::ifstream recuperarOrbe("./Carregamentos/Orbe.txt", std::ios::in);
	if (!recuperarOrbe)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}
	float dirX, dirY, posX, posY, velX, velY;
	while (recuperarOrbe >> dirX >> dirY >> posX >> posY >> velX >> velY)
	{
		Orbe* pAux = new Orbe(dirX, dirY, posX, posY, velX, velY);
		listaEntidades.incluaEntidade(pAux);
	}
	recuperarOrbe.close();

	/*ORBE CURA*/
	std::ifstream recuperarOrbeCura("./Carregamentos/OrbeCura.txt", std::ios::in);
	if (!recuperarOrbeCura)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}

	while (recuperarOrbeCura >> dirX >> dirY >> posX >> posY)
	{
		OrbeCura* pAux = new OrbeCura(dirX, dirY, posX, posY);
		listaEntidades.incluaEntidade(pAux);
	}
	recuperarOrbeCura.close();

	/*FERRAO*/
	std::ifstream recuperarFerrao("./Carregamentos/Ferrao.txt", std::ios::in);
	if (!recuperarFerrao)
	{
		std::cout << "arquivo não pode ser aberto" << std::endl;
		fflush(stdin);
		return;
	}

	while (recuperarFerrao >> dirX >> dirY >> posX >> posY)
	{
		Ferrao* pAux = new Ferrao(posX, posY, 0, 0);
		pAux->setDirecao_x(dirX);
		pAux->setDirecao_y(dirY);
		listaEntidades.incluaEntidade(pAux);
	}
	recuperarFerrao.close();
}

void Fase::reiniciarArquivos()
{
	std::ofstream limpar;
	limpar.open("./Carregamentos/FadaCaida.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/Abelha.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/Cogumelo.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/Ferrao.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/Orbe.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/OrbeCura.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/Obstaculos.txt", std::ios::out);
	limpar.close();
	limpar.open("./Carregamentos/PoteMel.txt", std::ios::out);
	limpar.close();
}
