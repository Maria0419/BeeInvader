#pragma once
#include "Fase.h"
#include "AbelhaRainha.h"

class FasePrimeira :
    public Fase
{
private:
    //Background
    Background background;

    //Boss
    AbelhaRainha abelha_rainha;

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
    void spawnAbelhas();
    void spawnCogumelo();
    void spawnPlataforma();
    
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void update();

    void renderFasePrimeira();
    
    void spawnFasePrimeiraEstatica(); 
};

