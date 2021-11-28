#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorComando.h"


enum qual_estado {ESTADO = 0, MENU_ESTADO, JOGO_ESTADO, PAUSE_ESTADO, JOGOFIM_ESTADO, VITORIA_ESTADO, NOME_ESTADO, RANKING_ESTADO};

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
	Estado(std::stack<Estado*>* estado, GerenciadorComando* pGC, short id );
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

	virtual void updateComando() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};


