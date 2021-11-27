#pragma once

#include "GraphicManager.h"
#include "Entidade.h"
#include "Jogador.h"


class CollisionManager
{
private:
	//Tela
	GraphicManager* pGraphic;
	sf::RenderWindow* pWindow;

public:
	CollisionManager();
	~CollisionManager();
	
	/*Funções*/
	bool verificaColisaoJogador(Entidade& entidade, Jogadores::Jogador& jogador);
	void updateColisoesJanela(Jogadores::Jogador* pJogador);
	bool updateColisoesJogador(Entidade* pEn, Jogadores::Jogador* pJogador);
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	void updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma);
	bool entidadeSaiuDaTela(Entidade* entidade);

	bool verificaContatoJogador(Entidade* entidade, Jogadores::Jogador* pJogador);

	//set
	void setGraphicManager(GraphicManager* pGM);

};

