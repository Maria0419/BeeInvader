#pragma once
#include "GraphicManager.h"
#include "GerenciadorComando.h"


enum qual_estado {STATE = 0, MENU_STATE, GAME_STATE, PAUSE_STATE, GOVER_STATE, GWIN_STATE, NOME_STATE, RANKING_STATE};

class Estado
{
protected:
	
	GerenciadorComando* pComando;
	std::stack<Estado*>* estados;

	std::string nomeJ; 

	short estadoID;

	bool terminarEstado; 
	bool sair;
	bool pause;
	bool fimJogo;
	bool vitoriaJogo;
	bool irMenu;
	bool salvarPontos;
	bool salvarFase;


public:
	Estado(std::stack<Estado*>* estado, GerenciadorComando* pIM, short id );
	virtual ~Estado();

	virtual void setPause(bool p);
	virtual void setNome(std::string nome);
	virtual void setPontos(int i);

	const bool getSair() const;
	virtual const short getEstado() = 0;
	virtual const bool getPause() const;
	virtual const bool getFimJogo() const;
	virtual const bool getVitoriaJogo() const;
	virtual const bool getIrMenu() const;
	virtual const bool getTerminarEstado() const;
	virtual const bool getSalvarFase() const;
	virtual const std::string getNome() const;


	virtual void verificarPause();
	virtual void verificarIrMenu();
	virtual void salvar();
	virtual void recuperar();

	virtual void updateInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};


