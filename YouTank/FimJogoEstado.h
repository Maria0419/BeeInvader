#pragma once
#include "Estado.h"
#include "Menu.h"

class FimJogoEstado :
    public Estado, public Menu
{
private:
	void initText();
	void initBotoes();

public:
	FimJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC);
	~FimJogoEstado();

	const short getEstado();

	void updateBotoes();
	void updateComando();
	void update();

	void render();
};

