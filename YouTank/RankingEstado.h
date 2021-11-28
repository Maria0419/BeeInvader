#pragma once
#include "Estado.h"
#include "FadaCaida.h"
#include "Menu.h"

class RankingEstado :
    public Estado, public Menu
{
private:

    void initText();
    void initButtons();

public:
    RankingEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM);
    ~RankingEstado();

    const short getEstado();

    void updateButtons();
    void updateInput();
    void update();

    void render();
};



