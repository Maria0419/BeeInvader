#pragma once
#include "Fase.h"
class FaseSegunda :
    public Fase
{
private:
    //Background
    Background background;

    //Timer dos inimigos

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
    void spawnPlataforma();
    void spawnObstaculos();
    void spawnCurandeira();

    void updateMovimento();
    void updateColisoes();
    void updateCombate();
    void updateInimigoPlataforma();
    void update();

    void renderFasePrimeira();

    void setFadaCaida(FadaCaida* pFadaCaida);
    Curandeira* getCurandeira() const;
};

