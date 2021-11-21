#pragma once
#include "GameState.h"
#include "Menu.h"

class MenuState :
    public State, public Menu
{
private:

    void initButtons();

public:
    MenuState(std::stack<State*>* state, InputManager* pIM);
    ~MenuState();

    const short getState();
    
    void endState();

    void updateButtons();
    void updateInput();
    void update();

    void renderButtons();
    void render();
};

