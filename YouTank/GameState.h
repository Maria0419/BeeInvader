#pragma once
#include "State.h"
#include "FasePrimeira.h"
#include "PauseState.h"

class GameState: public State
{
private:
    
    FasePrimeira* fasePrimeira;
    //Funções Inicializadoras
    short fase;
    bool multiplayer;

    void runFase();
public:

    //Construtora e Destrutora
    GameState(std::stack<State*>* state, InputManager* pIM, short fase, bool multip = false);
    ~GameState();

    void setPause(bool p);
    const short getState();
    const bool getPause() const;
    void endState();

    void updatePause();
    void updateInput();
    void update();
    void render();
    
    
};

