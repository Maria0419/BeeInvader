#pragma once
#include "State.h"
#include "FasePrimeira.h"

class GameState: public State
{
private:
    
    FasePrimeira* fasePrimeira;
    //Funções Inicializadoras
    short fase;

public:

    //Construtora e Destrutora
    GameState(std::stack<State*>* state, InputManager* pIM, int fase);
    ~GameState();

    const short getState();
    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render();
    
    
};

