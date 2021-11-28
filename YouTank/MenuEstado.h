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
    void initBotoes();

public:
    MenuEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC);
    ~MenuEstado();

    const short getEstado();

    void updateBotoes();
    void updateComando();
    void update();

    void render();
};

