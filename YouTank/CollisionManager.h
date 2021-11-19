#pragma once
#include "Jogador.h"
#include "GraphicManager.h"
#include "Obstaculo.h"
#include "Inimigo.h"

class CollisionManager
{
private:
	Jogador* pJogador;
	sf::Vector2f direcao;
	//Tela
	GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;
	
	std::vector<Obstaculo*> obstaculos;

public:
	CollisionManager();
	~CollisionManager();
	
	/*Funções*/
	bool verificaColisaoJogador(Entidade& entidade, sf::Vector2f& direcao, float push);
	void updateColisoesJanela();
	bool updateColisoes(Entidade* pEn);
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	bool entidadeSaiuDaTela(Entidade* entidade);

	//set
	void setJogador(Jogador* jogador1);
	void setGraphicManager(GraphicManager* pGM);

};

