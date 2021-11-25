#pragma once
#include "State.h"
#include "FadaCaida.h"
#include "Menu.h"

class RankingState :
    public State, public Menu
{
private:
    FadaCaida* pFada;
    void initText();
    void initButtons();

public:
    RankingState(std::stack<State*>* state, InputManager* pIM);
    ~RankingState();

    const short getState();

    void updateButtons();
    void updateInput();
    void update();

    void render();
};



