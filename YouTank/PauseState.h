#pragma once
#include "State.h"
#include "Background.h"
#include "Button.h"

class PauseState :
    public State
{
private:
    Background background;
    std::map<std::string, Button*> buttons;
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

