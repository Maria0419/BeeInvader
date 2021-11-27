#pragma once
#include "State.h"
#include "Menu.h"

class GameState;

class GameWinState :
    public State, public Menu
{
private:
	bool prox_fase;
	bool multiplayer;
	int pontuacao;
	std::multimap<int, std::string, std::greater<int>> ranking;

	void initText();
	void initButtons();
public:
	GameWinState(std::stack<State*>* state, InputManager* pIM, std::string nome, int pontos, bool prox_f = false, bool mp = false);
	~GameWinState();

	const short getState();

	void salvarPontuacao();
	void recuperarPontuacao();

	void updateButtons();
	void updateInput();
	void update();

	void render();
};

