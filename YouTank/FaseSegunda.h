#pragma once
#include "Fase.h"
#include "AbelhaRainha.h"

class FaseSegunda :
    public Fase
{
private:
    //Background
    Background background;

    //Boss
    AbelhaRainha abelha_rainha;

    //Timer dos inimigos
    unsigned int spawnTimer;
    unsigned int spawnTimerMAX;
    unsigned int abelhasMAX;
    unsigned int contaAbelhas;
    unsigned int cogumelosMAX;
    unsigned int contaCogu;
    unsigned int obstaculosMAX;
    unsigned int contaObstaculos;
    unsigned int contaPedras;

    //privateFunctions
    void initInimigo();

public:
    FaseSegunda();
    ~FaseSegunda();

    //Funçoes
    void spawnCogumelo();
    void spawnAbelhas();
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();
    
    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void updateBoss();
    void update();

    void renderFaseSegunda();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
    const bool getTerminou() const;
};

