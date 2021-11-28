#pragma once
#include "Estado.h"
#include "Menu.h"

class FimJogoEstado :
    public Estado, public Menu
{
private:
	void initText();
	void initButtons();

public:
	FimJogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM);
	~FimJogoEstado();

	const short getEstado();

	void updateButtons();
	void updateInput();
	void update();

	void render();
};

