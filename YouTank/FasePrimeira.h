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
    float ferraoTimer;
    float ferraoTimerMAX;
    unsigned int abelhasMAX;
    unsigned int contaAbelhas;
    unsigned int cogumelosMAX;
    unsigned int contaCogu;

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
    void updateBoss();
    void update();

    void renderFasePrimeira();
 
};

