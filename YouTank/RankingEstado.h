#pragma once
#include "Estado.h"
#include "FadaCaida.h"
#include "Menu.h"

class RankingEstado :
    public Estado, public Menu
{
private:

    void initText();
    void initBotoes();

public:
    RankingEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC);
    ~RankingEstado();

    const short getEstado();

    void updateBotoes();
    void updateComando();
    void update();

    void render();
};



