#pragma once
#include "State.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "GameWinState.h"
using namespace Jogadores;

class GameState: public State
{
private:
    FadaCaida* jogador1;
    Curandeira* jogador2;

    FasePrimeira* fasePrimeira;
    FaseSegunda* faseSegunda;

    short fase;
    bool multiplayer;
    bool recuperacao;
    
    //aux
    sf::Clock clock;
    float deltaTime;

    //Funções Inicializadoras
    void runFase();
    void updateDeltaTime();
    
public:

    //Construtora e Destrutora
    GameState(std::stack<State*>* state, InputManager* pIM, short f, bool mp = false, bool rec = false);
    ~GameState();

    void setPause(bool p);
    void setNome(std::string nome);
    void setPontos(int pontos);
    const short getState();
    const bool getPause() const;

    void criarCurandeira();

    void verificarGameOver();
    void verificarGameWin();

    void updatePause();
    void updateGameOver();
    void updateGameWin();
    void updateInput();
    void update();
    
    void render(); 

    void salvar();
    void recuperar();
};

