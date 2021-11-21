#pragma once
#include "State.h"
#include "FasePrimeira.h"
#include "PauseState.h"
#include "GameOverState.h"

class GameState: public State
{
private:
    FadaCaida* jogador1;


    FasePrimeira* fasePrimeira;
    //Funções Inicializadoras
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

    void verificarGameOver();

    void updatePause();
    void updateGameOver();
    void updateInput();
    void update();
    void render();
    
    
};

