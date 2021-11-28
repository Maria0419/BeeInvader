#pragma once
#include "Estado.h"
#include "Menu.h"

class JogoEstado;

class VitoriaJogoEstado :
    public Estado, public Menu
{
private:
	bool prox_fase;
	bool multiplayer;
	int pontuacao;
	std::multimap<int, std::string, std::greater<int>> ranking;

	void initText();
	void initBotoes();
public:
	VitoriaJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC, std::string nome, int pontos, bool prox_f = false, bool mp = false);
	~VitoriaJogoEstado();

	const short getEstado();

	void salvarPontuacao();
	void recuperarPontuacao();

	void updateBotoes();
	void updateComando();
	void update();

	void render();
};

