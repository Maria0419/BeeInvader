#pragma once
#include "Estado.h"
#include "Menu.h"

class PauseEstado :
    public Estado, public Menu
{
private:
    
    void initButtons();

public:
    PauseEstado(std::stack<Estado*>* estado, GerenciadorComando* pIM);
    ~PauseEstado();

    const short getEstado();
    const bool getPause() const;

    void updateButtons();
    void updateInput();
    void update();

    void render();
};

