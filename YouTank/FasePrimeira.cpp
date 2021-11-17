#include "stdafx.h"
#include "FasePrimeira.h"

void FasePrimeira::initInimigo()
{
	spawnTimerMAX = 100.f;
	spawnTimer = spawnTimerMAX;
	inimigosMAX = 10;
	contaInimigos = 0;
}

FasePrimeira::FasePrimeira():
	Fase(),
	background("Imagens/backgroundCidade.jpg", 0.8f)
{
	initInimigo();
	collisionManager.setGraphicManager(pGraphic);
	collisionManager.setJogador(pJogador);
}

FasePrimeira::~FasePrimeira()
{
	
}

void FasePrimeira::spawnInimigos()
{
	//timer
	if (spawnTimer < spawnTimerMAX)
		spawnTimer += 5.f;

	else if (contaInimigos < inimigosMAX)
	{
		InimigoTerrestre* inim = new InimigoTerrestre();
		listaEntidades.incluaEntidade(static_cast<Entidade*>(inim));
		contaInimigos++;
		spawnTimer = 0.f;
	}
}

void FasePrimeira::spawnPlataforma()
{

	Plataforma* plat = new Plataforma();
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat));

	Plataforma* plat2 = new Plataforma(300.f, 20.f, 100.f, 500.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat2));

	Plataforma* plat3 = new Plataforma(300.f, 20.f, 300.f, 420.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat3));

	Plataforma* plat4 = new Plataforma(300.f, 20.f, 500.f, 340.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat4));

	Plataforma* plat5 = new Plataforma(300.f, 20.f, 300.f, 260.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat5));

	Plataforma* plat6 = new Plataforma(300.f, 20.f, 500.f, 180.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat6));

	Plataforma* plat7 = new Plataforma(300.f, 20.f, 300.f, 100.f, 0);
	listaEntidades.incluaEntidade(static_cast<Entidade*>(plat7));
}

void FasePrimeira::updateColisoes()
{
	int i;
	std::cout << "tamanho lista " << listaEntidades.getTamanho() << std::endl;
	unsigned counter = 0;
	for (i = 0; i < listaEntidades.getTamanho(); i++) 
	{
		switch (listaEntidades.operator[](counter)->getId())
		{
		case 44042://update colisoes com plataforma
		{
			collisionManager.updateColisoes(listaEntidades.operator[](counter));
		}
		break;
		case 11102://update colisoes do player com inimigos
		{
			if (collisionManager.updateColisoes(listaEntidades.operator[](counter)))
			{
				listaEntidades.destruaEntidade(listaEntidades.operator[](counter));
				counter--;
				contaInimigos--;
			}
		}
		break;
		case 312://ve se o projetil saiu da area da janela
		{
			float dir_x = listaEntidades.operator[](counter)->getDirecao_x();
			float dir_y = listaEntidades.operator[](counter)->getDirecao_y();
			float rapidez = listaEntidades.operator[](counter)->getRapidez();
			listaEntidades.operator[](counter)->getBody()->move(dir_x * rapidez, dir_y * rapidez);
			if (collisionManager.deletaProjetil(listaEntidades.operator[](counter)))
			{
				listaEntidades.destruaEntidade(listaEntidades.operator[](counter));
				counter--;
			}
		}
		break;
		}

		++counter;
	}
}

void FasePrimeira::updateCombate()
{
	int i, j;
	bool colidiu = false;
	unsigned counter = 0;
	for (i = 0; i < listaEntidades.getTamanho(); i++)
	{
		unsigned counter_2 = 0;
		if (listaEntidades.operator[](counter)->getId() == 312)
		{
			for (j = 0; j < listaEntidades.getTamanho(); j++)
			{
				if (listaEntidades.operator[](counter_2)->getId() == 11102)
				{
					if (collisionManager.updateCombate(listaEntidades.operator[](counter), listaEntidades.operator[](counter_2)))
					{
						listaEntidades.destruaEntidade(listaEntidades.operator[](counter));
						listaEntidades.destruaEntidade(listaEntidades.operator[](counter_2));
						contaInimigos--;
						colidiu = true;
					}
				}
				if (colidiu)
					break;
				counter_2++;
			}
		}
		if (colidiu)
			break;
		counter++;
	}
}

void FasePrimeira::update()
{
	spawnInimigos();
	updateColisoes();
	updateCombate();
}


void FasePrimeira::renderFasePrimeira()
{
	background.renderBackground();
	for (int i = 0; i < listaEntidades.getTamanho(); i++)
	{
		listaEntidades.operator[](i)->setShowing(true);
		listaEntidades.operator[](i)->render();
	}
}
