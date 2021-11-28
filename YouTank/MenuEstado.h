#pragma once
#include "JogoEstado.h"
#include "Menu.h"
#include "NomeEstado.h"
#include "RankingEstado.h"

class MenuEstado :
    public Estado, public Menu
{
private:

    void initText();
    void initButtons();

public:
    MenuEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM);
    ~MenuEstado();

    const short getEstado();

    void updateButtons();
    void updateInput();
    void update();

    void render();
};

