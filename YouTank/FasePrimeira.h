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
    
    unsigned int cogumelosMAX;
    unsigned int contaCogu;

    //privateFunctions
    void initInimigo();

public:
    FasePrimeira();
    ~FasePrimeira();

    //Fun�oes
    void spawnCogumelo();
    void spawnPlataforma();
    
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateBoss();
    void update();

    void renderFasePrimeira();
 
};

