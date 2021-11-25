#pragma once
#include "GameState.h"
#include "Menu.h"
#include "NomeState.h"
#include "RankingState.h"

class MenuState :
    public State, public Menu
{
private:

    void initText();
    void initButtons();

public:
    MenuState(std::stack<State*>* state, InputManager* pIM);
    ~MenuState();

    const short getState();

    void updateButtons();
    void updateInput();
    void update();

    void render();
};

