#pragma once

#include "GraphicManager.h"
#include "Entidade.h"
#include "Jogador.h"
using namespace Jogadores;

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
	bool verificaColisaoJogador(Entidade& entidade, Jogador& jogador);
	void updateColisoesJanela(Jogador* pJogador);
	bool updateColisoesJogador(Entidade* pEn, Jogador* pJogador);
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	void updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma);
	bool entidadeSaiuDaTela(Entidade* entidade);

	bool verificaContatoJogador(Entidade* entidade, Jogador* pJogador);

	//set
	void setGraphicManager(GraphicManager* pGM);

};

