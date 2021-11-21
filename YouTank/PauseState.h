#pragma once
#include "State.h"
#include "Menu.h"

class PauseState :
    public State, public Menu
{
private:
    
    void initButtons();

public:
    PauseState(std::stack<State*>* state, InputManager* pIM);
    ~PauseState();

    const short getState();
    const bool getPause() const;

    void updateButtons();
    void updateInput();
    void update();

    void renderButtons();
    void render();
};

