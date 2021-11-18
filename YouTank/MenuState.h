#pragma once
#include "GameState.h"
#include "Background.h"
#include "Button.h"

class MenuState :
    public State
{
private:
    Background background;
    std::map<std::string, Button*> buttons;

    void initButtons();

public:
    MenuState(std::stack<State*>* state, InputManager* pIM);
    ~MenuState();

    const short getState();
    
    void endState();

    void updateButtons();
    void updateInput(const float& dt);
    void update(const float& dt);

    void renderButtons();
    void render();
};

