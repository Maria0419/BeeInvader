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
    unsigned int obstaculosMAX;
    unsigned int contaObstaculos;
    unsigned int contaPedras;

    //privateFunctions
    void initInimigo();

public:
    FasePrimeira();
    ~FasePrimeira();

    //Funçoes
    void spawnCogumelo();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();
    
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void updateBoss();
    void update();

    void renderFasePrimeira();

    Curandeira* getCurandeira() const;
};

