#pragma once
#include "Fase.h"
class FasePrimeira :
    public Fase
{
private:
    //Background
    Background background;

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
    unsigned int contaPoteMel;

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
    void spawnAbelhas();
    void spawnPoteMel();

    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void update();

    void renderFasePrimeira();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
    const bool getTerminou() const;
};

