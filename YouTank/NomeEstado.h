#pragma once
#include "Estado.h"
#include "Menu.h"

class NomeEstado :
    public Estado, public Menu
{

	void initText();
	void initButtons();

public:
	NomeEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM);
	~NomeEstado();

	const short getEstado();
	const std::string getNome() const;

	void updateButtons();
	void updateInput();
	void update();
	void retiraLetra(char letra);
	void incluaLetra(char letra);

	void render();
};

