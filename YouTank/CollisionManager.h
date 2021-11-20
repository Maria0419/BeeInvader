#pragma once
#include "Jogador.h"
#include "GraphicManager.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Curandeira.h"

class CollisionManager
{
private:
	Jogador* pJogador;
	Curandeira* pCurandeira;
	//Tela
	GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;

	float timer;
	float timerMAX;

public:
	CollisionManager();
	~CollisionManager();
	
	/*Funções*/
	bool verificaColisaoJogador(Entidade& entidade);
	void updateColisoesJanela();
	void updateColisoesJanelaJ1();
	void updateColisoesJanelaJ2();
	bool updateColisoes(Entidade* pEn);
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	void updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma);
	bool entidadeSaiuDaTela(Entidade* entidade);
	bool verificaContato(Entidade* entidade);

	//set
	void setJogador(Jogador* jogador1);
	void setCurandeira(Curandeira* curandeira);
	void setGraphicManager(GraphicManager* pGM);

};

