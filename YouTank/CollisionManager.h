#pragma once
#include "Jogador.h"
#include "GraphicManager.h"

class CollisionManager
{
private:
	Jogador* pJogador;
	sf::Vector2f direcao;
	//Tela
	GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;

public:
	CollisionManager();
	~CollisionManager();
	
	/*Funções*/
	bool verificaColisao(Entidade& entidade, sf::Vector2f& direcao, float push);
	void colidindoComInimigo(Entidade entidade);
	void colidindoComPlataforma();
	void updateColisoesJanela();
	bool updateColisoes(Entidade* pEn);
	bool updateCombate(Entidade* pProjetil, Entidade* pInimigo);
	bool deletaProjetil(Entidade* projetil);

	//set
	void setJogador(Jogador* jogador1);
	void setGraphicManager(GraphicManager* pGM);
	void incluaEntidade(Entidade* pEn);

	void updateCombate();

};

