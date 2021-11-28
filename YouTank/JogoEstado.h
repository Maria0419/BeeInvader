#pragma once
#include "Estado.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "PauseEstado.h"
#include "FimJogoEstado.h"
#include "VitoriaJogoEstado.h"


class JogoEstado: public Estado
{
private:
    Jogadores::FadaCaida* jogador1;
    Jogadores::Curandeira* jogador2;

    Fases::FasePrimeira* fasePrimeira;
    Fases::FaseSegunda* faseSegunda;

    short fase;
    bool multiplayer;
    bool recuperacao;
    
    //aux
    sf::Clock clock;
    float deltaTime;

    //Funções Inicializadoras
    void executarFase();
    void updateDeltaTime();
    
public:

    //Construtora e Destrutora
    JogoEstado(std::stack<Estado*>* estado, GerenciadorComando* pGC, short f, bool mp = false, bool rec = false);
    ~JogoEstado();

    void setPause(bool p);
    void setNome(std::string nome);
    void setPontos(int pontos);
    const short getEstado();
    const bool getPause() const;

    void criarCurandeira();

    void verificarFimJogo();
    void verificarVitoriaJogo();

    void updatePause();
    void updateFimJogo();
    void updateVitoriaJogo();
    void updateComando();
    void update();
    
    void render(); 

    void salvar();
    void recuperar();
};

