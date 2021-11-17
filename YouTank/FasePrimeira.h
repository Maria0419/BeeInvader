#pragma once
#include "Fase.h"

class FasePrimeira :
    public Fase
{
private:
    //Background
    Background background;

    //Timer dos inimigos
    float spawnTimer;
    float spawnTimerMAX;
    unsigned int inimigosMAX;
    unsigned int contaInimigos;

    //privateFunctions
    void initInimigo();

public:
    FasePrimeira();
    ~FasePrimeira();

    //Funçoes
    void spawnInimigos();
    void spawnPlataforma();
    
    void updateInimigos();
    void updateColisoes();
    void updateCombate();
    void update();

    void renderFasePrimeira();
    
    void spawnFasePrimeiraEstatica(); 
};

