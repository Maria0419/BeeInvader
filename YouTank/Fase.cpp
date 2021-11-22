#include "stdafx.h"
#include "Fase.h"
#include "Global.h"

void Fase::initInimigo()
{
	spawnTimer = SPAWN_TIMER_MAX;
	spawnTimerMAX = SPAWN_TIMER_MAX;
	contaAbelhas = 0;
	abelhasMAX = rand() % 10 + 5;
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
