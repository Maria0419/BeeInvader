#pragma once
#include "GraphicManager.h"
#include "InputManager.h"


enum qual_state {STATE = 0, MENU_STATE, GAME_STATE, PAUSE_STATE, GOVER_STATE, GWIN_STATE, NOME_STATE, RANKING_STATE};

class State
{
protected:
	
	InputManager* pInput;
	std::stack<State*>* states;

	std::string nomeJ; 

	short stateID;

	bool terminarState; //continuar
	bool sair;
	bool pause;
	bool gameOver;
	bool gameWin;
	bool goToMenu;
	bool salvarPontos;
	bool salvarFase;


public:
	State(std::stack<State*>* state, InputManager* pIM, short id );
	virtual ~State();

	virtual void setPause(bool p);
	virtual void setNome(std::string nome);
	virtual void setPontos(int i);

	const bool getSair() const;
	virtual const short getState() = 0;
	virtual const bool getPause() const;
	virtual const bool getGameOver() const;
	virtual const bool getGameWin() const;
	virtual const bool getGoToMenu() const;
	virtual const bool getTerminarState() const;
	virtual const bool getSalvarFase() const;
	virtual const std::string getNome() const;


	virtual void verificarPause();
	virtual void verificarGoToMenu();
	virtual void salvar();
	virtual void recuperar();

	virtual void updateInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};


