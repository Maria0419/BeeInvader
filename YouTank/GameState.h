#pragma once
#include "State.h"
#include "FasePrimeira.h"
#include "PauseState.h"

class GameState: public State
{
private:
    FadaCaida* jogador1;


    FasePrimeira* fasePrimeira;
    //Fun��es Inicializadoras
    short fase;
    bool multiplayer;

    //aux
    sf::Clock clock;
    float deltaTime;

    void runFase();
    void updateDeltaTime();
    
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

