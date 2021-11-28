#pragma once

#include "GerenciadorGrafico.h"
#include "Entidade.h"
#include "Jogador.h"


class GerenciadorColisao
{
private:
	//Tela
	GerenciadorGrafico* pGrafico;
	sf::RenderWindow* pWindow;

public:
	GerenciadorColisao();
	~GerenciadorColisao();
	
	/*Funções*/
	bool verificaColisaoJogador(Entidade& entidade, Jogadores::Jogador& jogador);
	void updateColisoesJanela(Jogadores::Jogador* pJogador);
	bool updateColisoesJogador(Entidade* pEn, Jogadores::Jogador* pJogador);
	bool updateCombate(Entidade* pOrbe, Entidade* pInimigo);
	void updateInimigoPlataforma(Entidade& inimigo, Entidade* plataforma);
	bool entidadeSaiuDaTela(Entidade* entidade);

	bool verificaContatoJogador(Entidade* entidade, Jogadores::Jogador* pJogador);

	//set
	void setGerenciadorGrafico(GerenciadorGrafico* pGG);

};

