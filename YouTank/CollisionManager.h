#pragma once
#include "FadaCaida.h"
#include "GraphicManager.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Curandeira.h"

class CollisionManager
{
private:
	FadaCaida* pFadaCaida;
	Curandeira* pCurandeira;
	//Tela
	GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;

	float timer;
	float timerCurandeira;
	float timerMAX;

public:
	CollisionManager();
	~CollisionManager();
	
	/*Funções*/
	bool verificaColisaoFadaCaida(Entidade& entidade);
	void updateColisoesJanela();
	void updateColisoesJanelaJ1();
	void updateColisoesJanelaJ2();
	bool updateColisoesFadaCaida(Entidade* pEn);
	
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	void updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma);
	bool entidadeSaiuDaTela(Entidade* entidade);
	bool verificaContatoFadaCaida(Entidade* entidade);
	bool verificaContatoCurandeira(Entidade* entidade);
	//set
	void setFadaCaida(FadaCaida* jogador1);
	void setCurandeira(Curandeira* curandeira);
	void setGraphicManager(GraphicManager* pGM);

};

