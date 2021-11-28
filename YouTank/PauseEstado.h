#pragma once
#include "Estado.h"
#include "Menu.h"

class PauseEstado :
    public Estado, public Menu
{
private:
    
    void initBotoes();

public:
    PauseEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC);
    ~PauseEstado();

    const short getEstado();
    const bool getPause() const;

    void updateBotoes();
    void updateComando();
    void update();

    void render();
};

