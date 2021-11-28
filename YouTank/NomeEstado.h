#pragma once
#include "Estado.h"
#include "Menu.h"

class NomeEstado :
    public Estado, public Menu
{

	void initText();
	void initBotoes();

public:
	NomeEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC);
	~NomeEstado();

	const short getEstado();
	const std::string getNome() const;

	void updateBotoes();
	void updateComando();
	void update();
	void retiraLetra(char letra);
	void incluaLetra(char letra);

	void render();
};

